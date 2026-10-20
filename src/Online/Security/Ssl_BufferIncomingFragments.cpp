#include <globaldefs.h>
#include <System/Memory.h>
ARM
#pragma force_active on
#pragma optimization_level 4
#pragma optimize_for_size off
extern "C" unsigned System_WaitForPendingResult(unsigned*,char*);
struct Buffer { char pad[8];unsigned char state;char pad2[0x33];unsigned capacity;char* data;unsigned size; };
extern "C" void ConsumeBufferBytesAndNotify(unsigned,Buffer*);
// Fallback dispatcher contract inferred from r0=context, r1=record and unused returns.
// The older int(...) declaration remains separate interface debt; no C owner exists.
extern "C" void Ssl_DispatchReceivedRecord(void*,void*);
// Original data: arm9/ov031 @ 0x0224C994; symbol: data_ov031_0224c994.
// Allocator callback slot, zero-filled at load and assigned by stack setup.
// Declaration matches Math_ExponentiateHalfwordIntegerWithOptionalModulus.
// Values and references: docs/data-symbols/ov031.md.
extern "C" void* (*SslSendClientHello_UnknownRoleZeroInitializedStorage)(unsigned);
#define WORD(p,o) (*(unsigned*)((p)+(o)))
#define POINTER(p,o) (*(unsigned char**)((p)+(o)))
// Original: arm9/ov031 @ 0x0220A6BC; symbol: func_ov031_0220a6bc; size: 0x144.
// Buffers TLS fragments until one complete record is ready, then dispatches and releases its slot.
extern "C" void Ssl_BufferIncomingFragments(void* object)
{
 unsigned char* self=(unsigned char*)object;
 unsigned char* state=POINTER(self,12);
 unsigned length;
 if(!POINTER(state,0x824)){
  if(WORD(self,0x44)<5)return;
  unsigned char* data=(unsigned char*)System_WaitForPendingResult(&length,(char*)self);
  unsigned high=data[3];
  length=(high<<8)+data[4]+5;
  if(length>0x4805){state[0x455]=9;return;}
  POINTER(state,0x824)=(unsigned char*)SslSendClientHello_UnknownRoleZeroInitializedStorage(length);
  if(!POINTER(state,0x824)){state[0x455]=9;return;}
  WORD(state,0x828)=length;
  WORD(state,0x82c)=0;
  state[0x456]=0;
 }else if(!WORD(self,0x44))return;
 unsigned char* data=(unsigned char*)System_WaitForPendingResult(&length,(char*)self);
 unsigned remaining=WORD(state,0x828)-WORD(state,0x82c);
 int complete;
 if(length>=remaining){length=remaining;complete=1;}else complete=0;
 MI_CpuCopy8(data,POINTER(state,0x824)+WORD(state,0x82c),length);
 ConsumeBufferBytesAndNotify(length,(Buffer*)self);
 if(complete){
  Ssl_DispatchReceivedRecord(state,POINTER(state,0x824));
  if(!state[0x456])POINTER(state,0x824)=0;
 }else WORD(state,0x82c)+=length;
}
