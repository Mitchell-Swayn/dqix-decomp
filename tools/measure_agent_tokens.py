"""Aggregate unique per-response Codex token telemetry without reading chat events."""

import argparse
from collections import Counter
from datetime import datetime, timezone
import json
import ntpath
from pathlib import Path
import re
import sqlite3
import sys

ROOT = Path(__file__).resolve().parent.parent
DEFAULT_DATABASE = Path.home() / ".codex/state_5.sqlite"
TOKEN_FIELDS = ("input_tokens", "cached_input_tokens", "cache_write_input_tokens",
                "output_tokens", "reasoning_output_tokens", "total_tokens")
# Only parse JSONL lines whose top-level type is token_usage_record. Chat/event
# lines are ignored without deserializing their message payloads.
TOKEN_USAGE_PREFIX = re.compile(
    r'^\s*\{(?=[^{}]*"type"\s*:\s*"token_usage_record")')
SESSION_META_PREFIX = re.compile(
    r'^\s*\{(?=[^{}]*"type"\s*:\s*"session_meta")')
TURN_CONTEXT_PREFIX = re.compile(
    r'^\s*\{(?=[^{}]*"type"\s*:\s*"turn_context")')


def parse_utc(value, field="timestamp"):
    """Parse an ISO-8601 timestamp that explicitly includes a timezone."""
    if not isinstance(value, str) or not value.strip():
        raise ValueError(f"{field} must be an ISO-8601 timestamp with a timezone")
    normalized = value.strip()
    if normalized.endswith("Z"):
        normalized = normalized[:-1] + "+00:00"
    try:
        parsed = datetime.fromisoformat(normalized)
    except ValueError as error:
        raise ValueError(f"{field} is not a valid ISO-8601 timestamp") from error
    if parsed.tzinfo is None or parsed.utcoffset() is None:
        raise ValueError(f"{field} must include Z or a UTC offset")
    return parsed.astimezone(timezone.utc)


def utc_text(value):
    return value.astimezone(timezone.utc).isoformat(timespec="seconds").replace("+00:00", "Z")


def _normalized_path(value):
    text = str(value).strip().replace("/", "\\")
    if text.startswith("\\\\?\\"):
        text = text[4:]
    return ntpath.normcase(ntpath.normpath(text)).rstrip("\\")


def _under_project(cwd, project_root):
    child = _normalized_path(cwd)
    root = _normalized_path(project_root)
    return bool(child and root and (child == root or child.startswith(root + "\\")))


def select_threads(database, agent_path=None, project_root=None):
    """Read only safe routing columns and return matching thread log metadata."""
    if (agent_path is None) == (project_root is None):
        raise ValueError("select exactly one of agent_path or project_root")
    db_path = Path(database).expanduser().resolve()
    if not db_path.is_file():
        raise FileNotFoundError(f"telemetry database does not exist: {db_path.name}")
    uri = db_path.as_uri() + "?mode=ro"
    try:
        connection = sqlite3.connect(uri, uri=True)
    except sqlite3.Error as error:
        raise ValueError(f"could not open telemetry database read-only: {error}") from error
    try:
        connection.execute("PRAGMA query_only = ON")
        columns = {row[1] for row in connection.execute("PRAGMA table_info(threads)")}
        needed = {"id", "rollout_path", "agent_path", "cwd"}
        missing = needed - columns
        if missing:
            raise ValueError("threads table is missing required telemetry columns")
        # Deliberately do not select the mutable model field or any chat/account fields.
        rows = connection.execute(
            "SELECT id, rollout_path, agent_path, cwd FROM threads").fetchall()
    except sqlite3.Error as error:
        raise ValueError(f"could not query telemetry metadata: {error}") from error
    finally:
        connection.close()

    selected = []
    for thread_id, rollout_path, row_agent, cwd in rows:
        if agent_path is not None:
            matches = row_agent == agent_path
        else:
            matches = _under_project(cwd or "", project_root)
        if not matches:
            continue
        path = Path(rollout_path).expanduser()
        if not path.is_absolute():
            path = db_path.parent / path
        selected.append({"thread_id": thread_id, "rollout_path": path,
                         "model": "unknown"})
    return selected


