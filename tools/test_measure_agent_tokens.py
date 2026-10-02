"""Synthetic tests for the read-only per-response token analyzer."""

import hashlib
import json
from collections import Counter
from pathlib import Path
import sqlite3
import tempfile
import unittest

from measure_agent_tokens import (aggregate, analyze, parse_utc, select_threads,
                                  scan_rollout)


START = parse_utc("2026-10-02T12:00:00Z")
END = parse_utc("2026-10-02T12:01:00Z")


def usage(input_tokens=10, cached=0, cache_write=0, output=4, reasoning=1, total=None):
    return {"input_tokens": input_tokens, "cached_input_tokens": cached,
            "cache_write_input_tokens": cache_write, "output_tokens": output,
            "reasoning_output_tokens": reasoning,
            "total_tokens": input_tokens + output if total is None else total}


def token_event(response_id="resp_a", timestamp="2026-10-02T12:00:10Z",
                token_usage=None, thread_id="thread-a"):
    return {"timestamp": timestamp, "type": "token_usage_record",
            "payload": {"response_id": response_id, "thread_id": thread_id,
                        "usage": token_usage if token_usage is not None else usage()}}


def session_meta(thread_id="thread-a"):
    return {"type": "session_meta", "payload": {"id": thread_id}}


def write_jsonl(path, records):
    path.write_text("".join(json.dumps(record) + "\n" for record in records),
                    encoding="utf-8")


