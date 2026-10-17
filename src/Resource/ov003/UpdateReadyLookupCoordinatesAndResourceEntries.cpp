#include <globaldefs.h>
ARM
extern "C" {int AreBothWordFieldsD4And9CNonzero(char*);void Object_UpdateAllCountedResourceEntries(unsigned char*);void Object_ComputeGroupAndPartScaledXY(char*,unsigned,int,short*,short*);unsigned char* FindTwoHundredTwentyFourByteRecordByByteKey(unsigned char*,unsigned);void ApplyEntryFlagsAndFinalizeUpdate(void*,int);unsigned ReadBit(void*);void DispatchLookupCoordinatesThroughOwnerID(void*,unsigned,unsigned);}
// Original: arm9/ov003 @ 0x0215501C; symbol: func_ov003_0215501c; size: 0xC0.
extern "C" void UpdateReadyLookupCoordinatesAndResourceEntries(char* p){
if(!*(void**)(p+8))return;
if(*(short*)(p+0x1e6)<0)return;
char* record=(char*)FindTwoHundredTwentyFourByteRecordByByteKey(*(unsigned char**)(p+0x18),*(short*)(p+0x1e6));if(!record)return;
if(!AreBothWordFieldsD4And9CNonzero(record)||!*(void**)(p+0x1c))return;
if(ReadBit(*(void**)(p+0x1c)))return;
short x,y;
Object_ComputeGroupAndPartScaledXY(*(char**)(p+0x18),*(short*)(p+0x1e6),**(short**)(p+8),&x,&y);
ApplyEntryFlagsAndFinalizeUpdate(*(void**)(p+0x1c),*(int*)(p+0x1dc));
x-=16;y-=3;
DispatchLookupCoordinatesThroughOwnerID(*(void**)(p+0x1c),x,y);
Object_UpdateAllCountedResourceEntries((unsigned char*)p+0x2c);
}
