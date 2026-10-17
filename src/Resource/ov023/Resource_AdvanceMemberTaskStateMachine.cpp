#include <globaldefs.h>
ARM
extern "C" void Graphics_SelectBackgroundStateRecord(char*,int);
extern "C" void RemoveNonnegativeStoredBackgroundTask(int*);
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
struct Owner{};
typedef int (Owner::*Handler)();
extern "C" Handler data_ov023_021fdaa8[];
struct Bits{unsigned char low:1;unsigned char enabled:1;unsigned char high:6;};
// Original: arm9/ov023 @ 0x021DFB4C; symbol: func_ov023_021dfb4c; size: 0x144.
extern "C" void Resource_AdvanceMemberTaskStateMachine(char* self){
 Handler* table;int previous;
 int target=*(short*)(self+0x772);
 if(*(short*)(self+0x770)!=target)Graphics_SelectBackgroundStateRecord(self,target);
 if(!(*(unsigned short*)(self+0x774)&1))return;
 if(*(signed char*)(self+0x77b)==1 && !((Bits*)(self+0x79b))->enabled){
  RemoveNonnegativeStoredBackgroundTask((int*)(self+0x734));
  char* tasks=self+0x338;int i=0;tasks+=0x400;
  for(;i<7;i++)RemoveNonnegativeStoredBackgroundTask((int*)(tasks+i*4));
  *(unsigned short*)(self+0x774)|=1;*(int*)(self+0x754)=0;return;
 }
 _ZN16BackgroundLoader11GetInstanceEv();
 table=data_ov023_021fdaa8;
 while(*(int*)(self+0x754)>=0 && table[*(int*)(self+0x754)]){
  Handler& handler=table[*(int*)(self+0x754)];
  previous=*(volatile int*)(self+0x754);
  int next=(((Owner*)self)->*handler)();
  *(int*)(self+0x754)=next;
  if(next<0){
   *(unsigned short*)(self+0x774)&=~1;
   RemoveNonnegativeStoredBackgroundTask((int*)(self+0x734));
   char* tasks=self+0x338;int i=0;tasks+=0x400;
   for(;i<7;i++)RemoveNonnegativeStoredBackgroundTask((int*)(tasks+i*4));return;
  }
  if(previous==next)return;
 }
}
