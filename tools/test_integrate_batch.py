import json
from pathlib import Path
import subprocess
import tempfile
import unittest

from integrate_batch import DELINKS, IDENTITY, IntegrationError, integrate, merge_delinks, parse_delinks


HEADER = "    .text start:0x02000000 end:0x02010000 kind:code align:32\n"


def block(name, start, end, metadata="complete"):
    return f"\nsrc/{name}.cpp:\n    {metadata}\n    .text start:0x{start:08x} end:0x{end:08x}\n"


BASE = HEADER + block("Base", 0x02000000, 0x02000010)
A = block("A", 0x02000010, 0x02000020)
B = block("B", 0x02000020, 0x02000030)


class ParserTests(unittest.TestCase):
    def test_disjoint_additions_and_header_preserved(self):
        text = merge_delinks(BASE, BASE + A, BASE + B)
        self.assertTrue(text.startswith(HEADER))
        self.assertEqual(list(parse_delinks(text).blocks), ["src/Base.cpp", "src/A.cpp", "src/B.cpp"])

    def test_one_sided_changes_are_not_lost(self):
        changed = BASE.replace("complete", "// complete")
        for ours, theirs in ((changed + A, BASE + B), (BASE + B, changed + A)):
            merged = parse_delinks(merge_delinks(BASE, ours, theirs))
            self.assertIn("// complete", merged.blocks["src/Base.cpp"])
            self.assertEqual(len(merged.blocks), 3)

    def test_identical_changes_and_additions(self):
        changed = BASE.replace("complete", "// complete") + A
        merged = parse_delinks(merge_delinks(BASE, changed, changed))
        self.assertEqual(len(merged.blocks), 2)

    def test_divergent_change_and_add_add_rejected(self):
        other = BASE.replace("complete", "reverse_fn_order")
        with self.assertRaisesRegex(IntegrationError, "divergent"):
            merge_delinks(BASE, BASE.replace("complete", "// complete"), other)
        with self.assertRaisesRegex(IntegrationError, "divergent"):
            merge_delinks(BASE, BASE + A, BASE + A.replace("complete", "// complete"))

    def test_deletions_rejected_even_when_agreed(self):
        for ours, theirs in ((HEADER, BASE), (BASE, HEADER), (HEADER, HEADER)):
            with self.assertRaisesRegex(IntegrationError, "deleted"):
                merge_delinks(BASE, ours, theirs)

    def test_duplicate_filename_aliases_rejected(self):
        for alias in ("src/Base.cpp", "src/base.cpp", "src\\Base.cpp", "src/./Base.cpp"):
            text = BASE + A.replace("src/A.cpp", alias)
            with self.assertRaisesRegex(IntegrationError, "duplicate"):
                parse_delinks(text)

    def test_range_collision_rejected_after_merge(self):
        with self.assertRaisesRegex(IntegrationError, "collision"):
            merge_delinks(BASE, BASE + A, BASE + A.replace("src/A.cpp", "src/B.cpp"))

    def test_adjacent_ranges_and_comments(self):
        text = BASE + "\n// src/Commented.cpp:\n// .text start:0x02000000 end:0x02000010\n" + A
        self.assertEqual(len(parse_delinks(text).blocks), 2)

    def test_invalid_top_sections_ranges_and_markers(self):
        invalid = [BASE.replace("end:0x02000010", "end:0x02000000"),
                   BASE.replace("end:0x02000010", "end:0x02020000"),
                   BASE.replace(".text start:0x02000000 end:0x02000010", ".bss start:0x02000000 end:0x02000010"),
                   BASE.replace("end:0x02000010", "end:bad"),
                   BASE + "<<<<<<< conflict\n", "src/Test.cpp:\n    complete\n"]
        for text in invalid:
            with self.subTest(text=text), self.assertRaises(IntegrationError):
                parse_delinks(text)
        with self.assertRaisesRegex(IntegrationError, "top section"):
            merge_delinks(BASE, BASE.replace("align:32", "align:4"), BASE)


