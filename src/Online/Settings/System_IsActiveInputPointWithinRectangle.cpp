#include <globaldefs.h>
ARM
struct InputState { unsigned char pad[0x28]; unsigned short x,y; unsigned char pad2[12]; unsigned char active:1; unsigned char other:7; };
struct InputGlobal { void* unknown; InputState* state; };
// Original data: arm9/ov031 @ 0x2290d40; symbol: data_ov031_02290d40.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" InputGlobal WfcUtilityAreButtonsPressed_UnknownRoleZeroInitializedStorage;
struct Rect { unsigned short left,top,right,bottom; };
// Original: arm9/ov031 @ 0x0223D414; symbol: func_ov031_0223d414; size: 0x88.
extern "C" int System_IsActiveInputPointWithinRectangle(const Rect* rect) {
 if(((*(volatile unsigned short*)0x027fffa8)&0x8000)>>15) return 0;
 InputState* state=WfcUtilityAreButtonsPressed_UnknownRoleZeroInitializedStorage.state;
 if(!state->active) return 0;
 if(rect->left>state->x) return 0;
 if(rect->right<state->x) return 0;
 if(rect->top>state->y) return 0;
 return rect->bottom>=state->y;
}
