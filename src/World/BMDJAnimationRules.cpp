#include "World/BMDJAnimationRules.h"
#include <globaldefs.h>

// Original data: arm9/main @ 0x20e6f48; symbol: data_020e6f48.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 01000000000000006e7362636100000002000000010000006e73626d6100000004000000030000006e7362746100000008000000020000006e73627470000000 ...; full span in module reference.
// Observed span: 96 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern const ObjectAnimationRules Zone3DLoadBMDJAnimatedObject_UnknownRoleInitializedBytes =
{{
    { 1, 0, "nsbca" },
    { 2, 1, "nsbma" },
    { 4, 3, "nsbta" },
    { 8, 2, "nsbtp" },
    { 16, -1, "bcfg" },
    { 0, 0, "" }
}};

// Original data: arm9/main @ 0x20e6fa8; symbol: data_020e6fa8.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 010000006e736263610000000000000000000000020000006e73626d610000000000000000000000040000006e73627461000000000000000100000008000000 ...; full span in module reference.
// Observed span: 100 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern const ModelAnimationRules Zone3DLoadBMDJModel_UnknownRoleInitializedBytes =
{{
    { 1, "nsbca", NULL, 0 },
    { 2, "nsbma", NULL, 0 },
    { 4, "nsbta", NULL, 1 },
    { 8, "nsbtp", NULL, 1 },
    { 0, "", NULL, 0 }
}};
