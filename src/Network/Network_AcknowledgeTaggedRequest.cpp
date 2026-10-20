#include <globaldefs.h>
ARM
extern "C" void Network_GetConnectionManager();extern "C" int Network_IsClientSession();extern "C" unsigned char* Network_FindTaggedAcknowledgement(void*,unsigned,void*);extern "C" void QueueTaggedRecordOperationMessage34(int,unsigned,void*);
// Original: arm9/main @ 0x020E3A50; symbol: func_020e3a50; size: 0x80.
extern "C" void Network_AcknowledgeTaggedRequest(void* p,unsigned bit,unsigned id,void* context){Network_GetConnectionManager();if(Network_IsClientSession()){QueueTaggedRecordOperationMessage34(1,id&255,context);return;}unsigned char* entry=Network_FindTaggedAcknowledgement(p,id,context);if(!entry)return;if(!(entry[5]&(1u<<bit)))return;entry[6]|=1u<<bit;QueueTaggedRecordOperationMessage34(3,id&255,context);}
