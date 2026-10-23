#include <globaldefs.h>
#include <System/Memory.h>
ARM
#pragma force_active on
#pragma optimization_level 4
#pragma optimize_for_size off
extern "C" int Ssl_AuthenticateAndEncryptRecord(void*,void*);
struct State {char pad[8];unsigned char type;char pad9[0x1f];unsigned current;unsigned short pending,pad2e;unsigned completed,retries;};
extern "C" unsigned Network_SendTwoBuffersWithTimeout(char*,unsigned,char*,unsigned,State*);
// Original data: arm9/ov031 @ 0x0224C994 and 0x0224C9C0; symbols: data_ov031_0224c994, data_ov031_0224c9c0.
// Allocator/release callback slots, zero-filled at load and assigned by stack setup.
// Declarations match Math_ExponentiateHalfwordIntegerWithOptionalModulus.
// Values and references: docs/data-symbols/ov031.md.
extern "C" void* (*SslSendClientHello_UnknownRoleZeroInitializedStorage)(unsigned);
extern "C" void (*SslSendClientHello_UnknownRoleZeroInitializedStorage_Variant2)(void*);
// Original: arm9/ov031 @ 0x0220A87C; symbol: func_ov031_0220a87c; size: 0x134.
// Splits two application spans into bounded SSL records and returns bytes sent.
// State matches the owning Network_SendTwoBuffersWithTimeout definition.
// Span advancement uses the original 32-bit address arithmetic, including empty null spans.
extern "C" unsigned Ssl_SendApplicationDataBuffers(char* first,unsigned firstSize,char* second,unsigned secondSize,State* socket)
{
 unsigned char* packet;
 unsigned char* state=*(unsigned char**)((unsigned char*)socket+12);
 unsigned total=0;
 int remaining=firstSize+secondSize;
 int amount;
 int count;
 do{
  count=remaining>0xb4f?0xb4f:remaining;
  packet=(unsigned char*)SslSendClientHello_UnknownRoleZeroInitializedStorage(count+25);
  if(!packet)break;
  amount=firstSize>=(unsigned)count?count:firstSize;
  unsigned fromSecond=count-amount;
  MI_CpuCopy8(first,packet+5,amount);
  first=(char*)((unsigned)first+amount);
  firstSize-=amount;
  MI_CpuCopy8(second,packet+5+amount,fromSecond);
  packet[0]=23;packet[1]=3;packet[2]=0;
  packet[3]=count>>8;packet[4]=count;
  second=(char*)((unsigned)second+fromSecond);
  amount=Ssl_AuthenticateAndEncryptRecord(state,packet);
  unsigned sent=Network_SendTwoBuffersWithTimeout((char*)packet,amount,0,0,socket);
  if(sent<(unsigned)amount)count=0;
  SslSendClientHello_UnknownRoleZeroInitializedStorage_Variant2(packet);
  total+=count;
  remaining-=count;
 }while(remaining&&count);
 return total;
}
