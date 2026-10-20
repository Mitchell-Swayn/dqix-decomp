#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
extern "C" void Window_BindNextCanvasResourceByFormatAndLayer(void*,int,int);
extern "C" void* memset(void*,int,unsigned);
extern "C" void Church_FormatPartyStatusList(void*,void*,int);
extern "C" void Window_PushTextCanvas(void*,void*,int,int,int,int,int,int);
// Original: arm9/ov003 @ 0x0215B8A0; symbol: Resource_ConfigureFourteenColumnOwnerAndReloadBuffer; size: 0xc4.
extern "C" void Church_CreatePartyStatusWindow(char* self) {
 Window_BindNextCanvasResourceByFormatAndLayer(self+0xf4,0,2);int count=(short)B(self,0x590)*14+31;
 H(self,0x194)=14;H(self,0x196)=count/8;H(self,0x198)=1;H(self,0x19a)=2;H(self,0x19c)=12;H(self,0x19e)=8;H(self,0x1a0)=10;H(self,0x1a2)=14;B(self,0x1a5)=2;B(self,0x1a9)=1;
 memset(P(self,0x7c),0,2400);Church_FormatPartyStatusList(self,P(self,0x7c),0);Window_PushTextCanvas(self+0xf4,P(self,0x7c),0,1,0,0,0,0);
}
