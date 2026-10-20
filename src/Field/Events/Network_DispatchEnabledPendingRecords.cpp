#include <globaldefs.h>
ARM
extern "C" {
void* _ZN9GameState11GetInstanceEv();
void* Network_GetConnectionManager();
unsigned char* Network_GetCommandRecordPool();
unsigned char* Network_PopIncomingMessageAndRecycleSlot(unsigned char*,int*);
unsigned Network_IsIncomingMessageTypeEnabled(unsigned char*,int);
void* GameResources_GetInstance();
}
typedef void (*Handler)(int,unsigned char*,void*,void*,void*);
// Original data: arm9/ov017 @ 0x21d7f98; symbol: data_ov017_021d7f98.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 5c431c02d8441c02ec401c0218461c02189f1c026cc21c0220c31c0288c31c02f8c41c02c4c61c0230c81c0200ca1c02f8ca1c02dccb1c0210cd1c0270cf1c02 ...; full span in module reference.
// Observed span: 752 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern "C" Handler NetworkDispatchEnabledPendingRecords_UnknownRoleProcedureReferenceRecords[];
// Original: arm9/ov017 @ 0x021D48F0; symbol: func_ov017_021d48f0; size: 0x90.
extern "C" void Network_DispatchEnabledPendingRecords() {
 void* state=_ZN9GameState11GetInstanceEv();
 void* resources=GameResources_GetInstance();
 unsigned char* queue=Network_GetCommandRecordPool();
 void* connection=Network_GetConnectionManager();
 int index;
 unsigned char* record;
 while((record=Network_PopIncomingMessageAndRecycleSlot(queue,&index))!=0) {
  unsigned type=record[0];
  if(type<0xbc && Network_IsIncomingMessageTypeEnabled(queue,type))
   NetworkDispatchEnabledPendingRecords_UnknownRoleProcedureReferenceRecords[type](index,record,state,resources,connection);
 }
}
