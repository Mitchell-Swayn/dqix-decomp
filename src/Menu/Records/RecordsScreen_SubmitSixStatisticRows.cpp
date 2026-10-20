#include <globaldefs.h>
ARM
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
extern "C" void* memset(void*,int,unsigned);
extern "C" void Text_AppendSixClampedStatisticRows(char*,char*,unsigned*);
extern "C" void Window_PushTextCanvas(void*,void*,int,int,int,int,int,int);
// Original: arm9/ov008 @ 0x02187A70; symbol: ConfigureAndSubmitSixStatisticRows; size: 0xb0.
// Configures row geometry, clears text buffer, appends clamped statistics and submits the text view.
extern "C" void RecordsScreen_SubmitSixStatisticRows(char* p,unsigned* source){
 H(p,0x1d0)=18;H(p,0x1d2)=11;H(p,0x1d4)=13;H(p,0x1d6)=3;H(p,0x1d8)=2;H(p,0x1da)=1;H(p,0x1dc)=10;H(p,0x1de)=15;
 B(p,0x1e7)=10;B(p,0x1e1)=3;B(p,0x1e5)=1;B(p,0x1e6)=1;memset((void*)U(p,0xb8),0,0x960);Text_AppendSixClampedStatisticRows(p,(char*)U(p,0xb8),source);Window_PushTextCanvas(p+0x130,(void*)U(p,0xb8),0,0,0,0,0,0);
}