def sha256(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


class TimestampTests(unittest.TestCase):
    def test_timestamps_require_explicit_zone(self):
        self.assertEqual(parse_utc("2026-10-02T22:00:00+10:00"), START)
        with self.assertRaisesRegex(ValueError, "include Z or a UTC offset"):
            parse_utc("2026-10-02T12:00:00")
        with self.assertRaisesRegex(ValueError, "valid ISO-8601"):
            parse_utc("tomorrow")

    def test_start_must_precede_end(self):
        with self.assertRaisesRegex(ValueError, "earlier"):
            aggregate([], END, START)


class RolloutAggregationTests(unittest.TestCase):
    def test_duplicate_response_ids_count_once_and_reasoning_is_not_added(self):
        with tempfile.TemporaryDirectory() as temporary:
            path = Path(temporary) / "rollout.jsonl"
            records = [
                {"timestamp": START.isoformat(), "type": "event_msg",
                 "payload": {"message": "DO NOT EMIT THIS SECRET"}},
                session_meta(),
                token_event("resp_a", token_usage=usage(12, 4, 0, 7, 3)),
                token_event("resp_a", token_usage=usage(12, 4, 0, 7, 3)),
                token_event("resp_b", token_usage=usage(20, 5, 2, 4, 1)),
                token_event("resp_at_end", "2026-10-02T12:01:00Z"),
            ]
            write_jsonl(path, records)
            result = aggregate([{"rollout_path": path, "model": "gpt-6-luna"}], START, END)
            totals = result["totals"]
            self.assertEqual(result["response_count"], 2)
            self.assertEqual(totals["input_tokens"], 32)
            self.assertEqual(totals["fresh_input_tokens"], 23)
            self.assertEqual(totals["cached_input_tokens"], 9)
            self.assertEqual(totals["cache_write_input_tokens"], 2)
            self.assertEqual(totals["output_tokens"], 11)
            self.assertEqual(totals["reasoning_output_tokens"], 4)
            self.assertEqual(totals["total_tokens"], 43)
            self.assertEqual(totals["max_input_tokens"], 20)
            self.assertEqual(result["diagnostics"]["duplicate_records_deduplicated"], 1)
            self.assertEqual(result["diagnostics"]["records_outside_window"], 1)
            self.assertNotIn("DO NOT EMIT THIS SECRET", json.dumps(result))
            self.assertNotIn("price", result)
            self.assertEqual(result["models"]["gpt-6-luna"]["response_count"], 2)

    def test_conflicting_duplicate_response_is_excluded_and_reported(self):
        with tempfile.TemporaryDirectory() as temporary:
            path = Path(temporary) / "conflict.jsonl"
            write_jsonl(path, [session_meta(), token_event("resp_x", token_usage=usage(10)),
                               token_event("resp_x", token_usage=usage(11))])
            result = aggregate([{"rollout_path": path, "model": "model-a"}], START, END)
            self.assertEqual(result["response_count"], 0)
            self.assertEqual(result["diagnostics"]["conflicting_response_ids"], 1)
            self.assertEqual(result["diagnostics"]["duplicate_records_deduplicated"], 1)

    def test_missing_malformed_and_invalid_records_are_counted_without_content(self):
        with tempfile.TemporaryDirectory() as temporary:
            path = Path(temporary) / "errors.jsonl"
            valid_marker = '{"type":"token_usage_record",'
            path.write_text("\n".join([
                json.dumps(session_meta()),
                valid_marker + "bad json",
                json.dumps({"timestamp": "2026-10-02T12:00:00Z",
                            "type": "token_usage_record", "payload": {"thread_id": "thread-a",
                                                                           "usage": usage()}}),
                json.dumps(token_event("resp_no_usage", token_usage=None) | {
                    "payload": {"response_id": "resp_no_usage", "thread_id": "thread-a",
                                "usage": {}}}),
                json.dumps(token_event("resp_bad_time", "no timezone")),
            ]), encoding="utf-8")
            _, diagnostics = scan_rollout(path, "m", START, END)
            kinds = {error["kind"] for error in diagnostics["errors"]}
            self.assertTrue({"invalid_token_record_json", "missing_response_id",
                             "invalid_usage", "invalid_record_timestamp"}.issubset(kinds))

    def test_thread_identity_must_match_and_response_ids_cannot_be_missing(self):
        with tempfile.TemporaryDirectory() as temporary:
            path = Path(temporary) / "identity.jsonl"
            records = [token_event("resp_wrong", thread_id="other-thread"),
                       token_event("resp_missing_id")]
            records[1]["payload"].pop("thread_id")
            records.append({"type": "token_usage_record", "timestamp": START.isoformat(),
                            "payload": {"thread_id": "thread-a", "usage": usage()}})
            write_jsonl(path, records)
            candidates, diagnostics = scan_rollout(path, "m", START, END,
                                                   expected_thread_id="thread-a")
            kinds = Counter(error["kind"] for error in diagnostics["errors"])
            self.assertEqual(candidates, [])
            self.assertEqual(kinds["thread_id_mismatch"], 1)
            self.assertEqual(kinds["missing_thread_id"], 1)
            self.assertEqual(kinds["missing_response_id"], 1)

    def test_direct_rollout_binds_token_records_to_session_meta_id(self):
        with tempfile.TemporaryDirectory() as temporary:
            path = Path(temporary) / "single.jsonl"
            write_jsonl(path, [session_meta("direct-thread"),
                               token_event("resp_ok", thread_id="direct-thread"),
                               token_event("resp_wrong", thread_id="other-thread")])
            result = analyze(None, START, END, rollouts=[path], model="gpt-6-luna")
            self.assertEqual(result["response_count"], 1)
            self.assertEqual(result["diagnostics"]["errors_by_kind"]["thread_id_mismatch"], 1)

    def test_missing_file_and_file_without_usage_records_are_reported(self):
        with tempfile.TemporaryDirectory() as temporary:
            empty = Path(temporary) / "empty.jsonl"
            empty.write_text('{"type":"event_msg","payload":{"text":"secret"}}\n',
                             encoding="utf-8")
            result = aggregate([{"rollout_path": empty},
                                {"rollout_path": Path(temporary) / "absent.jsonl"}], START, END)
            kinds = result["diagnostics"]["errors_by_kind"]
            self.assertEqual(kinds["no_token_usage_records"], 1)
            self.assertEqual(kinds["missing_rollout_file"], 1)
            self.assertEqual(result["diagnostics"]["rollouts_without_token_usage_records"], 2)
            self.assertNotIn("secret", json.dumps(result))


class TelemetrySelectionTests(unittest.TestCase):
    def make_database(self, directory):
        database = directory / "state.sqlite"
        connection = sqlite3.connect(database)
        connection.execute("create table threads (id text, rollout_path text, model text, "
                           "agent_path text, cwd text, first_user_message text, "
                           "creator_account_id text)")
        for name, agent, cwd, model in (
                ("selected", "/root/luna", r"\\?\C:\Projects\DQIX-Decomp", "gpt-6-luna"),
                ("other", "/root/other", r"C:\Projects\DQIX-Decomp\sub", "gpt-6-astra"),
                ("outside", "/root/luna", r"C:\Projects\DQIX-Decomp-old", "gpt-6-luna")):
            rollout = directory / f"{name}.jsonl"
            write_jsonl(rollout, [token_event(f"resp_{name}", thread_id=name)])
            connection.execute("insert into threads values (?,?,?,?,?,?,?)",
                               (name, str(rollout), model, agent, cwd,
                                "SECRET MESSAGE", "SECRET ACCOUNT"))
        connection.commit()
        connection.close()
        return database

    def test_exact_agent_filter_is_read_only_and_does_not_export_secrets(self):
        with tempfile.TemporaryDirectory() as temporary:
            directory = Path(temporary)
            database = self.make_database(directory)
            before = sha256(database)
            result = analyze(database, START, END, agent_path="/root/luna")
            self.assertEqual(result["selection"]["selected_threads"], 2)
            self.assertEqual(result["response_count"], 2)
            self.assertEqual(sha256(database), before)
            serialized = json.dumps(result)
            self.assertNotIn("SECRET MESSAGE", serialized)
            self.assertNotIn("SECRET ACCOUNT", serialized)
            self.assertNotIn(str(database), serialized)

    def test_project_filter_handles_extended_windows_cwd_and_path_prefix(self):
        with tempfile.TemporaryDirectory() as temporary:
            directory = Path(temporary)
            database = self.make_database(directory)
            selected = select_threads(database, project_root=r"C:\Projects\DQIX-Decomp")
            self.assertEqual({item["thread_id"] for item in selected}, {"selected", "other"})

    def test_direct_rollout_mode_uses_explicit_model(self):
        with tempfile.TemporaryDirectory() as temporary:
            path = Path(temporary) / "single.jsonl"
            write_jsonl(path, [session_meta(), token_event()])
            result = analyze(None, START, END, rollouts=[path], model="gpt-6-luna")
            self.assertEqual(result["models"]["gpt-6-luna"]["response_count"], 1)
            self.assertEqual(result["selection"]["kind"], "direct_rollout")


if __name__ == "__main__":
    unittest.main()
