#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
extern "C" void __clear(void*,unsigned);extern "C" int TextMarkup_AppendFrameTag(char*,int,int,int,int,int);extern "C" void Window_BindNextCanvasResourceByFormatAndLayer(char*,unsigned,unsigned);extern "C" short Text_AppendTwoLabelsAndReturnEvenTileWidth(void*,void*,int);extern "C" int Window_ReplaceCanvasTextById(void*,unsigned,void*,unsigned,unsigned char);
// Original: arm9/ov003 @ 0x0216fe74; symbol: Text_ConfigureAndCenterTwoLabelReadyRecord; size 0x11c.
extern "C" void Text_ConfigureAndCenterTwoLabelReadyRecord(char* self,int alternate,int unused,int prefix){if(!P(self,60))return;Window_BindNextCanvasResourceByFormatAndLayer(P(self,60),0,1);B(P(self,60),0xb1)=0;char* p=P(self,60);H(p,0xa0)=17;H(p,0xa2)=9;p=P(self,60);H(p,0xa4)=6;H(p,0xa6)=6;p=P(self,60);H(p,0xa8)=12;H(p,0xaa)=14;p=P(self,60);H(p,0xac)=10;H(p,0xae)=16;B(P(self,60),0xb5)=1;char text[512];__clear(text,512);if(prefix!=-1)TextMarkup_AppendFrameTag(text,prefix,8,5,5,5);int width=Text_AppendTwoLabelsAndReturnEvenTileWidth(text,self+0xdc,alternate);p=P(self,60);H(p,0xa4)=(32-width)>>1;H(p,0xa6)=6;p=P(self,60);H(p,0xa0)=width;H(p,0xa2)=9;Window_ReplaceCanvasTextById(P(self,60),0,text,1,0);}
