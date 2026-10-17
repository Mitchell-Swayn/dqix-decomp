#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetObjectWithFlag100(void*,int);
extern "C" char* ReadGlobalAt02108E10();
extern "C" char* TryTransformFirstOrSecondEmbeddedRecord(char*,int);
extern "C" int Object_TestPositiveCountAndOffset2F4Bit2(void*);
extern "C" int SelectHalfwordForPartyIndex(int,unsigned,unsigned);
struct Bits { unsigned low:10; unsigned high:10; unsigned rest:12; };
struct IdBits { unsigned id:12; unsigned rest:20; };
#define IsPartyIndex(index) ((index)>=0 && (index)<=3 ? 1 : 0)
// Original: arm9/ov024 @ 0x021E99D8; symbol: func_ov024_021e99d8; size: 0x14C.
extern "C" int SelectPartyRecordValueWithFlagOverrides(char* state,char* actor,char* record) {
 int index=*(short*)(*(char**)(actor+0x10)+0x20);
 if((*(unsigned*)(record+0x10)&0x2000000) && *(int*)(state+0x14)<=0) {
 if(IsPartyIndex(index)) {*(unsigned char*)(actor+0xb)|=2; return 0x1ef;}
 }
 if(((IdBits*)(record+4))->id==0x1f8) {
 char* other=TryTransformFirstOrSecondEmbeddedRecord(ReadGlobalAt02108E10(),*(short*)(actor+2));
 if(!other) return 0;
 unsigned id=*(unsigned short*)(actor+2);
 if(id==0x1c || id==0x247) return 0x2e;
 return SelectHalfwordForPartyIndex(index,((Bits*)(other+0x20))->low,((Bits*)(other+0x20))->high);
 }
 int value=SelectHalfwordForPartyIndex(index,((Bits*)(record+0x20))->low,((Bits*)(record+0x20))->high);
 if(value==1 && IsPartyIndex(index)) {
 char* obj=(char*)GameState_GetObjectWithFlag100(_ZN9GameState11GetInstanceEv(),index);
 if(obj && (*(unsigned*)(record+0x10)&0x100000) && Object_TestPositiveCountAndOffset2F4Bit2(*(void**)(obj+0x150))) return 0x10;
 }
 return value;
}
