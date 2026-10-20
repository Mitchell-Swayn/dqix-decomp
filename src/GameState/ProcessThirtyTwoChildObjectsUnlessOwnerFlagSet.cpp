#include <globaldefs.h>
#include "GameState/GameState.h"
struct Child { char pad[0x14]; void* obj; }; struct Owner { char pad[0xc]; Child* children[32]; char pad2[0xc]; unsigned flags; }; extern "C" void ActorSprite_StageChangedFrameToObjVram(void*);
// Original: arm9/main @ 0x0203DDE0; symbol: func_0203dde0; size: 0x4C.
 extern "C" void ProcessThirtyTwoChildObjectsUnlessOwnerFlagSet(Owner* p) { if(p->flags&1)return; GameState::GetInstance(); for(int i=0;i<32;++i) { Child* c=p->children[i]; if(c && c->obj)ActorSprite_StageChangedFrameToObjVram(c->obj); } }
