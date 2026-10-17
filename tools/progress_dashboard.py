#!/usr/bin/env python3
"""Generate or serve a local progress dashboard from this checkout's reports."""
import argparse
import hashlib
import json
import re
from pathlib import Path
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
import threading

from progress_treemap import ROOT, build_data


def snapshot_id(data):
    # Include source audit/revision as well as report hashes: an unchanged report
    # can accompany a different source tree. Time alone must not duplicate history.
    identity = {key: data[key] for key in ('revision', 'dirty', 'report_sha256',
                'arm7_report_sha256', 'assembly_groups')}
    identity['runtime_support'] = data.get('runtime_support', {})
    return hashlib.sha256(json.dumps(identity, sort_keys=True).encode()).hexdigest()[:20]


def render_history(root, output, history, baseline_path=None):
    baseline_path = baseline_path or output.parent / 'upstream-baseline.json'
    if baseline_path.exists():
        baseline = json.loads(baseline_path.read_text())
        history = [baseline] + [item for item in history
                                if item.get('snapshot_kind') != 'upstream'][-9:]
    payload = json.dumps(history, separators=(',', ':'), ensure_ascii=True).replace('<', '\\u003c')
    return (root / 'tools/progress_dashboard.html').read_text().replace('__PROGRESS_HISTORY__', payload)


def generate(root, report, arm7_report, output, history_directory=None):
    # The integrator holds this lock while source/report changes are unverified.
    # Continue serving the last accepted page until validation and publication.
    if (root / 'build/progress/integration.lock').exists() and output.exists():
        body = output.read_bytes()
        # A long-running publisher may still use an older generator. Reapply the
        # pinned reference to its accepted payload without reading live reports
        # or rewriting the publisher's file while integration is in progress.
        if (output.parent / 'upstream-baseline.json').exists():
            match = re.search(r'<script id="progress-data" type="application/json">(.*?)</script>',
                              body.decode('utf-8'), re.S)
            if match:
                body = render_history(root, output, json.loads(match.group(1))).encode('utf-8')
        return body, None
    data = build_data(root, report, arm7_report)
    history_dir = output.parent / 'snapshots'
    history_dir.mkdir(parents=True, exist_ok=True)
    archive = history_directory or history_dir
    identity = snapshot_id(data)
    snapshot = history_dir / (identity + '.json')
    existing = archive / snapshot.name
    if existing.exists():
        snapshot = existing
    if not snapshot.exists():
        snapshot.write_text(json.dumps(data, separators=(',', ':')) + '\n')
    # Pin the independently built upstream reference even as local history grows.
    baseline_path = archive.parent / 'upstream-baseline.json'
    baseline = json.loads(baseline_path.read_text()) if baseline_path.exists() else None
    # Preserve older snapshots on disk; embed at most ten including the baseline.
    paths = sorted((p for p in archive.glob('*.json') if p.name != snapshot.name),
                   key=lambda p: p.stat().st_mtime)[-(8 if baseline else 9):] + [snapshot]
    history = [json.loads(path.read_text()) for path in paths]
    # Latest always describes the supplied reports, even after checking out an
    # older revision. Its first-seen capture time remains stable in the archive.
    history = [item for item in history if snapshot_id(item) != identity] + [json.loads(snapshot.read_text())]
    if baseline:
        history.insert(0, baseline)
    rendered = render_history(root, output, history, baseline_path=baseline_path)
    output.write_text(rendered, encoding='utf-8')
    return rendered.encode('utf-8'), data


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--report', type=Path, default=ROOT / 'build/usa/report.json')
    parser.add_argument('--arm7-report', type=Path, default=ROOT / 'build/usa/arm7/report.json')
    parser.add_argument('--output', type=Path, default=ROOT / 'build/progress/index.html')
    parser.add_argument('--serve', action='store_true', help='Regenerate from current reports on each page load')
    parser.add_argument('--port', type=int, default=8765)
    parser.add_argument('--host', default='127.0.0.1', help='Bind address; use a LAN address for a browser on another machine')
    args = parser.parse_args()
    generate(ROOT, args.report, args.arm7_report, args.output)
    print(args.output.resolve(), flush=True)
    if not args.serve:
        return
    lock = threading.Lock()

    class Handler(BaseHTTPRequestHandler):
        def do_GET(self):
            if self.path.split('?')[0] not in ('/', '/index.html'):
                self.send_error(404)
                return
            try:
                with lock:
                    body, _ = generate(ROOT, args.report, args.arm7_report, args.output)
            except Exception as error:
                # Never serve a stale success page if reconciliation fails.
                self.send_error(503, 'Progress report unavailable; see server log')
                print(f'Cannot generate dashboard: {error}', flush=True)
                return
            self.send_response(200)
            self.send_header('Content-Type', 'text/html; charset=utf-8')
            self.send_header('Content-Length', str(len(body)))
            self.send_header('Cache-Control', 'no-store')
            self.end_headers()
            self.wfile.write(body)

    server = ThreadingHTTPServer((args.host, args.port), Handler)
    print(f'Progress dashboard: http://{args.host}:{args.port}', flush=True)
    try:
        server.serve_forever()
    except KeyboardInterrupt:
        pass
    finally:
        server.server_close()


if __name__ == '__main__':
    main()
