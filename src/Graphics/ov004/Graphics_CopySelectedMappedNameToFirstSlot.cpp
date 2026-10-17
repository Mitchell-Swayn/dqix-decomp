#include <globaldefs.h>
ARM
#pragma opt_propagation off
struct State; struct Buffer;
extern "C" unsigned char* data_ov004_02171030;
extern "C" unsigned ReadWordFieldAtOffset1C();
extern "C" void* HasTypeSevenAtResolvedHandle(void*,unsigned);
extern "C" void* OV023_GetEmbeddedField20WhenTypeFour(void*,unsigned);
extern "C" unsigned ComputeRowMajorIndexFromThreeHalfwords(unsigned short*);
extern "C" void ClearOwnerBuffersAndResetSignedByteSentinels(signed char*);
extern "C" void Text_MapInputBytesToVariableLengthOutputSequences(const unsigned char*,unsigned char*,unsigned);
extern "C" void CopyBoundedNameToIndexedSlot(Buffer*,int,const char*);
extern "C" void func_ov011_021848a0(State*,unsigned);
struct Entry { unsigned char pad[6],text[38]; };
struct Table { unsigned header; Entry entries[1]; };
// Original: arm9/ov004 @ 0x02169A28; symbol: func_ov004_02169a28; size: 0xB4.
extern "C" int Graphics_CopySelectedMappedNameToFirstSlot(State* self) {
 Table* table=*(Table**)(data_ov004_02171030+0x190);
 if(table) {
  Buffer* names=(Buffer*)ReadWordFieldAtOffset1C();
  unsigned char* selection=(unsigned char*)HasTypeSevenAtResolvedHandle(self,100);
  OV023_GetEmbeddedField20WhenTypeFour(self,3);
  short row=*(short*)(selection+0x5c);
  unsigned index=ComputeRowMajorIndexFromThreeHalfwords((unsigned short*)selection);
  unsigned char text[48]={};
  ClearOwnerBuffersAndResetSignedByteSentinels((signed char*)names);
  Entry* entry=&table->entries[index+row*8];
  Text_MapInputBytesToVariableLengthOutputSequences(entry->text,text,1);
  CopyBoundedNameToIndexedSlot(names,0,(char*)text);
  func_ov011_021848a0(self,0x51);
 }
 return 0;
}
