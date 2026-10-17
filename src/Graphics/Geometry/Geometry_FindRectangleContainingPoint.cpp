// Reviewed original ARM behavior. Types express confirmed access widths only.
#include <Memory/SafeAllocator.h>
struct SignedMode{int mode:3;int rest:29;};struct Counter{unsigned int value:24;unsigned int rest:8;};struct Value11{unsigned int low:18;unsigned int value:11;unsigned int rest:3;};extern "C" unsigned short* ReadWordFieldAtOffset8(char*);extern "C" signed char data_020e7e10[];extern "C" signed char data_020e7e1c[];extern "C" unsigned char data_02114e54[];extern "C" char data_02111654[];extern "C" short data_020e87c0[];int DisableIRQInterrupts();void SetIRQInterruptState(int);
// Original: arm9/main @ 0x0205B1AC; symbol: func_0205b1ac; size: 0x60.
extern "C" char* Geometry_FindRectangleContainingPoint(char* p,unsigned int count,int x,int y){for(unsigned char i=0;i<count;p+=12,++i){int left=*(short*)(p+4);if(left<=x && x<left+*(short*)(p+8)){int top=*(short*)(p+6);if(top<=y && y<top+*(short*)(p+10))return p;}}return 0;}
