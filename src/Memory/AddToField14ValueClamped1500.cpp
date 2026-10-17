// Reviewed original ARM behavior. Types express confirmed access widths only.
#include <Memory/SafeAllocator.h>
struct SignedMode{int mode:3;int rest:29;};struct Counter{unsigned int value:24;unsigned int rest:8;};struct Value11{unsigned int low:18;unsigned int value:11;unsigned int rest:3;};extern "C" unsigned short* ReadWordFieldAtOffset8(char*);extern "C" signed char data_020e7e10[];extern "C" signed char data_020e7e1c[];extern "C" unsigned char data_02114e54[];extern "C" char data_02111654[];extern "C" short data_020e87c0[];int DisableIRQInterrupts();void SetIRQInterruptState(int);
// Original: arm9/main @ 0x020A04C8; symbol: func_020a04c8; size: 0x3C.
extern "C" void AddToField14ValueClamped1500(char* p,unsigned int add){unsigned int value=((Value11*)(p+20))->value+add;if(value>1500)value=1500;((Value11*)(p+20))->value=value;}
