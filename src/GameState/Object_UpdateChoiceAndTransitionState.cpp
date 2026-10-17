#include <globaldefs.h>
ARM
struct GameState; struct Object3D; struct Object; struct E;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" Object3D* _ZN9GameState21GetPartyMemberByIndexEi(GameState*,int);
extern "C" void* Object_GetGlobalConnectionState();
extern "C" void* ReadGlobalAt020FDD44();
extern "C" E* FindRecordAmongFourByNonnegativeKey(E*,int);
extern "C" bool TestInactiveOrPrimaryIndexState(unsigned*);
extern "C" unsigned short _ZNK8Object3D10GetField06Ev(void*);
extern "C" bool Object_InvokeStateMethodAndRecordSuccessfulTransition(Object*,int);
extern "C" unsigned char Object_SelectAvailableRandomChoiceAndUpdateIndex(unsigned char*,unsigned char*);
extern "C" unsigned short ResolveNearestEntryAndStoreSignedIndex(unsigned char*,unsigned char*);
// Original: arm9/main @ 0x02076DF4; symbol: func_02076df4; size: 0x1E8.
extern "C" void Object_UpdateChoiceAndTransitionState(unsigned char* self) {
 void* game=_ZN9GameState11GetInstanceEv();
 void* connection=Object_GetGlobalConnectionState();
 void* records=ReadGlobalAt020FDD44();
 Object3D* member=_ZN9GameState21GetPartyMemberByIndexEi((GameState*)game,*(unsigned short*)(self+0x166));
 if(!FindRecordAmongFourByNonnegativeKey((E*)records,_ZNK8Object3D10GetField06Ev(self))) return;
 if(!TestInactiveOrPrimaryIndexState((unsigned*)connection)) return;
 if(self[0x17c]) return;
 int allow=1;
 if(member && self[0x17b] && !((unsigned char*)member)[0xbe]) {
  unsigned short id=_ZNK8Object3D10GetField06Ev(member);
  if(id==_ZNK8Object3D10GetField06Ev(self)) allow=0;
 }
 if(*(unsigned*)(self+0x14c)<=4000) return;
 if(!allow) return;
 unsigned short old=*(unsigned short*)(self+0x164);
 unsigned char changed=0;
 int first=(self[0x17d]&0x40)==0;
 self[0x17b]=0;
 switch(self[0x138]) {
 case 1:case 3:case 4:case 5:
  if(*(int*)(self+0x134)==4 || *(int*)(self+0x134)==5 || *(int*)(self+0x134)==6)
   *(unsigned short*)(self+0x164)=ResolveNearestEntryAndStoreSignedIndex(self,&changed);
  else *(unsigned short*)(self+0x164)=Object_SelectAvailableRandomChoiceAndUpdateIndex(self,&changed);
  if(!first && !changed) {
   Object_InvokeStateMethodAndRecordSuccessfulTransition((Object*)self,2);
   return;
  }
  if((old==*(unsigned short*)(self+0x164) && !first) || changed) {
   Object_InvokeStateMethodAndRecordSuccessfulTransition((Object*)self,1);
   return;
  }
  Object_InvokeStateMethodAndRecordSuccessfulTransition((Object*)self,2);
  return;
 case 2:
  self[0x17d]|=0x40;
  *(unsigned short*)(self+0x164)=Object_SelectAvailableRandomChoiceAndUpdateIndex(self,&changed);
  if(old==*(unsigned short*)(self+0x164) && !first) Object_InvokeStateMethodAndRecordSuccessfulTransition((Object*)self,1);
  else Object_InvokeStateMethodAndRecordSuccessfulTransition((Object*)self,3);
  return;
 }
}
