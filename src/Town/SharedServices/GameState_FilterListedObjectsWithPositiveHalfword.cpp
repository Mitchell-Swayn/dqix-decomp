#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetObjectWithFlag100(void*,int);
extern "C" int GameState_CopyProtagonistPartySlotList(void*,void*);
// Original: arm9/ov003 @ 0x0215E1EC; symbol: func_ov003_0215e1ec; size: 0x90.
extern "C" void GameState_FilterListedObjectsWithPositiveHalfword(unsigned char* self) {
 void* state=_ZN9GameState11GetInstanceEv();
 unsigned char ids[4]={};
 int count=GameState_CopyProtagonistPartySlotList(state,ids);
 self[0x3c3]=0;
 for(int i=0;i<count;i++) {
  char* object=(char*)GameState_GetObjectWithFlag100(state,ids[i]);
  if(object) {
   int value=*(unsigned short*)(*(char**)(object+0x130)+4);
   if(value>0) (self+self[0x3c3]++)[0x3c4]=ids[i];
  }
 }
}
