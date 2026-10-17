// Reviewed original ARM behavior. Types express confirmed access widths only.
#include <Memory/SafeAllocator.h>
struct SignedMode{int mode:3;int rest:29;};struct Counter{unsigned int value:24;unsigned int rest:8;};struct Value11{unsigned int low:18;unsigned int value:11;unsigned int rest:3;};extern "C" unsigned short* ReadWordFieldAtOffset8(char*);extern "C" signed char data_020e7e10[];extern "C" signed char data_020e7e1c[];extern "C" unsigned char data_02114e54[];extern "C" char data_02111654[];extern "C" short data_020e87c0[];int DisableIRQInterrupts();void SetIRQInterruptState(int);
// Original: arm9/main @ 0x0204C654; symbol: func_0204c654; size: 0x30.
extern "C" void SetFourHalfwordArrayElementsForBoundedIndex(char* p,int i,short a,short b,short c,short d){if(i<0)return;if(i>=18)return;char* q=p+i*2;*(short*)(q+12)=a;*(short*)(q+48)=b;*(short*)(q+84)=c;*(short*)(q+120)=d;}