class GitTests(unittest.TestCase):
    def setUp(self):
        self.temporary = tempfile.TemporaryDirectory()
        self.addCleanup(self.temporary.cleanup)
        self.root = Path(self.temporary.name).resolve()
        self.git("init", "-q", "--initial-branch=main")
        self.git("config", "commit.gpgsign", "false")
        self.write(".gitignore", "build/\n")
        self.write(DELINKS, BASE)
        self.write("other.txt", "base\n")
        self.base = self.commit("base")

    def git(self, *args):
        result = subprocess.run(["git", *IDENTITY, *args], cwd=self.root,
                                capture_output=True, check=True)
        return result.stdout.decode("utf-8").strip()

    def write(self, name, text):
        path = self.root / name
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(text, encoding="utf-8")

    def commit(self, message):
        self.git("add", "--all")
        self.git("commit", "-q", "-m", message)
        return self.git("rev-parse", "HEAD")

    def incoming(self, text, other=None):
        self.git("checkout", "-q", "-b", "incoming", self.base)
        self.write(DELINKS, text)
        if other is not None:
            self.write("other.txt", other)
        commit = self.commit("incoming source")
        self.git("checkout", "-q", "main")
        return commit

    def logs(self):
        return list((self.root / "build/integration").glob("*/result.json"))

    def test_real_disjoint_conflict_resolved(self):
        incoming = self.incoming(BASE + B)
        self.write(DELINKS, BASE + A)
        self.commit("current source")
        record, logs = integrate(self.root, [incoming])
        self.assertEqual(record["status"], "integrated")
        self.assertEqual(len(record["applied"]), 1)
        self.assertFalse(record["rom_acceptance"])
        self.assertEqual(len(parse_delinks((self.root / DELINKS).read_text()).blocks), 3)
        self.assertEqual(self.git("status", "--porcelain"), "")
        self.assertEqual(self.git("show", "-s", "--format=%cn <%ce>"), "Codex <codex@openai.com>")
        self.assertTrue(list(logs.glob("stage-*.txt")))
        self.assertTrue((logs / "commands.jsonl").is_file())

    def test_sequential_clean_picks(self):
        self.git("checkout", "-q", "-b", "incoming")
        self.write(DELINKS, BASE + A)
        first = self.commit("first")
        self.write(DELINKS, BASE + A + B)
        second = self.commit("second")
        self.git("checkout", "-q", "main")
        record, _ = integrate(self.root, [first[:12], second])
        self.assertEqual([entry["source"] for entry in record["applied"]], [first, second])

    def test_second_pick_failure_preserves_first_pick(self):
        self.git("checkout", "-q", "-b", "incoming")
        self.write(DELINKS, BASE + B)
        first = self.commit("first")
        self.write("other.txt", "incoming\n")
        second = self.commit("second")
        self.git("checkout", "-q", "main")
        self.write(DELINKS, BASE + A)
        self.write("other.txt", "current\n")
        before = self.commit("current")
        with self.assertRaisesRegex(IntegrationError, "other.txt"):
            integrate(self.root, [first, second])
        record = json.loads(self.logs()[0].read_text())
        self.assertEqual([entry["source"] for entry in record["applied"]], [first])
        self.assertNotEqual(self.git("rev-parse", "HEAD"), before)
        self.assertEqual(self.git("rev-parse", "CHERRY_PICK_HEAD"), second)
        self.assertEqual(len(parse_delinks((self.root / DELINKS).read_text()).blocks), 3)

    def test_existing_operation_and_unignored_logs_rejected(self):
        incoming = self.incoming(BASE + B)
        # A sequencer directory can exist even when the tracked tree is clean.
        sequencer = self.root / ".git/sequencer"
        sequencer.mkdir()
        with self.assertRaisesRegex(IntegrationError, "existing Git operation"):
            integrate(self.root, [incoming])
        sequencer.rmdir()
        self.write(".gitignore", "")
        before = self.commit("no ignored output directory")
        with self.assertRaisesRegex(IntegrationError, "must be ignored"):
            integrate(self.root, [incoming])
        self.assertEqual(self.git("rev-parse", "HEAD"), before)

    def test_other_file_conflict_keeps_git_state_and_files(self):
        incoming = self.incoming(BASE + B, "incoming\n")
        self.write(DELINKS, BASE + A)
        self.write("other.txt", "current\n")
        before = self.commit("current source")
        with self.assertRaisesRegex(IntegrationError, "other.txt"):
            integrate(self.root, [incoming])
        self.assertEqual(self.git("rev-parse", "HEAD"), before)
        self.assertEqual(self.git("rev-parse", "CHERRY_PICK_HEAD"), incoming)
        self.assertIn("<<<<<<<", (self.root / "other.txt").read_text())
        self.assertIn("<<<<<<<", (self.root / DELINKS).read_text())
        self.assertEqual(json.loads(self.logs()[0].read_text())["status"], "stopped")

    def test_divergent_delinks_conflict_is_not_staged(self):
        incoming = self.incoming(BASE.replace("end:0x02000010", "end:0x02000018"))
        self.write(DELINKS, BASE.replace("end:0x02000010", "end:0x02000014"))
        before = self.commit("current change")
        with self.assertRaisesRegex(IntegrationError, "divergent"):
            integrate(self.root, [incoming])
        self.assertEqual(self.git("rev-parse", "HEAD"), before)
        self.assertIn("<<<<<<<", (self.root / DELINKS).read_text())
        self.assertIn(DELINKS, self.git("diff", "--name-only", "--diff-filter=U"))

    def test_colliding_additions_stop_before_staging(self):
        incoming = self.incoming(BASE + A.replace("src/A.cpp", "src/Collision.cpp"))
        self.write(DELINKS, BASE + A)
        before = self.commit("current source")
        with self.assertRaisesRegex(IntegrationError, "collision"):
            integrate(self.root, [incoming])
        self.assertEqual(self.git("rev-parse", "HEAD"), before)
        self.assertEqual(self.git("rev-parse", "CHERRY_PICK_HEAD"), incoming)

    def test_dirty_tracked_worktree_and_index_rejected(self):
        incoming = self.incoming(BASE + B)
        for staged in (False, True):
            self.write("other.txt", "local edit\n")
            if staged:
                self.git("add", "other.txt")
            with self.assertRaisesRegex(IntegrationError, "must be clean"):
                integrate(self.root, [incoming])
            self.assertEqual(self.git("rev-parse", "HEAD"), self.base)
            self.assertEqual((self.root / "other.txt").read_text(), "local edit\n")
        self.assertEqual(self.logs(), [])

    def test_invalid_hash_refs_and_duplicate_requests_rejected_before_pick(self):
        incoming = self.incoming(BASE + B)
        for commits in (["main"], ["HEAD~1"], ["--abort"], [incoming, "f" * 40], [incoming, incoming]):
            with self.subTest(commits=commits), self.assertRaises(IntegrationError):
                integrate(self.root, commits)
            self.assertEqual(self.git("rev-parse", "HEAD"), self.base)

    def test_untracked_file_preserved(self):
        incoming = self.incoming(BASE + B)
        self.write("notes.txt", "leave me\n")
        integrate(self.root, [incoming])
        self.assertEqual((self.root / "notes.txt").read_text(), "leave me\n")

    def test_duplicate_ranges_in_clean_pick_are_detected_and_commit_retained(self):
        incoming = self.incoming(BASE + A + A.replace("src/A.cpp", "src/Collision.cpp"))
        with self.assertRaisesRegex(IntegrationError, "collision"):
            integrate(self.root, [incoming])
        self.assertNotEqual(self.git("rev-parse", "HEAD"), self.base)
        record = json.loads(self.logs()[0].read_text())
        self.assertEqual(len(record["applied"]), 1)
        self.assertEqual(record["status"], "stopped")


if __name__ == "__main__":
    unittest.main()
