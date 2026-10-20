#include <globaldefs.h>
#include <std_library_functions.h>
ARM
extern "C" {void* Network_GetConnectionManager();void* Network_GetCommandRecordPool();bool Network_IsParentOrOffline(unsigned*);void Network_QueueOutgoingRecord(void*,const void*,short);void* Network_GetTaggedAcknowledgementTable();char* Network_FindTaggedAcknowledgement(char*,int,int);int Network_FindTaggedAcknowledgementIndex(unsigned char*,int,int);}
struct Payload {unsigned char operation,index;short pad;int key;unsigned char type;char pad2[3];unsigned reserved;};
struct Message {unsigned char tag;Payload payload;};
// Original: arm9/ov017 @ 0x021CEBCC; symbol: func_ov017_021cebcc; size: 0xA4.
extern "C" void QueueTaggedRecordOperationMessage34(int operation,int type,int key){
unsigned char* records=(unsigned char*)Network_GetTaggedAcknowledgementTable();void* queue=Network_GetCommandRecordPool();
Message message;Payload* payload=&message.payload;message.tag=0x34;payload->operation=operation;payload->key=key;payload->type=type;
if(Network_IsParentOrOffline((unsigned*)Network_GetConnectionManager()) && operation==3){
payload->index=Network_FindTaggedAcknowledgementIndex(records,type,key);
char* found=Network_FindTaggedAcknowledgement((char*)records,type,key);
if(found)memcpy(&payload->key,found,8);
}
Network_QueueOutgoingRecord(queue,&message,0);
}
