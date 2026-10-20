#include <globaldefs.h>

struct CoordinatePair { short x, y; };
// Two selection variants, each with five coordinate pairs read by func_ov009_02188bf8.
// Original data: arm9/ov009 @ 0x218aa70; symbol: data_ov009_0218aa70.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex b80e9f10350e28100a0fae0f2410330f1e0fb40eb80e5110390efb0fe10e850f2410330fb80eb40e.
// Observed span: 40 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov009.md.
extern "C" const CoordinatePair CharacterCreationReadBodyScalePreset_UnknownRoleInitializedBytes[2][5] = {
 { {3768, 4255}, {3637, 4136}, {3850, 4014}, {4132, 3891}, {3870, 3764} },
 { {3768, 4177}, {3641, 4091}, {3809, 3973}, {4132, 3891}, {3768, 3764} },
};
