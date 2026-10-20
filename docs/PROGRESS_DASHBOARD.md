# Local progress dashboard

The dashboard follows the progress bars, report navigation, filters and treemap
of [decomp.dev's 3DWDecomp page](https://decomp.dev/shibbo/3DWDecomp). It reads this
checkout's ARM9 and ARM7 build reports and requires no Node packages or external
JavaScript. It does not publish or register the project on decomp.dev.

Run from the repository root:

```sh
python3 tools/progress_dashboard.py --serve
```

Open http://127.0.0.1:8765. The server refreshes from the current reports on each
page load. The browser checks every 30 seconds and updates when an accepted
report changes; **Refresh reports** checks immediately. It does not run the
build itself. Generate fresh reports with the configured build before refreshing.
Missing or inconsistent reports produce an error rather than a stale success page.

For a browser on another machine, specify an address reachable from that machine:

```sh
python3 tools/progress_dashboard.py --serve --host YOUR_LAN_OR_TAILSCALE_IP
```

`--port`, `--report`, `--arm7-report` and `--output` override defaults. Bind defaults
to loopback; no authentication is provided for network-bound development servers.

For an offline page, run without `--serve` and open `build/progress/index.html`.
The page embeds its data and works without a network connection. Regenerate it to
update the snapshot.

## Browsing

- Code/data bars and function counters show ARM9 report matching, including
  assembly. They are not whole-cartridge C/C++ completion percentages.
- Switch processor, measure, module and unit/function tile granularity. Hover for
  details, select a unit, or double-click to focus its module.
- The unit table supports name/path searches, matching-status filters and sorting.
  Numeric terms such as `<70% >10kb` can be combined with text. KB/MB thresholds
  mean 1024/1048576 units of the selected measure (normally bytes).
- Treemap highlighting keeps all tiles represented. Table filters also leave the
  displayed global totals and treemap denominator unchanged.
- ARM7 separates stored payload from runtime BSS and shows C instructions,
  literals, data, reviewed assembly and original fallback independently. Its total
  code/function denominators remain unknown.
- Unit categories come from the conservative assembly audit. They are not precise
  counts of assembly bytes. Function similarity is fuzzy instruction comparison,
  not evidence of accepted source coverage.

## Integration publication

The integrator creates `build/progress/integration.lock` before modifying source,
ownership maps or reports. While it exists, the server serves the previously
published page. After all required checks pass, remove the lock and regenerate
the dashboard. If integration fails, restore the last accepted state before
removing the lock. This keeps automatic updates from displaying unverified gains.

## Snapshot history

Local snapshots accumulate under `build/progress/snapshots/` when report hashes,
revision, dirty state or assembly category totals change. Reloading unchanged data
creates no duplicate snapshot. Capture time and report time are shown separately.
The page embeds up to ten snapshots; older archives remain on disk. Previous,
Next and Latest navigate actual stored data, including the treemap and unit tables.
History starts at the first capture; no earlier history is invented. It is not a
Git commit timeline and does not include results from unmerged worker checkouts.

`build/progress/upstream-baseline.json` pins an independently built original
upstream reference at the start of the selector. It is retained alongside the
latest nine local snapshots. Each local ARM9 view shows its matched function,
code and data delta against upstream when their denominators agree. The upstream
snapshot records its repository, exact revision, report hash and build evidence;
its ARM7 view is disabled because upstream does not report ARM7 source coverage.
The pinned reference does not automatically advance when upstream changes.

The generator performs the existing report reconciliation checks, including
fallback coverage. It does not independently rebuild or certify ROM acceptance.
Report hashes and revision are included for attribution; no ROM bytes are embedded.

## Verification

```sh
python3 -m unittest discover -s tools -p 'test_progress_*.py'
python3 tools/progress_dashboard.py
node tools/test_progress_dashboard_ui.cjs
```

The Python checks exercise report reconciliation and snapshot retention/safety.
The Node checks exercise all views, layout geometry, filters and history navigation.
A real-browser check also covered filters, ARM7 accounting, selection, module
navigation and a 390px responsive layout during implementation.
