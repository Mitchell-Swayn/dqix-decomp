# Function call graph

Generate the offline directed-network viewer and machine-readable graph:

```powershell
.venv/Scripts/python.exe tools/call_graph.py
Start-Process build/call-graph/index.html
```

The extractor uses `capstone` and `pyelftools`. Original USA ROM extraction and
existing ARM7 candidate objects are required. It verifies the original ROM SHA-1,
records input SHA-256 hashes, and never writes executable inputs or changes source
coverage. Outputs remain under ignored `build/call-graph/`.

Search by function name or runtime address, select a result, and follow arrows
from caller to callee. Click nodes or the caller/callee list to explore. Choose
one to three hops, filter by module, or select Overview for the entire network.
Drag to pan and scroll to zoom. Fit view resets framing. Hover list entries for
call-site addresses. Export graph JSON provides the complete analyzed network.

ARM9 main, ITCM, DTCM and all 35 configured overlays are processed, including
unreconstructed functions. Symbol files define nodes and bounds. DSD relocation
records define direct calls and retain target overlay identity. Reachable ARM and
Thumb disassembly supplements this with tail branches and unresolved register
transfers. Embedded literal pools are not scanned linearly as instructions.
Arrows include conditional calls and possible tail branches, rather than asserting
that every edge executes. Multiple possible overlay targets are dashed.

ARM7 includes inventoried startup entry points and function symbols in compiled
source units, mapped back to original payload bytes. Its function inventory is
incomplete. Objects provide function names, modes and sizes; original ARM7 bytes
provide instructions. Missing objects are reported. Unknown indirect targets and
uninventoried direct targets remain explicit in JSON and function details.
Computed jumps, callbacks and virtual dispatch are not fully resolved. External
BIOS and executable-like assets are not included. This graph cannot claim every
possible runtime call or a complete whole-cartridge function inventory. Graph
node counts are symbol-inventory counts, not replacements for progress-report
denominators.

Optional browser smoke verification:

```powershell
.venv/Scripts/python.exe -m pip install playwright
.venv/Scripts/python.exe -m playwright install chromium
.venv/Scripts/python.exe tools/check_call_graph_viewer.py
```

This verifies local-file loading, search, navigation, neighborhood traversal,
overview, ARM7 filtering, zoom and fit, and checks browser errors. A screenshot is
saved beside the viewer. No network connection is required by the viewer.

## Dependency layers for reconstruction order

Each function now has `lineage.layer`: the minimum dependency-safe work layer,
counting leaf functions as 1. A caller is one layer above its deepest callee.
This is the longest path through the acyclic dependency-group graph, not the
shortest path to any leaf: every known callee must precede its caller.

Recursive functions are grouped using strongly connected components. Members
share a layer and must be analyzed together; no call-based internal ordering
exists. `dependency_groups` records members and external group dependencies.
Unknown callees and ambiguous overlay targets propagate flags to their callers.
Layers describe the known static graph and may change as targets are resolved.
Data/type dependencies and progress toward matching remain separate concerns.

The viewer displays layers and recursive groups, filters by layer, and orders
search results from lowest layer upward. It exports the full dependency order
as CSV. `build/call-graph/decompilation-order.csv` also contains every inventoried
function, including functions already reconstructed; this is a context ordering,
not a replacement for reconstruction acceptance or the work queue.

Recompute existing graph layers without re-extracting instructions:

```powershell
.venv/Scripts/python.exe tools/lineage_depth.py
.venv/Scripts/python.exe -m unittest discover -s tools -p test_lineage_depth.py
```
