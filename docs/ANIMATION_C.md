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
