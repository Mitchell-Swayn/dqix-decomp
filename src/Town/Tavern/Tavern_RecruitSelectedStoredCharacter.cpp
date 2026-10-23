#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetIndexList(void*);
extern "C" int Tavern_AdvanceStoredCharacterActivation(void*,int);
extern "C" int PartyRoster_RemoveCharacterBySlotIdAndCompact(void*,int);
extern "C" unsigned char* GameState_GetSerializedProgressState();
extern "C" void BitArray_SetIndexedBoolean(void*,unsigned char*,int,int);
extern "C" void* _ZN9GameState14GetProtagonistEv(void*);
extern "C" void GameObject_DisableMovementInput(void*,int);
// Original: arm9/ov003 @ 0x021669F0; symbol: ApplyStoredPartyIndexAndResetProtagonist; size: 0xa0.
// Applies stored party index after validation, sets global bit784 and resets protagonist state.
extern "C" int Tavern_RecruitSelectedStoredCharacter(char* p){
 if(*(short*)(p+0x480)<0)return 1;void* state=_ZN9GameState11GetInstanceEv();void* list=GameState_GetIndexList(state);
 int result=Tavern_AdvanceStoredCharacterActivation(p,*(short*)(p+0x480));if(result==0)return 0;
 if(result==1){PartyRoster_RemoveCharacterBySlotIdAndCompact(list,(signed char)*(short*)(p+0x480));unsigned char* global=GameState_GetSerializedProgressState();BitArray_SetIndexedBoolean(global,global+0x8c,0x784,1);}
 void* protagonist=_ZN9GameState14GetProtagonistEv(state);if(protagonist)GameObject_DisableMovementInput(protagonist,1);return 1;
}