def _read_usage(usage):
    if not isinstance(usage, dict):
        raise ValueError("missing_usage")
    result = {}
    for field in TOKEN_FIELDS:
        value = usage.get(field)
        if isinstance(value, bool) or not isinstance(value, int) or value < 0:
            raise ValueError("invalid_usage")
        result[field] = value
    if result["cached_input_tokens"] > result["input_tokens"]:
        raise ValueError("cached_input_exceeds_input")
    if result["reasoning_output_tokens"] > result["output_tokens"]:
        raise ValueError("reasoning_exceeds_output")
    return result


def scan_rollout(path, model, start, end, expected_thread_id=None):
    """Read token and safe model context records, never chat content."""
    path = Path(path)
    candidates = []
    diagnostics = {"token_usage_records": 0, "records_in_window": 0,
                   "records_outside_window": 0, "errors": []}
    parsed_records = []
    session_ids = set()
    model_contexts = []
    try:
        stream = path.open("r", encoding="utf-8")
    except OSError:
        diagnostics["errors"].append({"kind": "missing_rollout_file",
                                      "source": path.name})
        return candidates, diagnostics
    with stream:
        for line_number, line in enumerate(stream, 1):
            is_token_record = bool(TOKEN_USAGE_PREFIX.search(line))
            is_session_meta = bool(SESSION_META_PREFIX.search(line))
            is_turn_context = bool(TURN_CONTEXT_PREFIX.search(line))
            if not (is_token_record or is_turn_context or
                    (expected_thread_id is None and is_session_meta)):
                continue
            try:
                event = json.loads(line)
            except (json.JSONDecodeError, UnicodeDecodeError):
                if is_token_record:
                    diagnostics["token_usage_records"] += 1
                    diagnostics["errors"].append({"kind": "invalid_token_record_json",
                                                  "source": path.name, "line": line_number})
                elif is_turn_context:
                    diagnostics["errors"].append({"kind": "invalid_turn_context_json",
                                                  "source": path.name, "line": line_number})
                continue
            if is_session_meta and event.get("type") == "session_meta":
                meta_payload = event.get("payload")
                meta_id = meta_payload.get("id") if isinstance(meta_payload, dict) else None
                if isinstance(meta_id, str) and meta_id.strip():
                    session_ids.add(meta_id)
                continue
            if is_turn_context and event.get("type") == "turn_context":
                context_payload = event.get("payload")
                context_model = (context_payload.get("model")
                                 if isinstance(context_payload, dict) else None)
                if not isinstance(context_model, str) or not context_model.strip():
                    diagnostics["errors"].append({"kind": "missing_turn_context_model",
                                                  "source": path.name, "line": line_number})
                    continue
                try:
                    context_timestamp = parse_utc(event.get("timestamp"),
                                                  "turn_context timestamp")
                except ValueError:
                    diagnostics["errors"].append({"kind": "invalid_turn_context_timestamp",
                                                  "source": path.name, "line": line_number})
                    continue
                model_contexts.append((context_timestamp, line_number, context_model))
                continue
            if not is_token_record:
                continue
            diagnostics["token_usage_records"] += 1
            payload = event.get("payload")
            if not isinstance(payload, dict):
                diagnostics["errors"].append({"kind": "missing_payload",
                                              "source": path.name, "line": line_number})
                continue
            response_id = payload.get("response_id")
            if not isinstance(response_id, str) or not response_id.strip():
                diagnostics["errors"].append({"kind": "missing_response_id",
                                              "source": path.name, "line": line_number})
                continue
            record_thread_id = payload.get("thread_id")
            parsed_records.append((event, payload, response_id, record_thread_id, line_number))

        if expected_thread_id is None:
            if len(session_ids) != 1:
                kind = "missing_session_meta_id" if not session_ids else "conflicting_session_meta_ids"
                diagnostics["errors"].append({"kind": kind, "source": path.name})
                expected_thread_id = None
            else:
                expected_thread_id = next(iter(session_ids))

        for event, payload, response_id, record_thread_id, line_number in parsed_records:
            if not isinstance(record_thread_id, str) or not record_thread_id.strip():
                diagnostics["errors"].append({"kind": "missing_thread_id",
                                              "source": path.name, "line": line_number})
                continue
            if expected_thread_id is None or record_thread_id != expected_thread_id:
                diagnostics["errors"].append({"kind": "thread_id_mismatch",
                                              "source": path.name, "line": line_number})
                continue
            try:
                timestamp = parse_utc(event.get("timestamp"), "record timestamp")
            except ValueError:
                diagnostics["errors"].append({"kind": "invalid_record_timestamp",
                                              "source": path.name, "line": line_number})
                continue
            if not start <= timestamp < end:
                diagnostics["records_outside_window"] += 1
                continue
            try:
                usage = _read_usage(payload.get("usage"))
            except ValueError as error:
                diagnostics["errors"].append({"kind": str(error),
                                              "source": path.name, "line": line_number})
                continue
            diagnostics["records_in_window"] += 1
            # Context order is timestamp then line order; when metadata and a usage
            # event share a timestamp, only preceding context applies.
            active_contexts = (context for context in model_contexts
                               if (context[0], context[1]) <= (timestamp, line_number))
            active_context = max(active_contexts, default=None,
                                 key=lambda context: (context[0], context[1]))
            attributed_model = active_context[2] if active_context else model
            candidates.append({"response_id": response_id, "timestamp": timestamp,
                               "model": attributed_model or "unknown", "usage": usage})
    if diagnostics["token_usage_records"] == 0:
        diagnostics["errors"].append({"kind": "no_token_usage_records",
                                      "source": path.name})
    return candidates, diagnostics


