#include <globaldefs.h>
ARM
extern "C" { void* _ZN9GameState11GetInstanceEv(); void* _ZN9GameState21GetPartyMemberByIndexEi(void*,int); unsigned char* GameState_GetIndexList(void*); unsigned char* GameObject_GetLinkedIndexedState(void*); void CharacterState_ClearEncounterSuppression(unsigned char*,int,int); int PartyRoster_ContainsActiveObjectIndex(unsigned char*,unsigned); unsigned PartySelection_GetMemberMask(unsigned char*,unsigned); }
// Original: arm9/ov000 @ 0x021674F4; symbol: func_ov000_021674f4; size: 0xAC.
extern "C" void GameState_ResetSelectedPartyMemberState(unsigned char* owner,int all) {
 void* state=_ZN9GameState11GetInstanceEv();
 unsigned char* indices=GameState_GetIndexList(state);
 unsigned char* active=*(unsigned char**)(*(unsigned char**)(owner+0x29c)+0x8e18);
 for(int i=0;i<4;++i) {
  if(!PartySelection_GetMemberMask(active,(unsigned char)i)) continue;
  if(!all && !PartyRoster_ContainsActiveObjectIndex(indices,i)) continue;
  void* member=_ZN9GameState21GetPartyMemberByIndexEi(state,i);
  if(member) {
   unsigned char* data=GameObject_GetLinkedIndexedState(member);
   int listed=PartyRoster_ContainsActiveObjectIndex(indices,i);
   CharacterState_ClearEncounterSuppression(data,listed,1);
  }
 }
}
