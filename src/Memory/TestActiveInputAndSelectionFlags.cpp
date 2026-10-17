// Reviewed original ARM behavior. Types express confirmed access widths only.
#include <Memory/SafeAllocator.h>
struct SignedMode{int mode:3;int rest:29;};struct Counter{unsigned int value:24;unsigned int rest:8;};struct Value11{unsigned int low:18;unsigned int value:11;unsigned int rest:3;};extern "C" unsigned short* ReadWordFieldAtOffset8(char*);extern "C" signed char data_020e7e10[];extern "C" signed char data_020e7e1c[];extern "C" unsigned char data_02114e54[];extern "C" char data_02111654[];extern "C" short data_020e87c0[];int DisableIRQInterrupts();void SetIRQInterruptState(int);
// Original: arm9/main @ 0x0205BD20; symbol: func_0205bd20; size: 0x38.
extern "C" int TestActiveInputAndSelectionFlags(unsigned char* p){int result=0;if(data_02114e54[0x55]){if(p[0x4e]==1){if(p[0x4c])result=1;}}return result;}
