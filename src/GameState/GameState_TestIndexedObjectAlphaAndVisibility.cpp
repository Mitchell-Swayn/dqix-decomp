#include <globaldefs.h>
#pragma opt_generateconditionalassignments off
#pragma opt_rebuildconditionals off
#pragma opt_common_subs off
#pragma opt_propagation off
#include "GameState/GameState.h"
#include "World/Object3D.h"
extern "C" Object3D *GameState_GetObjectWithFlag100(GameState *,int);
// Original: arm9/main @ 0x020243B8; symbol: func_020243b8; size: 0x64.
 extern "C" bool GameState_TestIndexedObjectAlphaAndVisibility(unsigned unused,int index) { if(index<0) return true; Object3D *p=GameState_GetObjectWithFlag100(GameState::GetInstance(),index); if(!p) return true; if(!p->GetInheritedAlpha()) return false; if(p->GetAlphaScaleFactor()==0) return false; return p->IsVisible()!=0; }