def _empty_totals():
    return {"response_count": 0, "input_tokens": 0, "fresh_input_tokens": 0,
            "cached_input_tokens": 0, "cache_write_input_tokens": 0,
            "output_tokens": 0, "reasoning_output_tokens": 0,
            "total_tokens": 0, "max_input_tokens": 0}


def aggregate(sources, start, end):
    """Deduplicate response IDs, reject conflicting duplicates, and aggregate usage."""
    if start >= end:
        raise ValueError("start must be earlier than end")
    unique = {}
    conflicted = set()
    diag_counts = Counter()
    error_examples = []
    rollouts_without_records = 0
    for source in sources:
        candidates, diagnostics = scan_rollout(
            source["rollout_path"], source.get("model", "unknown"), start, end,
            expected_thread_id=source.get("thread_id"))
        diag_counts["rollouts_scanned"] += 1
        if diagnostics["token_usage_records"] == 0:
            rollouts_without_records += 1
        for key in ("token_usage_records", "records_in_window", "records_outside_window"):
            diag_counts[key] += diagnostics[key]
        for error in diagnostics["errors"]:
            diag_counts[error["kind"]] += 1
            if len(error_examples) < 50:
                error_examples.append(error)
        for candidate in candidates:
            response_id = candidate["response_id"]
            if response_id in conflicted:
                continue
            prior = unique.get(response_id)
            if prior is None:
                unique[response_id] = candidate
                continue
            diag_counts["duplicate_records_deduplicated"] += 1
            if prior["usage"] != candidate["usage"] or prior["model"] != candidate["model"]:
                unique.pop(response_id, None)
                conflicted.add(response_id)
                diag_counts["conflicting_response_ids"] += 1
                continue
            if candidate["timestamp"] < prior["timestamp"]:
                prior["timestamp"] = candidate["timestamp"]

    by_model = {}
    for record in unique.values():
        model = record["model"]
        totals = by_model.setdefault(model, _empty_totals())
        usage = record["usage"]
        totals["response_count"] += 1
        for field in TOKEN_FIELDS:
            totals[field] += usage[field]
        totals["fresh_input_tokens"] += usage["input_tokens"] - usage["cached_input_tokens"]
        totals["max_input_tokens"] = max(totals["max_input_tokens"], usage["input_tokens"])
    totals = _empty_totals()
    for model_totals in by_model.values():
        for key in totals:
            if key == "max_input_tokens":
                totals[key] = max(totals[key], model_totals[key])
            else:
                totals[key] += model_totals[key]

    return {"response_count": len(unique), "totals": totals,
            "models": dict(sorted(by_model.items())),
            "diagnostics": {"rollouts_scanned": diag_counts["rollouts_scanned"],
                            "token_usage_records": diag_counts["token_usage_records"],
                            "records_in_window": diag_counts["records_in_window"],
                            "records_outside_window": diag_counts["records_outside_window"],
                            "rollouts_without_token_usage_records": rollouts_without_records,
                            "duplicate_records_deduplicated": diag_counts["duplicate_records_deduplicated"],
                            "conflicting_response_ids": diag_counts["conflicting_response_ids"],
                            "errors_by_kind": dict(sorted((key, value) for key, value in
                                diag_counts.items() if key not in {"rollouts_scanned", "token_usage_records",
                                    "records_in_window", "records_outside_window",
                                    "duplicate_records_deduplicated", "conflicting_response_ids"})),
                            "error_examples": error_examples}}


