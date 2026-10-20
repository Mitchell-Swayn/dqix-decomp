#include <globaldefs.h>
#include <std_library_functions.h>
ARM
extern "C" int Network_GetConnectionWorkspace(unsigned);
// Original data: arm9/ov031 @ 0x2245fe0; symbol: data_ov031_02245fe0.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 4652454553504f54.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char NetworkClassifyFreespotSsid_UnknownRoleInitializedBytes[];
struct SelectedState { unsigned char unknown[0xd0c]; unsigned char lowNibble:4, upper:4; };
// Original: arm9/ov031 @ 0x022145B4; symbol: func_ov031_022145b4; size: 0x4C.
// Returns 8 when selected state low nibble is zero or six and the eight-byte signature matches.
extern "C" int Network_ClassifyFreespotSsid(const char* object)
{
 SelectedState* state=(SelectedState*)Network_GetConnectionWorkspace(16);
 unsigned lowNibble=state->lowNibble;
 if((lowNibble==0 || lowNibble==6) && !strncmp(object+12,NetworkClassifyFreespotSsid_UnknownRoleInitializedBytes,8))return 8;
 return 0;
}
