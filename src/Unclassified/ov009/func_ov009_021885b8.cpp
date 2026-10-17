#include <globaldefs.h>
ARM
struct TransitionResource { char unknown[0x568]; short id; };
struct TransitionState { char unknown0[0x7fc]; void* target; char unknown1[0x588]; TransitionResource* resource; char unknown2[0x10]; unsigned flags; };
extern "C" void func_ov023_021e5974(void*,TransitionResource*,int,int,int);
// Original: arm9/ov009 @ 0x021885B8; symbol: func_ov009_021885b8; size: 0x4C.
extern "C" void func_ov009_021885b8(TransitionState* state) {
 if(state->flags&2) { func_ov023_021e5974(state->target,state->resource,state->resource->id,0,0); state->flags=(state->flags|4)&~2; }
}
