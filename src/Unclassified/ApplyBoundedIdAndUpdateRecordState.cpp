#include <globaldefs.h>
extern "C" char* ReadGlobalValueAt02108844();
extern "C" int ReadNonnegativeIndexedBit(char*,char*,int);
extern "C" int TestPackedBitForIndexZeroThrough204(char*,char*,int);
extern "C" void BitArray_SetBoundedIndexThrough204(char*,char*,int);
extern "C" void GameState_CopyB0ByteStateBufferToOutput(void*);
extern "C" void Object_AddByteCounterClampedTo250(void*,int);
extern "C" void GameState_Copy176BytesAtOffset7540(void*);
// Original: arm9/main @ 0x02095FF0; symbol: func_02095ff0; size: 0x98.
extern "C" ARM void ApplyBoundedIdAndUpdateRecordState(char* self,int id) {
 char temporary[0xb0];
 if(id<=0xcc && id>=0) {
  char* state=ReadGlobalValueAt02108844();
  if(ReadNonnegativeIndexedBit(state,state+0x8c,0x1138))++*(short*)(state+0x2ca);
  if(!TestPackedBitForIndexZeroThrough204(self,self+0x84,id)) {GameState_CopyB0ByteStateBufferToOutput(temporary);Object_AddByteCounterClampedTo250(temporary,1);GameState_Copy176BytesAtOffset7540(temporary);}
  BitArray_SetBoundedIndexThrough204(self,self+0x84,id);
 }
}
