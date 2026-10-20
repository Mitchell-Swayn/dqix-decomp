#include <globaldefs.h>
ARM
#include <std_library_functions.h>
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
struct SignedThree{signed value:3;unsigned other:29;};
extern "C" unsigned Crypto_TransformAndSerializeBlockWords(...);
extern "C" unsigned Ssl_InitializeMd5Context(...);
extern "C" unsigned Crypto_InitializeSha1Context(...);
extern "C" unsigned System_ExpandEncodedBufferHeaderAndPayload(...);
extern "C" unsigned Util_Update64ByteBlockHash(...);
extern "C" unsigned Resource_FindNamedEntry(...);
extern "C" unsigned Ssl_VerifyCertificateRsaSignature(...);
extern "C" unsigned Crypto_UpdateSha1Context(...);
// Original: arm9/ov031 @ 0x022085a8; symbol: HashSelectedBufferAndReturnCombinedStatus.
extern "C" unsigned Ssl_HashAndVerifyCertificateSignature(unsigned char* p){unsigned status=B(p,0x5af)?0:0x8000;if(U(p,0x45c)==-1U)return status|4;switch(U(p,0x458)){case 3:Ssl_InitializeMd5Context(p+0x3fc);Util_Update64ByteBlockHash(p+0x3fc,U(p,0x460),U(p,0x464)-U(p,0x460));System_ExpandEncodedBufferHeaderAndPayload(p+0x3fc,p+0x468);U(p,0x47c)=16;break;case 4:Crypto_InitializeSha1Context(p+0x348);Crypto_UpdateSha1Context(p+0x348,U(p,0x460),U(p,0x464)-U(p,0x460));Crypto_TransformAndSerializeBlockWords(p+0x348,p+0x468);U(p,0x47c)=20;break;default:return status|3;}unsigned result=Resource_FindNamedEntry(p,p+0x5b0);if(!result)return status|1;return status|Ssl_VerifyCertificateRsaSignature(p,result);}
