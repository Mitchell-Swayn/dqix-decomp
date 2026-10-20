#include <globaldefs.h>
ARM
extern "C" void* memcpy(void*,const void*,unsigned);
extern "C" void __clear(void*,unsigned);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* _ZN9GameState21GetPartyMemberByIndexEi(void*,int);
extern "C" void* GameState_FindIndexedObjectWithFlag1000(void*,int);
extern "C" int GameObject_GetAssociatedPartyMemberIndex(void*);
extern "C" void GameState_CollectPresentPartyMemberIndices(signed char*,signed char*);
// Original: arm9/main @ 0x020DC548; symbol: func_020dc548; size: 0x1C4.
extern "C" void GameState_CopyPartyMemberGroup(int member,signed char* output,signed char* outputCount) {
 int valid;
 if(member>=0 && member<=3)valid=1;else valid=0;
 if(!valid){*outputCount=0;return;}
 void* gs=_ZN9GameState11GetInstanceEv();
 signed char groups[4][4];
 signed char indices[4];
 signed char sizes[4];
 signed char n;
 GameState_CollectPresentPartyMemberIndices(indices,&n);
 int key=-1;
 signed char column=0;
 signed char group=0;
 __clear(sizes,4);
 for(signed char i=0;i<n;i++) {
  int index=indices[i];
  void* obj=GameState_FindIndexedObjectWithFlag1000(gs,index);
  if(obj) {
   if(key==GameObject_GetAssociatedPartyMemberIndex(obj)) {
    groups[group][column]=(signed char)index;
    sizes[group]++;
    column++;
   }
  } else {
   _ZN9GameState21GetPartyMemberByIndexEi(gs,index);
   if(key>=0)group++;
   groups[group][0]=(signed char)index;
   column=0;column++;
   sizes[group]++;
   key=index;
  }
 }
 for(signed char g=0;g<4;g++) {
  int found=0;
  for(signed char i=0;i<sizes[g];i++) {
   if(member==groups[g][i])found=1;
  }
  if(found) {
   if(output)memcpy(output,groups[g],sizes[g]);
   *outputCount=sizes[g];
   break;
  }
 }
}
