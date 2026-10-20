#include <globaldefs.h>
struct InputStateProjection { unsigned char preceding[0x28]; unsigned short x,y; unsigned char middle[6]; unsigned short held; unsigned char tail[4]; unsigned char flags;};
struct InputStateOwner {void* preceding; InputStateProjection* state;};
// Original data: arm9/ov031 @ 0x2290d40; symbol: data_ov031_02290d40.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" InputStateOwner WfcUtilityAreButtonsPressed_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x0223D354; symbol: func_ov031_0223d354; size: 0x40.
// Layout projection only; broader object ownership remains unclassified.
extern "C" ARM int WfcUtility_AreButtonsPressed(unsigned int mask) {
 if(((*(volatile unsigned short*)0x027fffa8)&0x8000)>>15) return 0;
 return (mask&WfcUtilityAreButtonsPressed_UnknownRoleZeroInitializedStorage.state->held)==mask;
}
