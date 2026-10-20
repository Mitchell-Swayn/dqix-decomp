#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* _ZN9GameState20GetGameObjectByIndexEi(void*,int);
extern "C" char* _ZN9GameState20GetUnknownGameObjectEv(void*);
extern "C" int GameState_ReadProtagonistObjectIndex(void*);
extern "C" void GameObject_DisableMovementInput(void*,int);
extern "C" unsigned TextContext_GetSharedInstance();
extern "C" void SystemState_SetFlags(unsigned*,unsigned);
extern "C" void SystemState_ClearFlags(unsigned*,unsigned);
extern "C" void PartySelection_EnableMember(unsigned char*,unsigned);
extern "C" unsigned PartySelection_GetMemberMask(unsigned char*,unsigned);
extern "C" void DisableInterruptsAndHaltForever();
extern "C" unsigned* SystemState_GetGlobalFlags();
extern "C" void Ov017_ApplyIndexedSignedValues(unsigned short);
extern "C" void World_QueueSourceValueWithTag7A(unsigned short);
extern "C" void Network_QueueEncounterFinalization(unsigned short,int);
// Original: arm9/ov017 @ 0x021B848C; symbol: func_ov017_021b848c; size: 0x254.
extern "C" void GameState_BeginEnabledPartySelectionTransition(unsigned char* self,signed char* enabled,int party,int value,unsigned short field,signed char optional,int flag,int position) {
 void* state=_ZN9GameState11GetInstanceEv();
 TextContext_GetSharedInstance();
 unsigned current=*(unsigned short*)(self+0x6b4);
 if(current==4 || current==6 || current==0) return;
 if(enabled[GameState_ReadProtagonistObjectIndex(state)]==0) return;
 if(!(party>=0 && party<=3?1:0) || enabled[party]==0 || !_ZN9GameState20GetGameObjectByIndexEi(state,party)) {
 Network_QueueEncounterFinalization(*(unsigned short*)(self+0x24),0);
 World_QueueSourceValueWithTag7A(*(unsigned short*)(self+0x24));
 *(unsigned short*)(self+0x6b4)=5;return;
 }
 unsigned* global=SystemState_GetGlobalFlags();
 SystemState_ClearFlags(global,0x200);SystemState_SetFlags(global,0x40000);
 char* obj=_ZN9GameState20GetUnknownGameObjectEv(state);
 if(obj) {GameObject_DisableMovementInput(obj,1);*(short*)(obj+0xb2)=0;}
 if(enabled[0] && _ZN9GameState20GetGameObjectByIndexEi(state,0)) PartySelection_EnableMember(self+0x1c,0);
 if(enabled[1] && _ZN9GameState20GetGameObjectByIndexEi(state,1)) PartySelection_EnableMember(self+0x1c,1);
 if(enabled[2] && _ZN9GameState20GetGameObjectByIndexEi(state,2)) PartySelection_EnableMember(self+0x1c,2);
 if(enabled[3] && _ZN9GameState20GetGameObjectByIndexEi(state,3)) PartySelection_EnableMember(self+0x1c,3);
 *(signed char*)(self+0x46)=party;
 if(!PartySelection_GetMemberMask(self+0x1c,(unsigned char)party)) DisableInterruptsAndHaltForever();
 if(value==0) GameState_ReadProtagonistObjectIndex(state);
 *(int*)(self+0x48)=value;*(unsigned short*)(self+0x1e)=field;
 if(position>=0) *(int*)(self+0x28)=position;
 if(optional>-1) {
 unsigned char id=optional;self[0x51]=id;
 if(*(char**)(self+0x6b0)) *(unsigned char*)(*(char**)(self+0x6b0)+0x8e49)=id;
 }
 Ov017_ApplyIndexedSignedValues(*(unsigned short*)(self+0x24));
 if(party!=GameState_ReadProtagonistObjectIndex(state)) {
 if(flag) self[0x6c6]=1;
 *(unsigned*)(self+0x6b8)=0;*(unsigned short*)(self+0x6b4)=4;
 } else *(unsigned short*)(self+0x6b4)=6;
}
