// Reviewed original ARM behavior. Types express confirmed access widths only.
#include <Memory/SafeAllocator.h>
struct SignedMode{int mode:3;int rest:29;};struct Counter{unsigned int value:24;unsigned int rest:8;};struct Value11{unsigned int low:18;unsigned int value:11;unsigned int rest:3;};extern "C" unsigned short* ReadWordFieldAtOffset8(char*);extern "C" signed char data_020e7e10[];extern "C" signed char data_020e7e1c[];extern "C" unsigned char data_02114e54[];extern "C" char data_02111654[];extern "C" short data_020e87c0[];int DisableIRQInterrupts();void SetIRQInterruptState(int);
// Original: arm9/main @ 0x020D6F0C; symbol: func_020d6f0c; size: 0x38.
extern "C" void SafeAllocator_DestroyPresentAllocationAndReset(char* p){if(!((SafeAllocator*)(p+0xa28))->GetSignedAllocator())return;((SafeAllocator*)(p+0xa28))->Destroy();((SafeAllocator*)(p+0xa28))->ResetAllocatorPointer();}
