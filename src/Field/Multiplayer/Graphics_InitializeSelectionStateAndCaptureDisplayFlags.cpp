#include <globaldefs.h>
ARM
extern "C" char* _ZN9GameState11GetInstanceEv(...);
extern "C" char* _ZN9GameState20GetUnknownGameObjectEv(...);
extern "C" int GameObject_GetMovementInputEnabled(...);
extern "C" void LinkedQueue_InitializeNodeStatus(...);
extern "C" void memset(...);
extern "C" void TextLayout_InitializeSelectionPanel(...);
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
// Original: arm9/ov017 @ 0x021AF59C; symbol: Graphics_InitializeSelectionStateAndCaptureDisplayFlags; size: 0xd0.
// Clears selection state/buffers, captures display plane bits, and records object byte252 availability.
extern "C" void Graphics_InitializeSelectionStateAndCaptureDisplayFlags(char* self){LinkedQueue_InitializeNodeStatus(self);B(self,0)=38;B(self,9)=0;B(self,10)=0;B(self,11)=0;memset(self+27,0,4);B(self,31)=0;B(self,32)=0;W(self,40)=0;W(self,48)=0;B(self,37)=0;B(self,38)=0;W(self,52)=0;B(self,39)=0;B(self,44)=0;memset(self+67,0,5);W(self,60)=0;W(self,56)=0;H(self,64)=0;B(self,66)=0;TextLayout_InitializeSelectionPanel(self+72);W(self,0x280)=(*(volatile unsigned*)0x4000000&0x1f00)>>8;char* object=_ZN9GameState20GetUnknownGameObjectEv(_ZN9GameState11GetInstanceEv());int flag;if(object)flag=GameObject_GetMovementInputEnabled(object)!=0;else flag=1;B(self,0x284)=flag;W(self,0x288)=0;B(self,8)=0;}
