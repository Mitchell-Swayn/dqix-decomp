#include <globaldefs.h>
ARM
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
struct Owner{char pad[0xa0];unsigned char selected:4;unsigned char rest:4;};extern "C" void Window_BindNextCanvasResourceByFormatAndLayer(void*,unsigned,unsigned);extern "C" char* TextContext_GetSharedInstance();extern "C" void* memset(void*,int,unsigned);extern "C" void TextMarkup_ExpandAndWrapText(void*,int,void*,void*,int,int,unsigned);extern "C" void Window_PushTextCanvas(void*,void*,int,int,int,int,int,int);
// Original: arm9/ov023 @ 0x021ED354; symbol: Graphics_InitializeSelectedTextEntryAndScratchBuffer; size: 0xF8.
extern "C" void MenuNotice_CreateDescriptionCanvas(char* self){Window_BindNextCanvasResourceByFormatAndLayer(self+0xc4,((Owner*)self)->selected,3);H(self,0x164)=30;H(self,0x166)=10;H(self,0x168)=1;H(self,0x16a)=13;H(self,0x16c)=7;H(self,0x16e)=8;H(self,0x170)=12;H(self,0x172)=12;B(self,0x17b)=12;B(self,0x175)=1;B(self,0x179)=0;B(self,0x17a)=0;char* text=TextContext_GetSharedInstance();memset(P(self,28),0,2400);TextMarkup_ExpandAndWrapText(text,1,P(P(self,32)+B(self,40)*580,4),P(self,28),227,0,1);Window_PushTextCanvas(self+0xc4,P(self,28),0,0,0,0,0,1);}
