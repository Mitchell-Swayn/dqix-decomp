#include <globaldefs.h>
ARM
extern "C" {void* Network_GetCommandRecordPool();void Network_QueueOutgoingRecord(void*,const void*,short);}
struct Payload {unsigned value;unsigned short owner,key;unsigned char a,b,index;unsigned reserved;};
struct Message {unsigned char tag;Payload payload;};
struct Entry {unsigned char b,a;unsigned short key;unsigned value;};
struct Source {unsigned char pad;unsigned char unused:6;unsigned char count:2;char pad2[0x4a];Entry entries[1];};
// Original: arm9/ov017 @ 0x021C66E8; symbol: func_ov017_021c66e8; size: 0x9C.
extern "C" void QueueIndexedEntryMessages41(char* owner){
void* queue=Network_GetCommandRecordPool();Message message;message.tag=0x41;
Payload* payload=&message.payload;
payload->owner=*(unsigned short*)(*(char**)(owner+0x8e18)+8);
Source* source=(Source*)(owner+0x81b0);
for(int i=0;i<source->count;i++){
payload->index=i;
payload->key=source->entries[i].key;
payload->a=source->entries[i].a;payload->b=source->entries[i].b;payload->value=source->entries[i].value;
Network_QueueOutgoingRecord(queue,&message,0);
}
}
