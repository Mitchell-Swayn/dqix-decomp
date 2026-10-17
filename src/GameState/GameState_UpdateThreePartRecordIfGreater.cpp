#include <globaldefs.h>
ARM
extern "C" {
unsigned char* ReadGlobalValueAt02108844();
void* Object_GetGlobalConnectionState();
char* GameResources_GetInstance();
void ReadThreeIndexedBytesAtStride1C(unsigned char*,unsigned char,unsigned char*,unsigned char*,unsigned char*);
void ClearIndexedTwentyEightByteRecordPayload(char*,int);
void Object_ClearTrailingTwelveBytesOfTwentyEightByteEntry(char*,int);
void Object_ClearTwoOneHundredTwentyEightByteBuffers(unsigned char*);
void Object_SetThreeBytesInTwentyEightByteEntry(unsigned char*,unsigned char,unsigned char,unsigned char,unsigned char);
int IsFirstWordNonzero(void*);
bool TestInactiveOrPrimaryIndexState(unsigned*);
void Network_QueueConnectionValueRecord(int,unsigned char,int,unsigned short);
void GameState_CopySelectedRecordInitialThreeBytes(unsigned char*);
}
// Original: arm9/main @ 0x020703C8; symbol: func_020703c8; size: 0x134.
extern "C" void GameState_UpdateThreePartRecordIfGreater(int index,int first,int second,int third) {
 unsigned char* state=ReadGlobalValueAt02108844();
 void* connection=Object_GetGlobalConnectionState();
 unsigned char* buffers=*(unsigned char**)(GameResources_GetInstance()+0x44c4);
 unsigned char a,b,c;
 ReadThreeIndexedBytesAtStride1C(state,index,&a,&b,&c);
 if(a*10000 + b*100 + c < first*10000 + second*100 + third) {
  if(a!=first) {
   ClearIndexedTwentyEightByteRecordPayload((char*)state,index);
   Object_ClearTwoOneHundredTwentyEightByteBuffers(buffers);
  } else if(b!=second) {
   Object_ClearTrailingTwelveBytesOfTwentyEightByteEntry((char*)state,index);
   Object_ClearTwoOneHundredTwentyEightByteBuffers(buffers);
  }
  Object_SetThreeBytesInTwentyEightByteEntry(state,index,(unsigned char)first,(unsigned char)second,(unsigned char)third);
  if(IsFirstWordNonzero(connection) && TestInactiveOrPrimaryIndexState((unsigned*)connection))
   Network_QueueConnectionValueRecord(2,(unsigned char)index,0,(unsigned short)((first<<10)|(second<<5)|third));
  GameState_CopySelectedRecordInitialThreeBytes(state);
 }
}
