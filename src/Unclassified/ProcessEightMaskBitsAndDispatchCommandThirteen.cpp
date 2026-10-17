#include <globaldefs.h>
ARM
extern "C" void SoundCommand_IncrementIndexedCounter(int);extern "C" void AcquireCommandEntryAndStoreFiveValues(int,int,int,unsigned,int);
// Original: arm9/main @ 0x020D1F0C; symbol: func_020d1f0c; size: 0x64.
extern "C" void ProcessEightMaskBitsAndDispatchCommandThirteen(int a,int b,unsigned mask,int c){int i=0;unsigned v=mask;while(i<8&&v){if(v&1)SoundCommand_IncrementIndexedCounter(i);++i;v>>=1;}AcquireCommandEntryAndStoreFiveValues(13,a,b,mask,c);}
