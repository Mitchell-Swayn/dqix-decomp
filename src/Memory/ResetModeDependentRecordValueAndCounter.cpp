// Reviewed original ARM behavior. Types express confirmed access widths only.
#include <Memory/SafeAllocator.h>
struct SignedMode{int mode:3;int rest:29;};struct Counter{unsigned int value:24;unsigned int rest:8;};struct Value11{unsigned int low:18;unsigned int value:11;unsigned int rest:3;};extern "C" unsigned short* ReadWordFieldAtOffset8(char*);extern "C" signed char data_020e7e10[];extern "C" signed char data_020e7e1c[];extern "C" unsigned char data_02114e54[];extern "C" char data_02111654[];extern "C" short data_020e87c0[];int DisableIRQInterrupts();void SetIRQInterruptState(int);
// Original: arm9/main @ 0x0201FBAC; symbol: func_0201fbac; size: 0x34.
extern "C" void ResetModeDependentRecordValueAndCounter(unsigned char* p){if(p[0]==1 || p[0]==4)p[1]=3;else if(p[0]==2)*(unsigned int*)(p+16)=0x43080000;*(short*)(p+4)=0;}
