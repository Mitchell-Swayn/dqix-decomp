#include <globaldefs.h>
#include <std_library_functions.h>
ARM
struct Overlay8SmallRecord;
extern "C" void Text_AppendSelectedPackedRecord(unsigned char*,char*,int,Overlay8SmallRecord*);
extern "C" void Window_PushTextCanvas(void*,void*,int,int,int,int,int,int);
#define H(o) (*(short*)(self+(o)))
#define B(o) (*(unsigned char*)(self+(o)))
// Original: arm9/ov008 @ 0x0218712C; symbol: func_ov008_0218712c; size: 0x14C.
// Configures two text passes with distinct geometry and packed-record indices.
extern "C" void Text_ConfigureAndAppendTwoPackedRecordPasses(unsigned char* self,Overlay8SmallRecord* fallback) {
 H(0x1d0)=5;H(0x1d2)=2;H(0x1d4)=7;H(0x1d6)=7;
 H(0x1d8)=2;H(0x1da)=4;H(0x1dc)=10;H(0x1de)=16;
 B(0x1e7)=10;B(0x1e1)=1;B(0x1e5)=1;B(0x1e6)=1;
 memset(*(void**)(self+0xb8),0,0x960);
 Text_AppendSelectedPackedRecord(self,*(char**)(self+0xb8),0,fallback);
 Window_PushTextCanvas(self+0x130,*(void**)(self+0xb8),0,0,0,0,0,0);
 H(0x1d0)=5;H(0x1d2)=2;H(0x1d4)=7;H(0x1d6)=12;
 H(0x1d8)=2;H(0x1da)=4;H(0x1dc)=10;H(0x1de)=16;
 B(0x1e7)=10;B(0x1e1)=2;B(0x1e5)=1;B(0x1e6)=1;
 memset(*(void**)(self+0xb8),0,0x960);
 Text_AppendSelectedPackedRecord(self,*(char**)(self+0xb8),1,fallback);
 Window_PushTextCanvas(self+0x130,*(void**)(self+0xb8),0,0,0,0,0,0);
}
