#include <globaldefs.h>
#include <GameState/GameState.h>
extern "C" GameObject* GameState_FindIndexedObjectWithFlag1000(GameState*,int);
extern "C" int GameObject_GetAssociatedPartyMemberIndex(GameObject*);
extern "C" int GameState_ReadProtagonistObjectIndex(GameState*);
extern "C" char* Network_GetConnectionManager();
extern "C" bool Network_IsSessionActive(void*);
extern "C" int Network_IsMemberAvailableForInteraction(void*,int);
extern "C" int TestResolvedEntryHalfwordHighBit(void*,int);
extern "C" int Object_TestMemberHalfwordBit14(void*,int);
struct ObjectFlag5 {unsigned char low:5,flag:1,high:2;};
// Original: arm9/main @ 0x020DC920; symbol: func_020dc920; size: 0x29C.
extern "C" ARM bool ReadAvailableMemberValueRelativeToProtagonist(int index,int checkBlocked,int allowSpecial,int checkAvailable) {
 GameState* state=GameState::GetInstance();
 GameObject* protagonist=state->GetProtagonist();
 char* context=Network_GetConnectionManager();
 if(protagonist){
  GameObject* member=state->GetPartyMemberByIndex(index);
  if(member){
   if(Network_IsSessionActive(context) && checkAvailable){
    int owner=index;
    if(*(unsigned short*)member & 0x1000)owner=0;
    if(owner!=GameState_ReadProtagonistObjectIndex(state) && !Network_IsMemberAvailableForInteraction(context,owner))return false;
   }
   if(checkBlocked && index!=GameState_ReadProtagonistObjectIndex(state)){
    if(TestResolvedEntryHalfwordHighBit(context,index))return false;
    GameObject* owner=GameState_FindIndexedObjectWithFlag1000(state,index);
    if(owner){int parent=GameObject_GetAssociatedPartyMemberIndex(owner);if(TestResolvedEntryHalfwordHighBit(context,parent) && parent!=GameState_ReadProtagonistObjectIndex(state))return false;}
    if(Object_TestMemberHalfwordBit14(context,index))return false;
    owner=GameState_FindIndexedObjectWithFlag1000(state,index);
    if(owner){int parent=GameObject_GetAssociatedPartyMemberIndex(owner);if(Object_TestMemberHalfwordBit14(context,parent) && parent!=GameState_ReadProtagonistObjectIndex(state))return false;}
   }
   bool same=false;
   unsigned a=protagonist->obj3D_.GetField06();
   unsigned b=member->obj3D_.GetField06();
   if(a==b)same=true;
   else if(allowSpecial && ((protagonist->obj3D_.GetField06()==10000 && member->obj3D_.GetField06()==5900) || (protagonist->obj3D_.GetField06()==5900 && member->obj3D_.GetField06()==10000))) same=true;
   else if(allowSpecial && ((protagonist->obj3D_.GetField06()==10100 && member->obj3D_.GetField06()==6401) || (protagonist->obj3D_.GetField06()==6401 && member->obj3D_.GetField06()==10100))) same=true;
   if(same){
    if(((ObjectFlag5*)((char*)protagonist+0xc2))->flag)return ((ObjectFlag5*)((char*)member+0xc2))->flag!=0;
    return ((ObjectFlag5*)((char*)member+0xc2))->flag==0;
   }
  }
 }
 return false;
}
