#include <globaldefs.h>
ARM
struct TransitionResource { char unknown[0x568]; short id; };
struct TransitionState { char unknown0[0x7fc]; void* target; char unknown1[0x588]; TransitionResource* resource; char unknown2[0x10]; unsigned flags; };
extern "C" void CharacterPreview_QueueAppearanceModelsAndAnimations(void*,TransitionResource*,int,int,int);
// Original: arm9/ov009 @ 0x021885B8; symbol: func_ov009_021885b8; size: 0x4C.
extern "C" void CharacterCreation_QueueChangedAppearancePreview(TransitionState* state) {
 if(state->flags&2) { CharacterPreview_QueueAppearanceModelsAndAnimations(state->target,state->resource,state->resource->id,0,0); state->flags=(state->flags|4)&~2; }
}
