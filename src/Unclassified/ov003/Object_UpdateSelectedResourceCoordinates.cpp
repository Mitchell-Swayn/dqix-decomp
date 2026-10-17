#include <globaldefs.h>
ARM
extern "C" unsigned char* FindTwoHundredTwentyFourByteRecordByByteKey(unsigned char*,unsigned);
extern "C" unsigned ReadBit(void*);
extern "C" void Object_WriteSelectedEntryByte14(void*,int,unsigned char);
extern "C" void Object_UpdateAllCountedResourceEntries(unsigned char*);
extern "C" int AreBothWordFieldsD4And9CNonzero(char*);
extern "C" void Object_ComputeGroupAndPartScaledXY(char*,unsigned,int,short*,short*);
extern "C" void Object_ResetSelectedEntryCoordinatesAndFlags(void*,int);
extern "C" unsigned char* FindRecordPointerByKey(void*,unsigned);
extern "C" void ApplyValueToAllHalfwordCountedEntries(char*,unsigned);
extern "C" void WriteResolvedLookupEntryXY(void*,unsigned,unsigned,unsigned);
// Original: arm9/ov003 @ 0x0216039C; symbol: func_ov003_0216039c; size: 0x134.
extern "C" void Object_UpdateSelectedResourceCoordinates(unsigned char* p) {
 if (!*(void**)(p+0x470) || *(short*)(p+0x488)<0 || !*(void**)(p+0x324)) return;
 unsigned char* r=FindTwoHundredTwentyFourByteRecordByByteKey(*(unsigned char**)(p+0x324),*(short*)(p+0x488));
 if (!r) return;
 if (*(void**)(p+0x390) && ReadBit(*(void**)(p+0x390))) {
 Object_WriteSelectedEntryByte14(*(void**)(p+0x38c),0,0);
 Object_UpdateAllCountedResourceEntries(p+0x334);
 } else if (AreBothWordFieldsD4And9CNonzero((char*)r)) {
 short x,y;
 Object_ComputeGroupAndPartScaledXY(*(char**)(p+0x324),*(short*)(p+0x488),**(short**)(p+0x470),&x,&y);
 x-=16; y-=3;
 Object_ResetSelectedEntryCoordinatesAndFlags(*(void**)(p+0x38c),0);
 unsigned char* e=FindRecordPointerByKey(*(void**)(p+0x38c),0);
 if(e) e[0x15]|=8;
 e=FindRecordPointerByKey(*(void**)(p+0x38c),1);
 if(e) e[0x15]&=~8;
 ApplyValueToAllHalfwordCountedEntries(*(char**)(p+0x38c),*(unsigned*)(p+0x460));
 WriteResolvedLookupEntryXY(*(void**)(p+0x38c),0,x,y);
 Object_UpdateAllCountedResourceEntries(p+0x334);
 }
}
