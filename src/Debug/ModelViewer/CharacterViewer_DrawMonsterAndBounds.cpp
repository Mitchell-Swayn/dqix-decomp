#include <globaldefs.h>
ARM
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
struct Vec{int x,y,z;};extern "C" void _ZN12RenderConfig12SubmitToFifoEv();extern "C" void Graphics_DrawColoredRotatedBoxFromBasePosition(Vec,Vec,int,int);extern "C" void _ZN8Object3D4DrawEb(void*,bool);
// Original: arm9/ov015 @ 0x0218ECD8; symbol: Graphics_DrawScaledObjectAndRefreshDimensions; size: 0xF4.
extern "C" void CharacterViewer_DrawMonsterAndBounds(char* self){if(P(self,16)&&B(P(self,0),0x19e)){Vec position=*(Vec*)(P(self,36)+68);Vec scale;scale.x=H(P(self,16),12)*4;scale.y=H(P(self,16),14);scale.z=scale.x;_ZN12RenderConfig12SubmitToFifoEv();Graphics_DrawColoredRotatedBoxFromBasePosition(position,scale,0,32767);}*(volatile unsigned*)0x04000444=0;_ZN8Object3D4DrawEb(P(self,36),false);_ZN12RenderConfig12SubmitToFifoEv();*(volatile unsigned*)0x04000448=1;H(self,52)=H(self,54)=0;H(self,52)=U(P(P(P(self,36),8),84),40);H(self,54)=U(P(P(P(self,36),8),84),42);}
