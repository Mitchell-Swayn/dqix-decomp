#pragma once

// The pinned runtime uses little-endian IEEE-754 binary32/binary64 storage.
// Bit initializers preserve its NaN payload as well as infinity values.
union RuntimeBinary32Constant {
    unsigned int bits;
    float value;
};
union RuntimeBinary64Constant {
    unsigned int words[2];
    double value;
};

// Original data: arm9/main @ 0x20eecc4; symbol: data_020eecc4.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0000807f.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern RuntimeBinary32Constant RuntimeParseDoubleFromCharacterCallback_UnknownRoleInitializedBytes; // positive infinity
// Original data: arm9/main @ 0x20eecc8; symbol: data_020eecc8.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffffff7f.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern RuntimeBinary32Constant RuntimePowerEvaluateDoublePower_UnknownRoleInitializedBytes_Variant4; // NaN, payload bits all set
// Original data: arm9/main @ 0x20eeccc; symbol: data_020eeccc.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 000000000000f07f.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern RuntimeBinary64Constant RuntimeParseDoubleFromCharacterCallback_UnknownRoleInitializedBytes_Variant2; // positive infinity
typedef char RuntimeBinary32ConstantSizeCheck[sizeof(RuntimeBinary32Constant) == 4 ? 1 : -1];
typedef char RuntimeBinary64ConstantSizeCheck[sizeof(RuntimeBinary64Constant) == 8 ? 1 : -1];
