#pragma once

class Animation3D;

struct ObjectAnimationRule
{
    unsigned int mask;
    int slot;
    char extension[8];
};
struct ObjectAnimationRules
{
    ObjectAnimationRule rules[6];
};
// Original data: arm9/main @ 0x20e6f48; symbol: data_020e6f48.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 01000000000000006e7362636100000002000000010000006e73626d6100000004000000030000006e7362746100000008000000020000006e73627470000000 ...; full span in module reference.
// Observed span: 96 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern const ObjectAnimationRules Zone3DLoadBMDJAnimatedObject_UnknownRoleInitializedBytes;

struct ModelAnimationRule
{
    unsigned int mask;
    char extension[8];
    Animation3D** destination;
    int unknown_10;
};
struct ModelAnimationRules
{
    ModelAnimationRule rules[5];
};
// Original data: arm9/main @ 0x20e6fa8; symbol: data_020e6fa8.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 010000006e736263610000000000000000000000020000006e73626d610000000000000000000000040000006e73627461000000000000000100000008000000 ...; full span in module reference.
// Observed span: 100 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern const ModelAnimationRules Zone3DLoadBMDJModel_UnknownRoleInitializedBytes;

