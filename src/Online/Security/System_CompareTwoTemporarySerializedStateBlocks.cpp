#include <globaldefs.h>
ARM
extern "C" int MI_CpuCopy8(...);
extern "C" int Ssl_ComputeFinishedMd5(...);
extern "C" int RuntimeMemory_CompareByteRanges(...);
extern "C" int Ssl_ComputeFinishedSha1(...);
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
// Original: arm9/ov031 @ 0x02209310; symbol: System_CompareTwoTemporarySerializedStateBlocks; size: 0xc0.
// System CompareTwoTemporarySerializedStateBlocks from listed field operations and calls.
extern "C" void System_CompareTwoTemporarySerializedStateBlocks(char* self,char* expected){char result[20];MI_CpuCopy8(self+0x3a4,self+0x3fc,88);Ssl_ComputeFinishedMd5(self,result,1);MI_CpuCopy8(self+0x3fc,self+0x3a4,88);if(RuntimeMemory_CompareByteRanges(expected,result,16)){B(self,0x455)=9;return;}MI_CpuCopy8(self+0x2ec,self+0x348,92);Ssl_ComputeFinishedSha1(self,result,1);MI_CpuCopy8(self+0x348,self+0x2ec,92);if(RuntimeMemory_CompareByteRanges(expected+16,result,20))B(self,0x455)=9;else B(self,0x455)=6;}
