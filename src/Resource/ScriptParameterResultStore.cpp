#include "Resource/Script.h"

// Original data: arm9/main @ 0x2109a28; symbol: data_02109a28.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char CharacterPaletteSetConfigurationParameter_UnknownRoleZeroInitializedStorage[];

// Original: arm9/main @ 0x02099C90; symbol: func_02099c90; size: 0x1C.
extern "C" int CharacterPalette_SetConfigurationParameter(Script::Parameter* parameter)
{
    *(short*)(CharacterPaletteSetConfigurationParameter_UnknownRoleZeroInitializedStorage + 0x28) = (short)parameter->ToInt();
    return 1;
}
