#include <globaldefs.h>
ARM
#include <std_library_functions.h>
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
struct HighTwoBits{unsigned char low:6,high:2;};
extern "C" unsigned Crypto_TransformAndSerializeBlockWords(...);
extern "C" unsigned Crypto_InitializeSha1Context(...);
extern "C" unsigned VectorizedMemset(...);
extern "C" unsigned Crypto_UpdateSha1Context(...);
extern "C" unsigned char Ssl_ComputeFinishedMd5_TextSRVR[];
extern "C" unsigned char Ssl_ComputeFinishedMd5_TextCLNT[];
// Original: arm9/ov031 @ 0x02209234; symbol: HashModeTaggedStateWithSha1Pads.
extern "C" void Ssl_ComputeFinishedSha1(unsigned char* p,void* output,unsigned mode){unsigned char pad[40];if(B(p,0x454)^mode)Crypto_UpdateSha1Context(p+0x2ec,Ssl_ComputeFinishedMd5_TextSRVR,4);else Crypto_UpdateSha1Context(p+0x2ec,Ssl_ComputeFinishedMd5_TextCLNT,4);Crypto_UpdateSha1Context(p+0x2ec,p,48);VectorizedMemset(pad,0x36,40);Crypto_UpdateSha1Context(p+0x2ec,pad,40);Crypto_TransformAndSerializeBlockWords(p+0x2ec,output);Crypto_InitializeSha1Context(p+0x2ec);Crypto_UpdateSha1Context(p+0x2ec,p,48);VectorizedMemset(pad,0x5c,40);Crypto_UpdateSha1Context(p+0x2ec,pad,40);Crypto_UpdateSha1Context(p+0x2ec,output,20);Crypto_TransformAndSerializeBlockWords(p+0x2ec,output);}
