#include <globaldefs.h>
ARM
struct TouchPoint { unsigned short x,y; };
struct InputState { unsigned char pad[0x28]; TouchPoint current,previous; unsigned char pad2[8]; unsigned char active:1,other:7; };
struct InputGlobal { void* unknown; InputState* state; };
// Original data: arm9/ov031 @ 0x2290d40; symbol: data_ov031_02290d40.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" InputGlobal WfcUtilityAreButtonsPressed_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x0223D69C; symbol: func_ov031_0223d69c; size: 0x68.
// Copies current active touch coordinates or the previous point; hardware status bit15 suppresses output.
extern "C" int Input_CopyCurrentOrPreviousTouchPoint(TouchPoint* output)
{
    if(((*(volatile unsigned short*)0x027fffa8)&0x8000)>>15)return 0;
    // The input sample buffer is shared with the IPC sampling path; retain read order.
    volatile InputState* state=WfcUtilityAreButtonsPressed_UnknownRoleZeroInitializedStorage.state;
    if(!state->active) {
        unsigned short x=state->previous.x,y=state->previous.y;
        output->x=x;output->y=y;return 0;
    }
    unsigned short x=state->current.x,y=state->current.y;
    output->x=x;output->y=y;
    return 1;
}
