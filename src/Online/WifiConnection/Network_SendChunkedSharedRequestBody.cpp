#include <globaldefs.h>
#include <System/Memory.h>
ARM
// Original data: arm9/ov031 @ 0x224e580; symbol: data_ov031_0224e580.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char* StoreReadySharedValue_UnknownRoleZeroInitializedStorage;
extern "C" void YssdCommand_RecordTransferSizeReply();
extern "C" int StoreReadySharedValue(void*);
extern "C" void YssdCommand_WaitForReplyCompletion();
extern "C" void YssdCommand_ClearReplyHandler();
extern "C" int System_CompareWordToGlobalResult(const unsigned*);
#define F(T,p,o) (*(T*)((char*)(p)+(o)))
#define REQUEST F(char*,StoreReadySharedValue_UnknownRoleZeroInitializedStorage,0x24)
struct Packet {unsigned length,signature,kind,continuation,total;char payload[1024];};
// Original: arm9/ov031 @ 0x0220F8A8; symbol: func_ov031_0220f8a8; size: 0x174.
// Sends a request body in at-most-1024-byte YSSD packets and verifies completion size.
extern "C" void Network_SendChunkedSharedRequestBody(){
char buffer[0x414];Packet* packet=(Packet*)buffer;char* source;unsigned sent;
sent=F(unsigned,REQUEST,0x14);source=F(char*,REQUEST,0xc);
if(sent>1024)sent=1024;
packet->length=sent+20;packet->signature=0x44535359;packet->kind=0xcd;
packet->total=F(unsigned,REQUEST,0x14);packet->continuation=F(unsigned,REQUEST,4);
MI_CpuCopy8(source,packet->payload,sent);
if(StoreReadySharedValue((void*)YssdCommand_RecordTransferSizeReply) && System_CompareWordToGlobalResult((unsigned*)buffer)){
int last=1;
if(sent<F(unsigned,REQUEST,0x14)){do{
unsigned amount=F(unsigned,REQUEST,0x14)-sent;last=1;
if(amount>1024){amount=1024;last=0;}
packet->signature=0x44535359;packet->kind=0xcf;packet->length=amount+20;packet->continuation=last?0:1;
packet->total=amount;MI_CpuCopy8(source+sent,packet->payload,amount);
if(!System_CompareWordToGlobalResult((unsigned*)buffer))break;
sent+=amount;F(unsigned,REQUEST,0x18)=sent;
}while(sent<F(unsigned,REQUEST,0x14));}
if(last){YssdCommand_WaitForReplyCompletion();if(sent!=F(unsigned,REQUEST,0x24))F(unsigned,REQUEST,0x20)=0;}
}
YssdCommand_ClearReplyHandler();
}
