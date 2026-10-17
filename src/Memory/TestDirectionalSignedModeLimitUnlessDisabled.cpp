// Reviewed original ARM behavior. Types express confirmed access widths only.
#include <Memory/SafeAllocator.h>
struct SignedMode{int mode:3;int rest:29;};struct Counter{unsigned int value:24;unsigned int rest:8;};struct Value11{unsigned int low:18;unsigned int value:11;unsigned int rest:3;};extern "C" unsigned short* ReadWordFieldAtOffset8(char*);extern "C" signed char data_020e7e10[];extern "C" signed char data_020e7e1c[];extern "C" unsigned char data_02114e54[];extern "C" char data_02111654[];extern "C" short data_020e87c0[];int DisableIRQInterrupts();void SetIRQInterruptState(int);
// Original: arm9/main @ 0x0208776C; symbol: func_0208776c; size: 0x54.
extern "C" int TestDirectionalSignedModeLimitUnlessDisabled(char* p,int direction){if(*(unsigned int*)(p+20)&1)return 0;if(direction==0){int v=((SignedMode*)(p+0x58))->mode;if(v<2)return 1;}else{int v=((SignedMode*)(p+0x58))->mode;if(v>-2)return 1;}return 0;}
