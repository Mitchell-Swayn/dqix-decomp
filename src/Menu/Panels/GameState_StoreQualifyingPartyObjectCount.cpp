#include <globaldefs.h>
ARM
extern "C" {
void __clear(void*,unsigned);
void* _ZN9GameState11GetInstanceEv();
unsigned char* GameState_GetObjectWithFlag100(void*,int);
unsigned GameState_CopyActivePartySlotList(void*,void*);
void Script_WriteIntegerReferenceOutput(void*,int);
}
// Original: arm9/ov023 @ 0x021EA5A4; symbol: func_ov023_021ea5a4; size: 0x8C.
extern "C" int GameState_StoreQualifyingPartyObjectCount(void* output) {
 void* state=_ZN9GameState11GetInstanceEv();
 unsigned char ids[4];
 __clear(ids,4);
 int count=GameState_CopyActivePartySlotList(state,ids);
 int qualifying=0;
 for(int i=0;i<count;++i) {
  unsigned char* object=GameState_GetObjectWithFlag100(state,ids[i]);
  if(object && !(*(unsigned short*)object&0x1000)) {
   int value=*(unsigned short*)(*(unsigned char**)(object+0x130)+4);
   if(value>0) ++qualifying;
  }
 }
 Script_WriteIntegerReferenceOutput(output,qualifying);
 return 1;
}
