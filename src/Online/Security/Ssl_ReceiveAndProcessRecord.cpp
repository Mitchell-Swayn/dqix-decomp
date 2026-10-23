#include <globaldefs.h>
ARM
#pragma force_active on
#pragma optimization_level 4
#pragma optimize_for_size off
extern "C" unsigned System_WaitForPendingResult(unsigned*,char*);
struct Buffer {char pad[8];unsigned char state;char pad2[0x33];unsigned capacity;char* data;unsigned size;};
extern "C" void ConsumeBufferBytesAndNotify(unsigned,Buffer*);
extern "C" int Network_CopyPendingBufferChunks(char*,int,Buffer*);
extern "C" void Util_UpdateObjectHashContexts(void*,unsigned,unsigned);
// Dispatcher fallback uses two pointers and has no consistent scalar result.
// SSL2 processor fallback uses two pointers and leaves 0/1 in r0; this caller
// ignores that scalar result. Its original return spelling remains uncertain.
// Existing untyped dispatcher caller declarations remain interface debt.
extern "C" void Ssl_DispatchReceivedRecord(void*,void*);
extern "C" int Ssl_ProcessSsl2CompatibleClientHello(void*,void*);
// Original data: arm9/ov031 @ 0x0224C994 and 0x0224C9C0; symbols: data_ov031_0224c994, data_ov031_0224c9c0.
// Allocator/release callback slots, zero-filled at load and assigned by stack setup.
// Declarations match Math_ExponentiateHalfwordIntegerWithOptionalModulus.
// Values and references: docs/data-symbols/ov031.md.
extern "C" void* (*SslSendClientHello_UnknownRoleZeroInitializedStorage)(unsigned);
extern "C" void (*SslSendClientHello_UnknownRoleZeroInitializedStorage_Variant2)(void*);
// Original: arm9/ov031 @ 0x02209B58; symbol: func_ov031_02209b58; size: 0x1a0.
// Receives a TLS record or initial SSL2-compatible ClientHello and returns the current handshake state.
extern "C" int Ssl_ReceiveAndProcessRecord(void* object)
{
 unsigned char* self=(unsigned char*)object;
 unsigned char* state=*(unsigned char**)(self+12);
 unsigned length;
 unsigned char* data;
 do{
  data=(unsigned char*)System_WaitForPendingResult(&length,(char*)self);
  if(!length){state[0x455]=9;return 9;}
 }while(length<5);
 if(data[0]==128){
  if(state[0x454]&&!state[0x455]){
   length=data[1];
   ConsumeBufferBytesAndNotify(2,(Buffer*)self);
   unsigned char* record=(unsigned char*)SslSendClientHello_UnknownRoleZeroInitializedStorage(length);
   if(!record){state[0x455]=9;return 9;}
   if(Network_CopyPendingBufferChunks((char*)record,length,(Buffer*)self)||record[0]!=1)state[0x455]=9;
   else Ssl_ProcessSsl2CompatibleClientHello(state,record+1);
   Util_UpdateObjectHashContexts(state,(unsigned)record,length);
   SslSendClientHello_UnknownRoleZeroInitializedStorage_Variant2(record);
  }else state[0x455]=9;
 }else{
  unsigned high=data[3];
  length=(high<<8)+data[4]+5;
  if(length>0x4805){state[0x455]=9;return 9;}
  unsigned char* record=(unsigned char*)SslSendClientHello_UnknownRoleZeroInitializedStorage(length);
  if(!record){state[0x455]=9;return 9;}
  if(Network_CopyPendingBufferChunks((char*)record,length,(Buffer*)self)){
   SslSendClientHello_UnknownRoleZeroInitializedStorage_Variant2(record);
   state[0x455]=9;return 9;
  }
  Ssl_DispatchReceivedRecord(state,record);
 }
 return state[0x455];
}
