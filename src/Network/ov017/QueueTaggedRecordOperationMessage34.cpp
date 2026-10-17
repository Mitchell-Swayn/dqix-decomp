#include <globaldefs.h>
#include <std_library_functions.h>
ARM
extern "C" {void* Object_GetGlobalConnectionState();void* ReadGlobalAt02100044();bool TestInactiveOrPrimaryIndexState(unsigned*);void MoveQueuedRecordAndApplySourceValue(void*,const void*,short);void* RecordArray_ReadGlobalTaggedEntryPointer();char* RecordArray_FindFourEntryTagAndOptionalKeyMatch(char*,int,int);int FindOneOfFourRecordsByTypeAndOptionalWordValue(unsigned char*,int,int);}
struct Payload {unsigned char operation,index;short pad;int key;unsigned char type;char pad2[3];unsigned reserved;};
struct Message {unsigned char tag;Payload payload;};
// Original: arm9/ov017 @ 0x021CEBCC; symbol: func_ov017_021cebcc; size: 0xA4.
extern "C" void QueueTaggedRecordOperationMessage34(int operation,int type,int key){
unsigned char* records=(unsigned char*)RecordArray_ReadGlobalTaggedEntryPointer();void* queue=ReadGlobalAt02100044();
Message message;Payload* payload=&message.payload;message.tag=0x34;payload->operation=operation;payload->key=key;payload->type=type;
if(TestInactiveOrPrimaryIndexState((unsigned*)Object_GetGlobalConnectionState()) && operation==3){
payload->index=FindOneOfFourRecordsByTypeAndOptionalWordValue(records,type,key);
char* found=RecordArray_FindFourEntryTagAndOptionalKeyMatch((char*)records,type,key);
if(found)memcpy(&payload->key,found,8);
}
MoveQueuedRecordAndApplySourceValue(queue,&message,0);
}
