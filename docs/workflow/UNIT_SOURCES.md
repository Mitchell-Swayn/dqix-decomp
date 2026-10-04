# Unit source destinations

`config/usa/unit_sources.json` assigns each inventoried ARM9 function, by module
and original address, to a stable source destination. Existing source units retain
their files. Original fallback units have comment-only files under
`src/Units/arm9/<module>/`. These names are provisional build-group identities,
not established subsystem names. The catalog is generated once; changing fallback
object names in later reports must not move its function destinations.

Reserved files are not compiled or credited until real reconstructed functions
are added and the relevant delink ranges select them. Do not add whole fallback
ranges to a source file or mark unassigned bytes complete. An empty source file
has zero reconstructed functions, code and data. All original-byte comparisons,
coverage denominators and ROM/module/symbol/SHA-1 acceptance gates remain required.

Each factory function packet names its unit source file and its baseline SHA-256.
The worker preserves that file's existing contents and appends declarations and
the assigned function, with necessary header and delink-map changes in the same
linear commit. The host checks the source destination and preserved contents both
when receiving the candidate and at independent integration verification.

Only one unresolved candidate may own a unit source file. Other functions in that
unit wait while different units can progress concurrently. Ownership is retained
through review, verification and promotion. Rejected candidates do not receive
source credit. Previously dispatched candidates retain their original contract;
new packets use the stable catalog after deployment and accepted snapshot refresh.

The catalog covers the ARM9 main program, ITCM, DTCM and configured overlays.
ARM7 source files remain governed by its separate source-unit configuration and
processor adapter; unclassified ARM7 code has no invented function destinations.

`tools/unit_sources.py` materializes an initial catalog from a matching report and
module symbol/delink metadata. It refuses to regenerate an existing catalog or
overwrite existing files. Future inventory extensions and deliberate source-file
renames require explicit catalog maintenance, never silent destination changes.
