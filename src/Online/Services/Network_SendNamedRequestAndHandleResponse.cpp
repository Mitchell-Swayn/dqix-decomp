#include <globaldefs.h>
#include <System/Memory.h>
ARM
// Original data: arm9/ov031 @ 0x224e588; symbol: data_ov031_0224e588.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" int* YssdClientRunWorker_UnknownRoleZeroInitializedStorage;
extern "C" unsigned Text_CopyBoundedStringAndReturnSourceLength(signed char*,const signed char*,int);
extern "C" unsigned String_CountBytesUntilTerminator(const signed char*);
extern "C" void Overlay_EnsureContextStateTwoUnlessAlreadySet(unsigned,int);
extern "C" void YssdClient_SetWorkerPhase(int);
extern "C" void System_StoreStateAndUnblockContexts(unsigned);
extern "C" int YssdClient_SendLengthPrefixedPacket(unsigned char*);
extern "C" int Network_ReadAndValidateLengthPrefixedPacket(char*);
#define F(T,p,o) (*(T*)((char*)(p)+(o)))
struct RequestPacket {unsigned length,signature,type,status,first,second;signed char text[1020];};
// Original: arm9/ov031 @ 0x02210BEC; symbol: func_ov031_02210bec; size: 0x234.
// Sends a named D3 request, handles CA error status or D4 response and publishes its returned identifier.
extern "C" void Network_SendNamedRequestAndHandleResponse(){
char buffer[0x414];unsigned nameLength;unsigned expected;RequestPacket* packet=(RequestPacket*)buffer;
if(F(unsigned,YssdClientRunWorker_UnknownRoleZeroInitializedStorage,0x40)!=3){System_StoreStateAndUnblockContexts(5);return;}
F(unsigned char,YssdClientRunWorker_UnknownRoleZeroInitializedStorage,0x1b5)=0;
nameLength=String_CountBytesUntilTerminator((signed char*)YssdClientRunWorker_UnknownRoleZeroInitializedStorage+0x89);
expected=nameLength+25;VectorizedMemset(buffer,0,0x414);
packet->length=expected;packet->signature=0x44535359;packet->type=0xd3;packet->status=0;
packet->first=F(unsigned,YssdClientRunWorker_UnknownRoleZeroInitializedStorage,0x28);packet->second=F(unsigned,YssdClientRunWorker_UnknownRoleZeroInitializedStorage,0x2c);
Text_CopyBoundedStringAndReturnSourceLength(packet->text,(signed char*)YssdClientRunWorker_UnknownRoleZeroInitializedStorage+0x89,nameLength+1);
if(expected!=YssdClient_SendLengthPrefixedPacket((unsigned char*)buffer)){System_StoreStateAndUnblockContexts(5);return;}
unsigned received=Network_ReadAndValidateLengthPrefixedPacket(buffer);
if(received<12 || received!=packet->length){System_StoreStateAndUnblockContexts(5);return;}
switch(packet->type){
case 0xca:
switch(packet->status){
case 21:Overlay_EnsureContextStateTwoUnlessAlreadySet(2,-2);break;
case 24:Overlay_EnsureContextStateTwoUnlessAlreadySet(6,-20);break;
case 27:Overlay_EnsureContextStateTwoUnlessAlreadySet(2,-2);break;
case 29:F(unsigned,YssdClientRunWorker_UnknownRoleZeroInitializedStorage,0x40)=0;VectorizedMemset((char*)YssdClientRunWorker_UnknownRoleZeroInitializedStorage+0x44,0,0x174);YssdClient_SetWorkerPhase(5);return;
}
System_StoreStateAndUnblockContexts(5);return;
case 0xd4:
if(F(unsigned,YssdClientRunWorker_UnknownRoleZeroInitializedStorage,0x2c)==0){unsigned value=packet->status;F(unsigned,YssdClientRunWorker_UnknownRoleZeroInitializedStorage,0x2c)=value;typedef void(*Callback)(unsigned);Callback callback=F(Callback,YssdClientRunWorker_UnknownRoleZeroInitializedStorage,0x30);if(callback)callback(value);}
YssdClient_SetWorkerPhase(7);return;
default:Overlay_EnsureContextStateTwoUnlessAlreadySet(2,-40);System_StoreStateAndUnblockContexts(5);return;
}
}