def analyze(database, start, end, agent_path=None, project_root=None, rollouts=None,
            model="unknown"):
    if rollouts and (agent_path is not None or project_root is not None):
        raise ValueError("--rollout cannot be combined with --agent-path or --project-root")
    if rollouts:
        sources = [{"rollout_path": Path(path), "model": model} for path in rollouts]
        selection = {"kind": "direct_rollout", "selected_threads": 0}
    else:
        threads = select_threads(database, agent_path=agent_path, project_root=project_root)
        sources = threads
        selection = {"kind": "agent_path" if agent_path is not None else "project_root",
                     "selected_threads": len(threads)}
    result = aggregate(sources, start, end)
    result["schema_version"] = 1
    result["window_utc"] = {"start_inclusive": utc_text(start),
                            "end_exclusive": utc_text(end)}
    result["selection"] = selection
    result["accounting_note"] = (
        "input_tokens includes cached_input_tokens; fresh_input_tokens is input minus cached. "
        "cache_write_input_tokens is reported separately and may overlap input. "
        "reasoning_output_tokens is a subset of output_tokens. total_tokens is the recorded total; "
        "do not add cached or reasoning subtotals again. No prices or billing charges are inferred.")
    return result


def build_parser():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--database", type=Path, default=DEFAULT_DATABASE,
                        help="local Codex telemetry SQLite database (opened read-only)")
    selection = parser.add_mutually_exclusive_group()
    selection.add_argument("--agent-path", help="exact threads.agent_path filter")
    selection.add_argument("--project-root", help="include threads whose cwd is inside this project")
    selection.add_argument("--rollout", action="append", type=Path,
                           help="read this JSONL directly; repeat to supply multiple logs")
    parser.add_argument("--model", default="unknown",
                        help="fallback model for direct rollouts without prior turn_context metadata")
    parser.add_argument("--start", required=True, help="inclusive ISO-8601 UTC start time")
    parser.add_argument("--end", required=True, help="exclusive ISO-8601 UTC end time")
    return parser


def main(argv=None):
    parser = build_parser()
    args = parser.parse_args(argv)
    try:
        start = parse_utc(args.start, "--start")
        end = parse_utc(args.end, "--end")
        if start >= end:
            raise ValueError("--start must be earlier than --end")
        if not args.rollout and args.agent_path is None and args.project_root is None:
            raise ValueError("select --agent-path, --project-root, or at least one --rollout")
        result = analyze(args.database, start, end, agent_path=args.agent_path,
                         project_root=args.project_root, rollouts=args.rollout,
                         model=args.model)
    except (OSError, sqlite3.Error, ValueError) as error:
        parser.error(str(error))
    print(json.dumps(result, indent=2))
    diagnostics = result["diagnostics"]
    if diagnostics["errors_by_kind"] or diagnostics["conflicting_response_ids"]:
        return 2
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
