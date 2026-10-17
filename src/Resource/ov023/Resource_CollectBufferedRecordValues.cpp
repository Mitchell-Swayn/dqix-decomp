#include <globaldefs.h>
ARM
extern "C" { unsigned ReadWordFieldAtOffset1C(); void Graphics_FinalizeRecordBuffers(void*); unsigned short ReadRecordDerivedHalfwordOrZero(void*,void*); void func_ov023_021f6d9c(void*,void*); void Unclassified_ClearIndexedHalfwordBit(void*,int,unsigned); void* GetIndexedRecordAddressOrZero(void*,unsigned short); }
// Original: arm9/ov023 @ 0x021FA7D4; symbol: func_ov023_021fa7d4; size: 0x80.
extern "C" void Resource_CollectBufferedRecordValues(unsigned char* object,void* destination) {
 func_ov023_021f6d9c(destination,object+0x78);
 for(unsigned i=0;i<*(unsigned short*)(object+0x72);++i) {
  void* record=GetIndexedRecordAddressOrZero(object+0x24,(unsigned short)i);
  if(record) {
   unsigned value=ReadRecordDerivedHalfwordOrZero(object+0x24,record);
   Unclassified_ClearIndexedHalfwordBit(destination,object[0x74],value);
  }
 }
 Graphics_FinalizeRecordBuffers(object+0x24);
 unsigned char* global=(unsigned char*)ReadWordFieldAtOffset1C();
 *(int*)(global+0x2d8)=0;
 global[0x2e6]=1;
}
