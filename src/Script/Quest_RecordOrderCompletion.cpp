#include <globaldefs.h>
extern "C" char* GameState_GetSerializedProgressState();
extern "C" int BitArray_ReadNonnegativeIndexMask(char*,char*,int);
extern "C" int Quest_TestBoundedIdFlag(char*,char*,int);
extern "C" void Quest_SetBoundedIdFlag(char*,char*,int);
extern "C" void GameState_CopyStatisticsRecord(void*);
extern "C" void Object_AddByteCounterClampedTo250(void*,int);
extern "C" void GameState_StoreStatisticsRecord(void*);
// Original: arm9/main @ 0x02095FF0; symbol: func_02095ff0; size: 0x98.
extern "C" ARM void Quest_RecordOrderCompletion(char* self,int id) {
 char temporary[0xb0];
 if(id<=0xcc && id>=0) {
  char* state=GameState_GetSerializedProgressState();
  if(BitArray_ReadNonnegativeIndexMask(state,state+0x8c,0x1138))++*(short*)(state+0x2ca);
  if(!Quest_TestBoundedIdFlag(self,self+0x84,id)) {GameState_CopyStatisticsRecord(temporary);Object_AddByteCounterClampedTo250(temporary,1);GameState_StoreStatisticsRecord(temporary);}
  Quest_SetBoundedIdFlag(self,self+0x84,id);
 }
}
