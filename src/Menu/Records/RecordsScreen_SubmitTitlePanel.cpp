#include <globaldefs.h>
ARM
extern "C" {void* memset(void*,int,unsigned);void Text_AppendSelectedTitleAndPanelFormat(void*,void*,int);void Window_PushTextCanvas(void*,void*,int,int,int,int,int,int);}
// Original: arm9/ov008 @ 0x02187664; symbol: InitializeFormattedPanelBuffer; size: 0xa4.
// Initializes panel dimensions/flags and formats cleared960-byte buffer before submission.
extern "C" void RecordsScreen_SubmitTitlePanel(unsigned char* self,int mode){*(unsigned short*)(self+0x1d0)=30;*(unsigned short*)(self+0x1d2)=3;*(unsigned short*)(self+0x1d4)=2;*(unsigned short*)(self+0x1d6)=0;*(unsigned short*)(self+0x1d8)=1;*(unsigned short*)(self+0x1da)=2;*(unsigned short*)(self+0x1dc)=10;*(unsigned short*)(self+0x1de)=10;self[0x1e7]=10;self[0x1e1]=0;self[0x1e5]=1;self[0x1e6]=1;memset(*(void**)(self+0xb8),0,0x960);Text_AppendSelectedTitleAndPanelFormat(self,*(void**)(self+0xb8),mode);Window_PushTextCanvas(self+0x130,*(void**)(self+0xb8),0,0,0,0,0,0);}
