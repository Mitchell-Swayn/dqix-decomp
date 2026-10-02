# Joint animation source recovery

Ten existing joint-animation C++ functions are now mapped to original code:

- JACSetup.cpp: animation/track setup, processing callback, and bind-pose
  translation/scaling at 0x020b7840..0x020b7a20.
- JACBoneEvaluation.cpp: channel selection and bone render-data evaluation at
  0x020b7ba0..0x020b7f54.
- JACTranslationSmooth.cpp: sub-frame translation at 0x020b80b4..0x020b8210.
- JACInterpolation.cpp: smooth scaling, frame-aligned and smooth rotation, and
  packed matrix decoding at 0x020b8404..0x020b8e60.

These total 4,428 report code bytes. Nine matched on the first isolated compile.
The matrix decoder had identical instructions but three differently expressed
relocations (96.70%). The four byte fields of each pivot row establish a common
array base: the inferred interior labels at 0x020e9285..0x020e9287 were replaced
with base 0x020e9284 plus offsets 1, 2 and 3. Resolved pointers are unchanged.
JACPivotPositions.cpp owns the corresponding nine four-byte rows (36 bytes),
using the existing matrix-position layout, now named PivotMatrixPositions.
Both matrix-decoder callers use this same representation.

All ten code symbols and the table compare at 100%; full module, symbol and
whole-ROM checks pass with unchanged coverage denominators. Shared declarations
and the inline cross-product helper live in JACInternal.h. No assembly or
binary source substitutions were introduced.

Three existing candidates remain unmapped in JAC.cpp: bind-pose rotation
(82.29%), frame-aligned translation (48.86%) and frame-aligned scaling (81.60%).
These figures describe the initial whole-file comparison before extraction;
no coverage is claimed for them. Their compiler register/instruction differences
still need investigation. Other animation and rendering dependencies remain
external to these units, so this is not a complete animation subsystem.

NameListLookup.cpp additionally recovers the existing 448-byte resource lookup routine at 0x020b736c..0x020b752c. It selects linear search for fewer than 16 entries, otherwise traverses the bit-index tree, compares the 16-byte name and returns the associated record. Its original C++ form matches on the first compile and after extraction. Full ROM checks pass. The adjacent index-returning lookup remains fallback after its initial 66.67% register-allocation comparison.

MaterialColorMasks.cpp and RenderPivotPositions.cpp subsequently recover another
68 bytes at 0x020e9240..0x020e9284: eight material color/control masks and the
render-command copy of the nine pivot rows. Existing material flag extraction
and matrix field accesses establish the layouts. The latter's three interior
labels are represented as base-plus-field offsets, preserving every address.
Both tables compare at 100% and the complete ROM/module/symbol checks pass.
The existing 1,120-byte RenderCommand_6 object also compares at 100% with the
new table representation. Its C++ instructions remain unchanged, and this
data batch earns no additional function or code-byte coverage.

RenderMatrixCommands.cpp owns the two mutable 72-byte graphics command packets at 0x020f1d78..0x020f1e08. Each contains the packed pop/mode/load/scale command sequence, identity rotation, and initially zero translation and scale fields; existing rendering callers populate the mutable fields. Eight interior field labels become base-plus-offset references. Both complete structs match at 100%, and full ROM/module/symbol checks pass. This contributes 144 initialized data bytes.

RenderCommandDispatch.cpp recovers the 128-byte dispatch table at 0x020f1e08..0x020f1e88. The five-bit opcode mask proves 32 slots: 14 named command functions and 18 null entries. Existing command 9 remains fallback; its unmapped candidate declaration now uses the C++ linkage established by the symbol and table, without claiming its implementation matches. The table compares at 100% and full ROM/module/symbol checks pass.

RenderBindingState.cpp defines the existing 112-byte mutable rendering state at 0x020f1d08..0x020f1d78: texture-image command/argument pairs, four-slot material and mesh callback tables, and the command-13 matrix. Its typed initializer preserves the two original 0x10000 matrix entries. Five interior field labels are consolidated into offsets. The state and its existing material/mesh command callers compare at 100%; full ROM checks pass.
