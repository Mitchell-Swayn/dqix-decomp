#include <globaldefs.h>
ARM
extern "C" void Graphics_SelectBackgroundStateRecord(char*,int);
extern "C" void Menu_RemoveStoredBackgroundTask(int*);
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
struct Owner{};
typedef int (Owner::*Handler)();
// Original data: arm9/ov023 @ 0x21fdaa8; symbol: data_ov023_021fdaa8.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 90fc1d0200000000ccfe1d020000000044021e020000000028031e020000000014041e0200000000e8041e0200000000e4051e020000000090061e0200000000 ...; full span in module reference.
// Observed span: 128 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov023.md.
extern "C" Handler ResourceAdvanceMemberTaskStateMachine_UnknownRoleProcedureReferenceRecords[];
struct Bits{unsigned char low:1;unsigned char enabled:1;unsigned char high:6;};
// Original: arm9/ov023 @ 0x021DFB4C; symbol: func_ov023_021dfb4c; size: 0x144.
extern "C" void Resource_AdvanceMemberTaskStateMachine(char* self){
 Handler* table;int previous;
 int target=*(short*)(self+0x772);
 if(*(short*)(self+0x770)!=target)Graphics_SelectBackgroundStateRecord(self,target);
 if(!(*(unsigned short*)(self+0x774)&1))return;
 if(*(signed char*)(self+0x77b)==1 && !((Bits*)(self+0x79b))->enabled){
  Menu_RemoveStoredBackgroundTask((int*)(self+0x734));
  char* tasks=self+0x338;int i=0;tasks+=0x400;
  for(;i<7;i++)Menu_RemoveStoredBackgroundTask((int*)(tasks+i*4));
  *(unsigned short*)(self+0x774)|=1;*(int*)(self+0x754)=0;return;
 }
 _ZN16BackgroundLoader11GetInstanceEv();
 table=ResourceAdvanceMemberTaskStateMachine_UnknownRoleProcedureReferenceRecords;
 while(*(int*)(self+0x754)>=0 && table[*(int*)(self+0x754)]){
  Handler& handler=table[*(int*)(self+0x754)];
  previous=*(volatile int*)(self+0x754);
  int next=(((Owner*)self)->*handler)();
  *(int*)(self+0x754)=next;
  if(next<0){
   *(unsigned short*)(self+0x774)&=~1;
   Menu_RemoveStoredBackgroundTask((int*)(self+0x734));
   char* tasks=self+0x338;int i=0;tasks+=0x400;
   for(;i<7;i++)Menu_RemoveStoredBackgroundTask((int*)(tasks+i*4));return;
  }
  if(previous==next)return;
 }
}
