"""Snapshot history remains attributable, bounded, and safe to embed offline."""
import json
from pathlib import Path
import tempfile
import unittest
from unittest.mock import patch

from progress_dashboard import generate, snapshot_id


class DashboardTests(unittest.TestCase):
    def fixture(self, name='a', symbol='safe'):
        return dict(revision='1234567890', dirty=True, report_sha256=name,
                    arm7_report_sha256='arm7', assembly_groups={}, generated=name,
                    units=[dict(name=symbol)])

    def test_integration_lock_keeps_last_published_page(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            output = root / 'build/progress/index.html'
            output.parent.mkdir(parents=True)
            output.write_bytes(b'last accepted page')
            (output.parent / 'integration.lock').touch()
            with patch('progress_dashboard.build_data') as build:
                body, data = generate(root, None, None, output)
            build.assert_not_called()
            self.assertEqual(body, b'last accepted page')
            self.assertIsNone(data)

    def test_repeated_refresh_does_not_add_history(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            (root / 'tools').mkdir()
            (root / 'tools/progress_dashboard.html').write_text('__PROGRESS_HISTORY__')
            output = root / 'out/index.html'
            with patch('progress_dashboard.build_data', return_value=self.fixture()):
                generate(root, None, None, output)
                body, _ = generate(root, None, None, output)
            self.assertEqual(len(list((output.parent / 'snapshots').glob('*.json'))), 1)
            self.assertEqual(len(json.loads(body)), 1)

    def test_locked_older_publication_gets_reference_without_reading_live_reports(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            (root / 'tools').mkdir()
            (root / 'tools/progress_dashboard.html').write_text('__PROGRESS_HISTORY__')
            output = root / 'build/progress/index.html'
            output.parent.mkdir(parents=True)
            original = '<script id="progress-data" type="application/json">'+json.dumps([self.fixture()])+'</script>'
            output.write_text(original)
            (output.parent / 'integration.lock').touch()
            baseline = dict(self.fixture('upstream'), snapshot_kind='upstream')
            (output.parent / 'upstream-baseline.json').write_text(json.dumps(baseline))
            with patch('progress_dashboard.build_data') as build:
                body, data = generate(root, None, None, output)
            build.assert_not_called()
            self.assertIsNone(data)
            self.assertEqual(json.loads(body), [baseline, self.fixture()])
            self.assertEqual(output.read_text(), original)

    def test_history_is_bounded_but_archives_are_retained(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            (root / 'tools').mkdir()
            (root / 'tools/progress_dashboard.html').write_text('__PROGRESS_HISTORY__')
            output = root / 'out/index.html'
            for index in range(12):
                with patch('progress_dashboard.build_data', return_value=self.fixture(str(index))):
                    body, _ = generate(root, None, None, output)
            self.assertEqual(len(json.loads(body)), 10)
            self.assertEqual(json.loads(body)[-1]['report_sha256'], '11')
            self.assertEqual(len(list((output.parent / 'snapshots').glob('*.json'))), 12)
            # Returning to an old report must make that report current, without
            # duplicating its archive or exceeding the embedded-history limit.
            with patch('progress_dashboard.build_data', return_value=self.fixture('0')):
                body, _ = generate(root, None, None, output)
            self.assertEqual(len(json.loads(body)), 10)
            self.assertEqual(json.loads(body)[-1]['report_sha256'], '0')

    def test_capture_time_does_not_change_identity_and_html_is_escaped(self):
        a = self.fixture(symbol='</script><script>alert(1)</script>')
        b = dict(a, generated='tomorrow')
        self.assertEqual(snapshot_id(a), snapshot_id(b))
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            (root / 'tools').mkdir()
            (root / 'tools/progress_dashboard.html').write_text('__PROGRESS_HISTORY__')
            with patch('progress_dashboard.build_data', return_value=a):
                body, _ = generate(root, None, None, root / 'out/index.html')
            self.assertNotIn(b'</script>', body)
            self.assertEqual(json.loads(body)[0]['units'][0]['name'], a['units'][0]['name'])

    def test_upstream_reference_remains_pinned_after_local_history_grows(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            (root / 'tools').mkdir()
            (root / 'tools/progress_dashboard.html').write_text('__PROGRESS_HISTORY__')
            output = root / 'out/index.html'
            output.parent.mkdir()
            baseline = dict(self.fixture('upstream'), snapshot_kind='upstream',
                            snapshot_label='Original upstream')
            (output.parent / 'upstream-baseline.json').write_text(json.dumps(baseline))
            for index in range(12):
                with patch('progress_dashboard.build_data', return_value=self.fixture(str(index))):
                    body, _ = generate(root, None, None, output)
            history = json.loads(body)
            self.assertEqual(len(history), 10)
            self.assertEqual(history[0], baseline)
            self.assertEqual(history[-1]['report_sha256'], '11')

    def test_staged_publication_reads_bounded_archive_and_keeps_baseline(self):
        with tempfile.TemporaryDirectory() as tmp:
            root=Path(tmp);(root/'tools').mkdir()
            (root/'tools/progress_dashboard.html').write_text('__PROGRESS_HISTORY__')
            accepted=root/'accepted/index.html'
            for index in range(12):
                with patch('progress_dashboard.build_data',return_value=self.fixture(str(index))):
                    generate(root,None,None,accepted)
            archive=accepted.parent/'snapshots'
            before={p.name:(p.read_bytes(),p.stat().st_mtime_ns) for p in archive.glob('*.json')}
            baseline=dict(self.fixture('upstream'),snapshot_kind='upstream')
            (accepted.parent/'upstream-baseline.json').write_text(json.dumps(baseline))
            staged=root/'stage/index.html'
            with patch('progress_dashboard.build_data',return_value=self.fixture('new')):
                body,_=generate(root,None,None,staged,history_directory=archive)
            history=json.loads(body)
            self.assertEqual(len(history),10)
            self.assertEqual(history[0],baseline)
            self.assertEqual(history[-1]['report_sha256'],'new')
            self.assertEqual(len(list((staged.parent/'snapshots').glob('*.json'))),1)
            self.assertEqual(before,{p.name:(p.read_bytes(),p.stat().st_mtime_ns) for p in archive.glob('*.json')})
            # Revisiting an archived identity keeps its first-seen capture time
            # and does not stage an overwrite of immutable history.
            other=root/'other/index.html'
            with patch('progress_dashboard.build_data',return_value=self.fixture('0')):
                body,_=generate(root,None,None,other,history_directory=archive)
            self.assertEqual(json.loads(body)[-1]['report_sha256'],'0')
            self.assertEqual(list((other.parent/'snapshots').glob('*.json')),[])


if __name__ == '__main__':
    unittest.main()
