# USA progress treemap

Generate the interactive, offline dashboard after refreshing the build reports:

```powershell
.venv/Scripts/python.exe tools/progress_treemap.py
Start-Process build/progress/treemap.html
```

The default output is `build/progress/treemap.html`. It embeds its report snapshot
and needs neither a server nor external JavaScript. Re-run the generator after
accepted reconstruction batches; an already generated page does not refresh
itself. `--output PATH` selects another destination. No ROM bytes are embedded.

The [Brawl progress page](https://decomp.dev/doldecomp/brawl) is the visual
reference: byte-weighted rectangles colored by matching status. This dashboard
is a local project artifact, not a registration or publication on decomp.dev.

Choose ARM9 code, data or function counts. The code view defaults to function
rectangles nested within units; switch Tiles to Units for a coarser view.
Each unit's reported code area is subdivided in proportion to symbol sizes
(which may include literals). Colors describe the owning unit's matching status,
not individual function similarity; no new matching credit is inferred.
Hover to inspect, select a unit to
inspect its source/category and function similarities, or double-click to focus
its module. Module selection and an accessible unit table provide the same
navigation without a pointer. Search highlights names without removing tiles or
changing denominators. Tiny rectangles can be selected through the table.

All ARM9 measures reconcile with the input objdiff report, including original
fallback units, ITCM, DTCM and overlays. Data follows objdiff's measure and includes
BSS. Matching includes assembly and must not be read as pure C/C++ completion.
The existing conservative assembly audit labels affected whole source units;
it does not attribute exact assembly instruction bytes. Function similarity is
fuzzy comparison, not source credit.

ARM7 offers a stored-payload view and a separate runtime-BSS view. C instructions,
literal pools, initialized data, reviewed assembly and original fallback retain
separate accounting. Each view reconciles with its full reported denominator.
ARM7 total instruction/function counts are unknown; no whole-cartridge source
percentage is inferred. Fallback payload bytes are not assumed to be all code.

The page records generation time, report time, revision, dirty status and SHA-256
hashes of both input reports. These identify a snapshot; generating a treemap
does not independently run build acceptance or certify gameplay tests.

Validation:

```powershell
.venv/Scripts/python.exe -m unittest discover -s tools -p test_progress_treemap.py
node tools/test_progress_treemap_ui.cjs
```

The optional Node check executes the page against a small DOM/canvas stub to
check interactions and layout geometry. It is not a real-browser visual test.
