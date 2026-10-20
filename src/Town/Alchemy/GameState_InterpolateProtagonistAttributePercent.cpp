#include <globaldefs.h>
ARM
extern "C" unsigned char* ScriptRecordTable_FindById(unsigned char*,int);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* _ZN9GameState14GetProtagonistEv(void*);
struct Packed {unsigned first:10,second:10,third:10,pad:2;};
struct Record {char pad[10];unsigned short low:12,type:4;Packed output,input;};
// Original: arm9/ov006 @ 0x02153F24; symbol: func_ov006_02153f24; size: 0x214.
extern "C" int GameState_InterpolateProtagonistAttributePercent(unsigned char** owner,int key) {
 Record* record=(Record*)ScriptRecordTable_FindById(*owner,key);
 if(!record)return 0;
 short result=100;
 if(record->type) {
  char* actor=_ZN9GameState14GetProtagonistEv(_ZN9GameState11GetInstanceEv());
  if(actor) {
   unsigned value=0;
   switch(record->type) {
   case 1:value=(unsigned short)((*(Packed**)(actor+0x150))[0].first);break;
   case 2:value=(unsigned short)((*(Packed**)(actor+0x150))[0].second);break;
   case 3:value=(unsigned short)((*(Packed**)(actor+0x150))[0].third);break;
   case 4:value=(unsigned short)((*(Packed**)(actor+0x150))[1].first);break;
   case 5:value=(unsigned short)((*(Packed**)(actor+0x150))[1].second);break;
   case 6:value=(unsigned short)((*(Packed**)(actor+0x150))[1].third);break;
   case 7:value=(unsigned short)((*(Packed**)(actor+0x150))[2].first);break;
   case 8:value=*(unsigned short*)(*(char**)(actor+0x134)+48);break;
   case 9:value=*(unsigned short*)(*(char**)(actor+0x134)+50);break;
   }
   unsigned low=record->output.first,high=record->output.second;
   float rise=(float)(high-low);
   unsigned inputLow=record->input.first;
   float run=(float)(record->input.second-inputLow);
   float converted=(float)value;
   float origin=(float)inputLow;
   float offset=converted-origin;
   float slope=rise/run;
   result=(short)((int)(offset*slope)+low);
   if(result>100)result=100;else if(result<0)result=0;
   if((unsigned)result<=low)result=(short)low;
   if(high<=(unsigned)result)result=(short)high;
  }
 }
 return result;
}
