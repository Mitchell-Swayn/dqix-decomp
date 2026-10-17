#include <globaldefs.h>
ARM
extern "C" {
void* _ZN9GameState11GetInstanceEv();
void* Object_GetGlobalConnectionState();
unsigned char* ReadGlobalAt02100044();
unsigned char* Network_PopPendingRecordAndReturnIndexUnderLock(unsigned char*,int*);
unsigned Object_ReadIndexedBitAtOffset1524(unsigned char*,int);
void* GameResources_GetInstance();
}
typedef void (*Handler)(int,unsigned char*,void*,void*,void*);
extern "C" Handler data_ov017_021d7f98[];
// Original: arm9/ov017 @ 0x021D48F0; symbol: func_ov017_021d48f0; size: 0x90.
extern "C" void Network_DispatchEnabledPendingRecords() {
 void* state=_ZN9GameState11GetInstanceEv();
 void* resources=GameResources_GetInstance();
 unsigned char* queue=ReadGlobalAt02100044();
 void* connection=Object_GetGlobalConnectionState();
 int index;
 unsigned char* record;
 while((record=Network_PopPendingRecordAndReturnIndexUnderLock(queue,&index))!=0) {
  unsigned type=record[0];
  if(type<0xbc && Object_ReadIndexedBitAtOffset1524(queue,type))
   data_ov017_021d7f98[type](index,record,state,resources,connection);
 }
}
