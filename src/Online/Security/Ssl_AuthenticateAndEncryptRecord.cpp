#include <globaldefs.h>
#include <System/Memory.h>
ARM
#pragma force_active on
struct HashState {unsigned state[4];unsigned low,high;unsigned char buffer[64];};
struct Sha1Context { unsigned state[5], highBits, lowBits; unsigned char buffer[64]; };
struct BytePermutationState {unsigned char first,second,permutation[256];};
extern "C" void Ssl_InitializeMd5Context(unsigned*);
extern "C" void Util_Update64ByteBlockHash(HashState*,const unsigned char*,unsigned);
extern "C" void System_ExpandEncodedBufferHeaderAndPayload(void*,void*);
extern "C" void Crypto_InitializeSha1Context(unsigned*);
extern "C" void Crypto_UpdateSha1Context(Sha1Context*,const unsigned char*,unsigned);
extern "C" void Crypto_TransformAndSerializeBlockWords(unsigned char*,unsigned char*);
extern "C" void ApplyBytePermutationXorStream(BytePermutationState*,unsigned char*,int);
extern "C" void Util_IncrementBigEndian64(unsigned char*);
// Original: arm9/ov031 @ 0x0220963C; symbol: func_ov031_0220963c; size: 0x204.
// Appends the selected SSL3 MAC, encrypts the payload in place, and advances the write sequence.
// HashState, Sha1Context and BytePermutationState match their owning helper definitions.
extern "C" int Ssl_AuthenticateAndEncryptRecord(void* object,void* buffer)
{
 unsigned char* state=(unsigned char*)object;
 unsigned char* record=(unsigned char*)buffer;
 unsigned char pad[48];
 unsigned char* data=record+5;
 int length=(record[3]<<8)+record[4];
 switch(*(unsigned short*)(state+0x32)){
 case 4:
  Ssl_InitializeMd5Context((unsigned*)(state+0x3fc));
  Util_Update64ByteBlockHash((HashState*)(state+0x3fc),*(unsigned char**)(state+0xbc),16);
  VectorizedMemset(pad,0x36,48);
  Util_Update64ByteBlockHash((HashState*)(state+0x3fc),pad,48);
  Util_Update64ByteBlockHash((HashState*)(state+0x3fc),state+0x1cc,8);
  Util_Update64ByteBlockHash((HashState*)(state+0x3fc),record,1);
  Util_Update64ByteBlockHash((HashState*)(state+0x3fc),record+3,length+2);
  System_ExpandEncodedBufferHeaderAndPayload(state+0x3fc,data+length);
  Ssl_InitializeMd5Context((unsigned*)(state+0x3fc));
  Util_Update64ByteBlockHash((HashState*)(state+0x3fc),*(unsigned char**)(state+0xbc),16);
  VectorizedMemset(pad,0x5c,48);
  Util_Update64ByteBlockHash((HashState*)(state+0x3fc),pad,48);
  Util_Update64ByteBlockHash((HashState*)(state+0x3fc),data+length,16);
  System_ExpandEncodedBufferHeaderAndPayload(state+0x3fc,data+length);
  length+=16;
  break;
 case 5:
  Crypto_InitializeSha1Context((unsigned*)(state+0x348));
  Crypto_UpdateSha1Context((Sha1Context*)(state+0x348),*(unsigned char**)(state+0xbc),20);
  VectorizedMemset(pad,0x36,40);
  Crypto_UpdateSha1Context((Sha1Context*)(state+0x348),pad,40);
  Crypto_UpdateSha1Context((Sha1Context*)(state+0x348),state+0x1cc,8);
  Crypto_UpdateSha1Context((Sha1Context*)(state+0x348),record,1);
  Crypto_UpdateSha1Context((Sha1Context*)(state+0x348),record+3,length+2);
  Crypto_TransformAndSerializeBlockWords(state+0x348,data+length);
  Crypto_InitializeSha1Context((unsigned*)(state+0x348));
  Crypto_UpdateSha1Context((Sha1Context*)(state+0x348),*(unsigned char**)(state+0xbc),20);
  VectorizedMemset(pad,0x5c,40);
  Crypto_UpdateSha1Context((Sha1Context*)(state+0x348),pad,40);
  Crypto_UpdateSha1Context((Sha1Context*)(state+0x348),data+length,20);
  Crypto_TransformAndSerializeBlockWords(state+0x348,data+length);
  length+=20;
  break;
 }
 record[3]=length>>8;
 record[4]=length;
 ApplyBytePermutationXorStream((BytePermutationState*)(state+0xc8),record+5,length);
 Util_IncrementBigEndian64(state+0x1d4);
 return length+5;
}
