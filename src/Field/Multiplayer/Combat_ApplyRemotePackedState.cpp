#include <globaldefs.h>
ARM
struct GameState; struct Object;
extern "C" void* FieldBattle_GetScene(void*);
extern "C" void* FieldBattle_GetCombatContext(void*);
extern "C" void* FieldBattle_GetEncounterRequest(void*);
extern "C" int GameState_ReadProtagonistObjectIndex(GameState*);
extern "C" unsigned char* _ZN9GameState19GetCombatantByIndexEi(GameState*,int);
extern "C" void CombatStatus_SetAttributeWardKindAndRefreshDuration(Object*,unsigned short);
struct Bits { unsigned short a:2,b:4,c:3,d:3,e:4; };
// Original: arm9/ov017 @ 0x021C6EBC; symbol: func_ov017_021c6ebc; size: 0x134.
extern "C" void Combat_ApplyRemotePackedState(void*,unsigned char* p,GameState* gs,unsigned char* owner) {
 void* mgr=*(void**)(owner+0x3718);
 unsigned char* state=(unsigned char*)FieldBattle_GetEncounterRequest(mgr);
 if(!state) return;
 if(!FieldBattle_GetScene(mgr)) return;
 if(!FieldBattle_GetCombatContext(mgr)) return;
 if(*(signed char*)(state+0x2a)==GameState_ReadProtagonistObjectIndex(gs)) return;
 if(*(unsigned short*)(state+8)!=*(unsigned short*)(p+4)) return;
 unsigned char* obj=_ZN9GameState19GetCombatantByIndexEi(gs,*(unsigned short*)(p+6));
 if(!obj) return;
 ((Bits*)(*(unsigned char**)(obj+0x138)+0x22))->a=(unsigned char)(((Bits*)(p+8))->a);
 ((Bits*)(*(unsigned char**)(obj+0x138)+0x22))->b=(unsigned char)(((Bits*)(p+8))->b);
 ((Bits*)(*(unsigned char**)(obj+0x138)+0x22))->c=(unsigned char)(((Bits*)(p+8))->c);
 CombatStatus_SetAttributeWardKindAndRefreshDuration(*(Object**)(obj+0x138),(unsigned char)(((Bits*)(p+8))->d));
 *(*(unsigned char**)(obj+0x138)+0x24)=p[0xa];
 *(unsigned short*)(*(unsigned char**)(obj+0x138)+4)=*(unsigned short*)(p+0xc);
 *(unsigned short*)(*(unsigned char**)(obj+0x138)+6)=*(unsigned short*)(p+0xe);
}
