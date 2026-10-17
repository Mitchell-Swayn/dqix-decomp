#include <globaldefs.h>
ARM
extern "C" void __clear(void*,unsigned);
extern "C" void* memcpy(void*,const void*,unsigned);
extern "C" int RuntimeMemory_CompareByteRanges(const void*,const void*,unsigned);
extern "C" const char data_020f0238[],data_020f023d[],data_020f0242[];
struct State {char pad[12];int part[4];unsigned char low:4,high:4;};
struct Temp {int value[4];};
extern "C" void Graphics_StageImageDataToMappedVRAMRegion(State*,int,int,const void*);
extern "C" void func_0204ac60(void*,int,const void*);
extern "C" void ClearHalfwordPairBytePairAndWordPair(Temp*);
extern "C" void StageSerializedDataToSelectedVRAMRegion(Temp*,int,int,const void*);
// Original: arm9/main @ 0x0204B4C0; symbol: func_0204b4c0; size: 0xF4.
extern "C" void DispatchResourceUpdateByFourByteTag(State* p,const void* text) {
 if(!text)return;
 char name[8];Temp temp;
 __clear(name,5);memcpy(name,text,5);
 if(!RuntimeMemory_CompareByteRanges(name,data_020f0238,4))Graphics_StageImageDataToMappedVRAMRegion(p,p->low,p->high,text);
 else if(!RuntimeMemory_CompareByteRanges(name,data_020f023d,4))func_0204ac60(p->part,p->low,text);
 else if(!RuntimeMemory_CompareByteRanges(name,data_020f0242,4)){ClearHalfwordPairBytePairAndWordPair(&temp);StageSerializedDataToSelectedVRAMRegion(&temp,p->low,p->high,text);}
}
