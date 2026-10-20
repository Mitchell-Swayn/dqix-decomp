struct WindowCanvasOwner;
struct WindowCanvasRecord;
#include <globaldefs.h>
ARM
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
extern "C" void* memset(void*,int,unsigned);extern "C" void Window_PushTextCanvas(void*,void*,int,int,int,int,int,int);extern "C" void Window_BindNextCanvasResourceByFormatAndLayer(void*,unsigned,unsigned);extern "C" void Graphics_AppendFlagAndSignedValueStatusPage(void*,char*,int);extern "C" WindowCanvasRecord* Window_FindActiveCanvasById(WindowCanvasOwner*,unsigned);
// Original: arm9/ov003 @ 0x02169C3C; symbol: InitializeFlagAndValueStatusPageLayout; size: 0xD4.
extern "C" void Bank_OpenTransferAmountWindow(char* self){Window_BindNextCanvasResourceByFormatAndLayer(self+0xe4,0,2);H(self,0x184)=14;H(self,0x186)=7;H(self,0x188)=17;H(self,0x18a)=7;H(self,0x18c)=8;H(self,0x18e)=16;H(self,0x190)=12;H(self,0x192)=14;B(self,0x195)=2;B(self,0x199)=1;B(self,0x4ee)=3;memset(P(self,0x7c),0,0x960);Graphics_AppendFlagAndSignedValueStatusPage(self,P(self,0x7c),0);Window_PushTextCanvas(self+0xe4,P(self,0x7c),0,0,0,0,0,1);char* record=(char*)Window_FindActiveCanvasById((WindowCanvasOwner*)(self+0xe4),2);B(record,0xc6)=0;}
