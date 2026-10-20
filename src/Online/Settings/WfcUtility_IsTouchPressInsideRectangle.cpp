#include <globaldefs.h>
struct InputStateProjection { unsigned char preceding[0x28]; unsigned short x,y; unsigned char middle[6]; unsigned short held; unsigned char tail[4]; unsigned char flag0:1; unsigned char active:1; unsigned char remaining:6;};
struct InputStateOwner {void* preceding; InputStateProjection* state;};
// Original data: arm9/ov031 @ 0x2290d40; symbol: data_ov031_02290d40.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" InputStateOwner WfcUtilityAreButtonsPressed_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x0223D49C; symbol: func_ov031_0223d49c; size: 0x88.
// Layout projection only; broader object ownership remains unclassified.
extern "C" ARM int WfcUtility_IsTouchPressInsideRectangle(unsigned short* rect) {
 if(((*(volatile unsigned short*)0x027fffa8)&0x8000)>>15) return 0;
 InputStateProjection* p=WfcUtilityAreButtonsPressed_UnknownRoleZeroInitializedStorage.state;
 if(p->active==0) return 0;
 unsigned int x=p->x; if(rect[0]>x) return 0; if(rect[2]<x) return 0;
 unsigned int y=p->y; if(rect[1]>y) return 0; return rect[3]>=y;
}
