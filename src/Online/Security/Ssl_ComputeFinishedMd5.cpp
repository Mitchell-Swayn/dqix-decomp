#include <globaldefs.h>
ARM
#include <std_library_functions.h>
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
struct HighTwoBits{unsigned char low:6,high:2;};
extern "C" unsigned Ssl_InitializeMd5Context(...);
extern "C" unsigned System_ExpandEncodedBufferHeaderAndPayload(...);
extern "C" unsigned Util_Update64ByteBlockHash(...);
extern "C" unsigned VectorizedMemset(...);
extern "C" unsigned char Ssl_ComputeFinishedMd5_TextSRVR[];
extern "C" unsigned char Ssl_ComputeFinishedMd5_TextCLNT[];
// Original: arm9/ov031 @ 0x02209158; symbol: HashModeTaggedStateWithInnerAndOuterPads.
extern "C" void Ssl_ComputeFinishedMd5(unsigned char* p,void* output,unsigned mode){unsigned char pad[48];if(B(p,0x454)^mode)Util_Update64ByteBlockHash(p+0x3a4,Ssl_ComputeFinishedMd5_TextSRVR,4);else Util_Update64ByteBlockHash(p+0x3a4,Ssl_ComputeFinishedMd5_TextCLNT,4);Util_Update64ByteBlockHash(p+0x3a4,p,48);VectorizedMemset(pad,0x36,48);Util_Update64ByteBlockHash(p+0x3a4,pad,48);System_ExpandEncodedBufferHeaderAndPayload(p+0x3a4,output);Ssl_InitializeMd5Context(p+0x3a4);Util_Update64ByteBlockHash(p+0x3a4,p,48);VectorizedMemset(pad,0x5c,48);Util_Update64ByteBlockHash(p+0x3a4,pad,48);Util_Update64ByteBlockHash(p+0x3a4,output,16);System_ExpandEncodedBufferHeaderAndPayload(p+0x3a4,output);}
