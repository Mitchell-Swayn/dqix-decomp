#include <globaldefs.h>
ARM
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
struct Fields{char pad[0xc0];unsigned char index:4;unsigned char rest:4;};
extern "C" void Window_BindNextCanvasResourceByFormatAndLayer(void*,unsigned,unsigned);extern "C" void* memset(void*,int,unsigned);extern "C" const char* ResourceStringTable_GetTextByKey(void*,int);extern "C" int Text_AppendFormatString(char*,const char*);extern "C" void Window_PushTextCanvas(void*,void*,int,int,int,int,int,int);
// Original: arm9/ov023 @ 0x021ED600; symbol: InitializeBoundTextRecordAndFixedLayoutFields; size: 0xCC.
extern "C" void MenuNotice_CreateCompletionCanvas(char* self){Window_BindNextCanvasResourceByFormatAndLayer(self+0xc4,((Fields*)self)->index,3);H(self,0x164)=32;H(self,0x166)=9;H(self,0x168)=0;H(self,0x16a)=15;H(self,0x16c)=10;H(self,0x16e)=10;H(self,0x170)=12;H(self,0x172)=20;B(self,0x17b)=12;B(self,0x175)=2;B(self,0x179)=0;B(self,0x17a)=0;memset(P(self,0x1c),0,0x960);const char* text=ResourceStringTable_GetTextByKey(self+4,1000);Text_AppendFormatString(P(self,0x1c),text);Window_PushTextCanvas(self+0xc4,P(self,0x1c),0,0,0,0,0,1);}
