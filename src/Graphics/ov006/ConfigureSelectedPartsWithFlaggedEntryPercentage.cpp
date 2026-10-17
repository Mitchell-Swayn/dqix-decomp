#include <globaldefs.h>
ARM
extern "C" void SetRecordOffsetOrComputeTextPosition(void**,int,int,int,short);
extern "C" void Object_ApplyModeOneToSelectedPartGroup(unsigned char*,int);
extern "C" void SetFlagOneForEachListedId(char*,int);
extern "C" void Object_SetSelectedPartInitialWord(char*,int,int);
extern "C" void WriteResolvedEntryHalfword0E(char*,int,short);
extern "C" void WriteResolvedEntryByte15Flag2(unsigned char*,int,int);
extern "C" int Object_CreateAndConfigureSelectedDisplayPart(char*,int);
extern "C" unsigned _ffltu(unsigned);
extern "C" unsigned _fdiv(unsigned,unsigned);
extern "C" unsigned _fmul(unsigned,unsigned);
extern "C" int _ffix(unsigned);
extern "C" short GameState_CountAndStoreFlaggedEntries(void*);
// Original: arm9/ov006 @ 0x0215FA1C; symbol: func_ov006_0215fa1c; size: 0x160.
extern "C" void ConfigureSelectedPartsWithFlaggedEntryPercentage(char* self,int enabled) {
 char* obj=*(char**)(self+0x14);
 SetFlagOneForEachListedId(obj,13);
 Object_ApplyModeOneToSelectedPartGroup((unsigned char*)obj,0x56);
 WriteResolvedEntryHalfword0E(*(char**)(self+0x14),0x56,0x2b);
 if(*(unsigned char*)(self+0x38f)!=10 && *(unsigned char*)(self+0x38f)!=3) {
 short value=0x2c;
 if(!enabled) {
 switch(*(short*)(self+0x366)) {
 case 0x25:value=0x12;break;
 case 0x26:value=0x13;break;
 }
 }
 WriteResolvedEntryHalfword0E(obj,0x57,value);
 Object_ApplyModeOneToSelectedPartGroup((unsigned char*)obj,0x57);
 SetRecordOffsetOrComputeTextPosition((void**)obj,13,0x57,1,4);
 if(enabled) {
 unsigned count=(unsigned short)GameState_CountAndStoreFlaggedEntries(self+0x74);
 int n=_ffix(_fmul(_fdiv(_ffltu(count),0x43e00000),0x461c4000));
 int percent=(n-n%100)/100;
 if(count && percent<=0) percent=1;
 if(percent>100) percent=100;
 Object_SetSelectedPartInitialWord(obj,0x58,percent);
 Object_ApplyModeOneToSelectedPartGroup((unsigned char*)obj,0x58);
 WriteResolvedEntryHalfword0E(*(char**)(self+0x14),0x56,0x2e);
 }
 }
 WriteResolvedEntryByte15Flag2((unsigned char*)obj,13,1);
 Object_CreateAndConfigureSelectedDisplayPart(obj,13);
}
