#include <globaldefs.h>
ARM
#pragma optimize_for_size off
extern "C" void func_0205a254(char*,unsigned char,unsigned);
// Original: arm9/main @ 0x0205A330; symbol: func_0205a330; size: 0x40.
extern "C" void ApplyValueToAllHalfwordCountedEntries(char* p,unsigned value){
    for(unsigned short i=0;i<*(unsigned short*)(p+4);++i)func_0205a254(p,(unsigned char)i,value);
}
