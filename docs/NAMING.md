# Function naming and original locations

Every reconstructed function must have a descriptive source name and a comment
recording its original identity. Byte matching alone does not complete naming.

- Use PascalCase verb/object names for project-owned functions and methods:
  `ComputePageRowAndColumn`, `ReadEntryCount`, `InitializeRomFileTables`.
- Scope names with an established class, namespace, or subsystem when known.
  Standalone C linkage uses `Subsystem_VerbObject` when the subsystem is established.
- Preserve established standard-library, compiler runtime, and SDK names and
  ABI-required constructors, destructors, operators, and initialization symbols.
  Existing meaningful upstream names are retained unless a reviewed rename improves them.
- Infer names from instructions, types, field accesses, callees, and call sites.
  Prefer a precise low-level description to speculative gameplay meaning.
  An offset may qualify an otherwise meaningful field name until its role is known.
- Address-only names (`func_0205bb04`, `Func0207e2e0`) are pending naming work.
  `UnknownOperation` and invented gameplay names do not resolve that work.
- Use `Unknown` only for the uncertain part of a partially understood operation;
  record the uncertainty in its comment and naming registry.
- If two functions share a description, establish their object/subsystem context.
  A module/address suffix is allowed only as a temporary collision disambiguator,
  and must be listed as pending refinement.

Put this comment directly above the definition (a dedicated runtime source's
existing provenance header may serve the same purpose):

```cpp
// Original: arm9/main @ 0x0205BB04; symbol: func_0205bb04; size: 0x80.
// Computes a page index and row/column coordinates from a validated entry index.
extern "C" bool ComputePageRowAndColumn(/* original ABI */)
{
    // Matched implementation.
}
```

For overlays record the overlay identity as well as the loaded address, e.g.
`arm9/ov017 @ 0x...`; addresses alone are not globally unique. For ARM7 record
`arm7/wram` or `arm7/mainram`. Keep the original symbol in the comment and the
address-bound registry after a rename. Preserve source comments and evidence.

Update definitions, declarations, references, and the owning `symbols.txt`
together. Never rename unrelated functions merely because overlay addresses
overlap. Preserve compiler-generated ABI spellings and runtime evidence hashes.
Naming migrations require object/module/symbol checks and the original ROM SHA-1,
unchanged coverage denominators, and the project-wide integration lock.

Future worker manifests must include a reviewed descriptive name, original
identity/location comment, and behavior evidence. Unresolved naming is explicit
required work; it must not be described as fully named source.

## Source file organization

Place source under its subsystem folder. Engine and game-core folders are
`System`, `Graphics`, `Sound`, `Filesystem`, `Resource`, `Memory`, `Math`, `Util`, `Network`,
`Text`, `UI`, `Save`, `Actor`, `Camera`, `World`, `Script`, `GameState` and `Grotto`.
Game-mode overlays use `Combat`, `Field`, `Event`, `Town`, `Menu`, `Online` and `Debug`.
`docs/subsystem-map-usa.json` assigns every ARM9 function to a chunk with a folder;
use its `source_directory` when present, otherwise its root `folder`, unless
reviewed evidence shows a different owner. Feature ownership is primary: examples
are `src/Menu/Bestiary/` and `src/Menu/CharacterCreation/`. Module names identify binary locations in symbol maps and original-location
comments; they are not source-directory components. Preserve
established class units and keep each matched compilation unit separate until
regrouping is independently verified. A single-function file uses the descriptive
function name.

`src/Unclassified/` is a legacy holding area, not a destination. Record remaining
uncertainty in the name's `Unknown` part and the naming registry rather than
inventing a gameplay category.
Initialized data and BSS units without an established owner live under `src/Data/`.
Overlay identity is retained in original-location comments and the owning binary
maps. Source directories use feature ownership without `ovNNN` components. Dedicated
runtime inline assembly remains directly under `src/RuntimeSupport/` for its compiler
and provenance rules.

Run names, worker identifiers, and batch numbers belong in ignored `build/` evidence,
not the integrated source hierarchy. `config/usa/source_layout.json` maps historical
source paths to their reorganized locations. Update delink maps, live naming records,
retention manifests, runtime policies, and linker object references together when
moving a source. Preserve original-location comments and source bytes; verify the
complete ROM and unchanged coverage before accepting a move.

## Auditing existing naming debt

`python3 tools/audit_naming.py --output build/naming-review.json` lists matched
ARM9 functions with address-only names, temporary address disambiguators or
recorded uncertainty, plus functions whose subsystem ownership is unclassified.
The lists are review queues, not instructions to generate names automatically.
Names containing `Unknown` can correctly retain uncertainty; compiler-generated
initialization symbols and established SDK/runtime names keep their ABI spellings.

Review complete bodies and relevant callers before proposing a name. Keep a
precise behavioural name under `Unclassified` when the subsystem is unresolved.
Do not replace empty callbacks with invented roles or move functions into a
subsystem based only on their caller. Rename a source file together with its
function and update source-layout and naming records, live references, delink
maps, symbol maps and hash-bound provenance. Preserve original identity comments.
Verify matching coverage and the full ROM before publishing the changed tree.

## Subsystem discovery and serial integration

Refactor one bounded subsystem at a time. `docs/SUBSYSTEM_MAP.md` defines the
proposed ARM9 chunks, their order and `tools/subsystem_map.py` work packets.
Start with an identified entry point and
trace its complete bodies, callers, callees, shared state, callback registration
and relevant resources. Distinguish the owning routines from generic SDK/runtime
dependencies and consumers. Call-graph connectivity or adjacent addresses alone
do not establish common ownership. Keep ambiguous indirect/overlay references
explicit.

Record a module/address inventory and behavior evidence before naming. Preserve
accurate established names and ABI symbols. Name uncertain operations precisely
without guessing gameplay roles. Keep unreconstructed and encoded routine
identities separate from matched-source coverage.

Integrate each reviewed subsystem as one guarded naming/path migration, updating
references, symbol maps, source-layout/naming records and provenance together.
Preserve compilation-unit boundaries and run the full object/module/symbol/ROM
and unchanged-coverage checks before moving to the next subsystem. Preserve
pending evidence when discovery exposes an unresolved boundary.

## Data symbol names and values

Keep original processor, module, address and symbol comments beside data definitions or declarations. Record inferred purpose and original initialized values; large objects can link to the full module record under `docs/data-symbols/`. Distinguish initialized bytes from mutable runtime state and zero-initialized BSS.

Use literal-content or established layout names where supported. A consumer scope records a reference and does not prove exclusive ownership. Use `UnknownRole` for unresolved semantics and keep `semantic_review_required` in `config/usa/data_names.json`; contextual renaming does not clear that debt. Preserve overlapping labels, distinct copies, original bytes and logical layout uncertainty.

The legacy linker limits the aggregate `-force_active` symbol list to 255 characters, including commas; separate occurrences share that limit. Retained symbols need concise names within that total.
