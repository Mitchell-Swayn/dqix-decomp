#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetObjectWithFlag100(void*,int);
// Original: arm9/ov002 @ 0x021548C4; symbol: func_ov002_021548c4; size: 0x80.
extern "C" short Combat_AddCappedValue(void* unused,int index,int amount,unsigned char* status) {
 char* object=(char*)GameState_GetObjectWithFlag100(_ZN9GameState11GetInstanceEv(),index);
 if(!object) return 0;
 int delta;
 char* b;
 char* a=*(char**)(object+0x130);
 b=*(char**)(object+0x134);
 int limit=*(unsigned short*)(b+0x30);
 int current=*(unsigned short*)(a+4);
 int next=current+amount;
 if(next>=(int)limit) {
  delta=limit-current;
  if(delta==0) *status=0; else *status=3;
 } else {
  *status=3;
  delta=next-current;
 }
 *(unsigned short*)(*(char**)(object+0x130)+4)=current+delta;
 return delta;
}
