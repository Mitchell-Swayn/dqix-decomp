#include <globaldefs.h>
ARM
extern "C" int Window_BindNextCanvasResourceByFormatAndLayer(...);
extern "C" void* memset(...);
extern "C" int MenuNotice_FormatCenteredTitleAndRevealMask(...);
extern "C" int Window_PushTextCanvas(...);
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
struct FourBitIndex {unsigned char index:4;unsigned char other:4;};
// Original: arm9/ov023 @ 0x021ED194; symbol: Graphics_InitializeSelectedRecordAndTextBuffer; size: 0xc0.
// Graphics InitializeSelectedRecordAndTextBuffer from listed field operations and calls.
extern "C" void MenuNotice_CreateTitleCanvas(char* self){Window_BindNextCanvasResourceByFormatAndLayer(self+0xc4,((FourBitIndex*)(self+0xa0))->index,3);H(self,0x164)=20;H(self,0x166)=3;H(self,0x168)=6;H(self,0x16a)=5;H(self,0x16c)=0;H(self,0x16e)=6;H(self,0x170)=12;H(self,0x172)=14;B(self,0x17b)=12;B(self,0x175)=0;B(self,0x179)=1;B(self,0x17a)=1;memset(P(self,0x1c),0,2400);MenuNotice_FormatCenteredTitleAndRevealMask(self,P(self,0x1c));Window_PushTextCanvas(self+0xc4,P(self,0x1c),0,0,0,0,0,1);}
