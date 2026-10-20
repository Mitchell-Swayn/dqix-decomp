// Effect suffix followed by four animation resource filename patterns.
struct AnimationFilePatterns { char effectSuffix[8]; char resourcePatterns[4][17]; };
// Original data: arm9/main @ 0x20f04b8; symbol: data_020f04b8.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 2e62656666000000646174612f616e692f25732e4e43455200646174612f616e692f25732e4e414e5200646174612f616e692f25732e4e43475200646174612f ...; full span in module reference.
// Observed span: 76 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" AnimationFilePatterns Object3DLoadCHRArchiveAndOptionalAuxiliaryResource_UnknownRoleInitializedBytes = { ".beff", {
    "data/ani/%s.NCER",
    "data/ani/%s.NANR",
    "data/ani/%s.NCGR",
    "data/ani/%s.NCLR",
} };
