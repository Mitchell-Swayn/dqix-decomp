// Reviewed original ARM behavior. Types express confirmed access widths only.
#include <Memory/SafeAllocator.h>
struct SignedMode{int mode:3;int rest:29;};struct Counter{unsigned int value:24;unsigned int rest:8;};struct Value11{unsigned int low:18;unsigned int value:11;unsigned int rest:3;};extern "C" unsigned short* ReadWordFieldAtOffset8(char*);extern "C" signed char data_020e7e10[];extern "C" signed char data_020e7e1c[];extern "C" unsigned char data_02114e54[];extern "C" char data_02111654[];extern "C" short data_020e87c0[];int DisableIRQInterrupts();void SetIRQInterruptState(int);
// Original: arm9/main @ 0x0203DFDC; symbol: func_0203dfdc; size: 0x60.
extern "C" int FindChildIndexByHalfwordKeyExcludingFlag8000(char* p,int key){for(int i=0;i<32;++i){char* q=*(char**)(p+12+i*4);if(q && !(*(unsigned int*)q&0x8000)){unsigned short* value=ReadWordFieldAtOffset8(q);if(value && *value==key)return i;}}return -1;}
