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

Place source under its established subsystem (`Filesystem`, `Graphics`, `Resource`,
`System`, `Memory`, `GameState`, `World`, `Combat`, or `Grotto`). Preserve established
class units and keep each matched compilation unit separate until regrouping is
independently verified. A single-function file uses the descriptive function name.

Use `src/Unclassified/` when the subsystem is not established; retain precise
operation names and recorded uncertainty instead of inventing a gameplay category.
Initialized data and BSS units without an established owner live under `src/Data/`.
Overlay and autoload sources include their module in the directory path. Dedicated
runtime inline assembly remains directly under `src/RuntimeSupport/` for its compiler
and provenance rules.

Run names, worker identifiers, and batch numbers belong in ignored `build/` evidence,
not the integrated source hierarchy. `config/usa/source_layout.json` maps historical
source paths to their reorganized locations. Update delink maps, live naming records,
retention manifests, runtime policies, and linker object references together when
moving a source. Preserve original-location comments and source bytes; verify the
complete ROM and unchanged coverage before accepting a move.
