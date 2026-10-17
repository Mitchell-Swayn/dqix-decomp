// Reviewed original ARM behavior. Types express confirmed access widths only.
#include <Memory/SafeAllocator.h>
struct SignedMode{int mode:3;int rest:29;};struct Counter{unsigned int value:24;unsigned int rest:8;};struct Value11{unsigned int low:18;unsigned int value:11;unsigned int rest:3;};extern "C" unsigned short* ReadWordFieldAtOffset8(char*);extern "C" signed char data_020e7e10[];extern "C" signed char data_020e7e1c[];extern "C" unsigned char data_02114e54[];extern "C" char data_02111654[];extern "C" short data_020e87c0[];int DisableIRQInterrupts();void SetIRQInterruptState(int);
// Original: arm9/main @ 0x020D857C; symbol: func_020d857c; size: 0x60.
extern "C" int String_TestSecondIsPrefixOfFirst(char* a,char* b){if(!a)return 0;if(!b)return 0;if(a==b)return 1;while(*a && *b && *a==*b){++a;++b;}return *b==0;}
