#include <globaldefs.h>
#include <GameState/GameState.h>
extern "C" int GameState_FindIndexedObjectWithFlag1000(GameState*,int);
struct Flag { unsigned char rest:5; unsigned char blocked:1; unsigned char tail:2; };
// Original: arm9/main @ 0x02039DF4; symbol: func_02039df4; size: 0x7C.
extern "C" ARM void Object3D_HideSelectedObjectKindsWithInheritedAlpha(Object3D* self) { unsigned char* bytes=(unsigned char*)self; if(((Flag*)(bytes+194))->blocked)return; if(!GameState_FindIndexedObjectWithFlag1000(GameState::GetInstance(),*(short*)(bytes+4)))return; int kind=self->GetField06()/100; if(kind!=43 && kind!=45 && kind!=64 && kind!=41)return; bytes[462]|=4; self->TransitionInheritedAlpha(0,0); self->SetInheritedAlpha(0); }
