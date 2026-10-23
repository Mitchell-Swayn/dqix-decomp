#include <globaldefs.h>
#include <System/Memory.h>
ARM
#pragma force_active on
#pragma optimization_level 4
#pragma optimize_for_size off
extern "C" void Ssl_FillNonzeroRandomBytes(unsigned char*,int);
extern "C" void Graphics_PackReverseBytePairsIntoHalfwords(unsigned short*,const unsigned char*,int,unsigned);
extern "C" void Math_ExponentiateHalfwordIntegerWithOptionalModulus(unsigned short*,unsigned short*,unsigned short*,int,unsigned short*);
extern "C" int Ssl_ApplyCryptoThreadPriority(void);
extern "C" void System_ChangeContextPriorityForIndex(unsigned);
extern "C" void Util_UpdateObjectHashContexts(void*,unsigned,unsigned);
struct State {char pad[8];unsigned char type;char pad9[0x1f];unsigned current;unsigned short pending,pad2e;unsigned completed,retries;};
extern "C" unsigned Network_SendTwoBuffersWithTimeout(char*,unsigned,char*,unsigned,State*);
// Original data: arm9/ov031 @ 0x02245FA8; symbol: data_ov031_02245fa8.
// Initialized bytes: 15 03 00 00 02 01 29 00; original sends the first seven bytes.
// Opaque fallback storage; this is a non-owning object-representation byte view.
// Logical storage type/extent remains unresolved; owning-type migration remains debt.
// Values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char SslSendRsaClientKeyExchange_UnknownRoleInitializedBytes[];
// Original data: arm9/ov031 @ 0x0224C994 and 0x0224C9C0; symbols: data_ov031_0224c994, data_ov031_0224c9c0.
// Allocator/release callback slots, zero-filled at load and assigned by stack setup.
// Declarations match Math_ExponentiateHalfwordIntegerWithOptionalModulus.
// Values and references: docs/data-symbols/ov031.md.
extern "C" void* (*SslSendClientHello_UnknownRoleZeroInitializedStorage)(unsigned);
extern "C" void (*SslSendClientHello_UnknownRoleZeroInitializedStorage_Variant2)(void*);
// Original: arm9/ov031 @ 0x0220A184; symbol: func_ov031_0220a184; size: 0x2C0.
// Builds a type-two-padded RSA premaster secret, sends ClientKeyExchange and updates handshake hashes.
extern "C" void Ssl_SendRsaClientKeyExchange(void* object)
{
 unsigned char* self=(unsigned char*)object;
 unsigned char* state=*(unsigned char**)(self+12);
 unsigned short* temporary;
 unsigned short* modulus;
 int count;
 unsigned char* encoded;
 int keySize;
 if(state[0x5ac])Network_SendTwoBuffersWithTimeout((char*)SslSendRsaClientKeyExchange_UnknownRoleInitializedBytes,7,0,0,(State*)self);
 state[0]=3;state[1]=0;
 Ssl_FillNonzeroRandomBytes(state+2,46);
 keySize=*(int*)(state+0x594);
 count=(int)((unsigned)keySize*2u)/2;
 encoded=(unsigned char*)SslSendClientHello_UnknownRoleZeroInitializedStorage(keySize);
 if(!encoded){state[0x455]=9;return;}
 encoded[0]=0;encoded[1]=2;
 Ssl_FillNonzeroRandomBytes(encoded+2,keySize-51);
 encoded[keySize-49]=0;
 MI_CpuCopy8(state,encoded+keySize-48,48);
 temporary=(unsigned short*)SslSendClientHello_UnknownRoleZeroInitializedStorage((unsigned)count*8);
 if(!temporary){SslSendClientHello_UnknownRoleZeroInitializedStorage_Variant2(encoded);state[0x455]=9;return;}
 unsigned short* message=temporary+count;
 unsigned short* exponent=message+count;
 modulus=exponent+count;
 Graphics_PackReverseBytePairsIntoHalfwords(message,encoded,keySize,count);
 Graphics_PackReverseBytePairsIntoHalfwords(exponent,state+0x598,*(unsigned*)(state+0x5a0),count);
 Graphics_PackReverseBytePairsIntoHalfwords(modulus,state+0x494,keySize,count);
 int priority=Ssl_ApplyCryptoThreadPriority();
 Math_ExponentiateHalfwordIntegerWithOptionalModulus(temporary,message,exponent,count,modulus);
 System_ChangeContextPriorityForIndex(priority);
 unsigned char* packet=(unsigned char*)SslSendClientHello_UnknownRoleZeroInitializedStorage(keySize+73);
 if(!packet){SslSendClientHello_UnknownRoleZeroInitializedStorage_Variant2(encoded);SslSendClientHello_UnknownRoleZeroInitializedStorage_Variant2(temporary);state[0x455]=9;return;}
 packet[0]=22;
 packet[1]=3;packet[2]=0;
 packet[3]=(keySize+4)>>8;packet[4]=keySize+4;
 packet[5]=16;packet[6]=keySize>>16;packet[7]=keySize>>8;packet[8]=keySize;
 unsigned char* out=packet+9;
 if(keySize&1)*out++=temporary[keySize/2];
 for(int i=keySize/2-1;i>=0;--i){out[0]=temporary[i]>>8;out[1]=temporary[i];out+=2;}
 Network_SendTwoBuffersWithTimeout((char*)packet,keySize+9,0,0,(State*)self);
 Util_UpdateObjectHashContexts(state,(unsigned)(packet+5),keySize+4);
 SslSendClientHello_UnknownRoleZeroInitializedStorage_Variant2(packet);
 SslSendClientHello_UnknownRoleZeroInitializedStorage_Variant2(temporary);
 SslSendClientHello_UnknownRoleZeroInitializedStorage_Variant2(encoded);
}
