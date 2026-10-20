#include <globaldefs.h>
ARM
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
extern "C" void BuildAndDispatchYRotationMatrixWhenAngleNonzero(int);extern "C" void ZoneContainerRenderPart_DrawTexturedQuad(void*,void*,int);struct DrawFlags{char pad[132];unsigned char a:1;unsigned char b:1;unsigned char rest:6;};
// Original: arm9/main @ 0x02047448; symbol: Graphics_DrawEnabledFrameEntryWithTransform; size: 0x10C.
extern "C" void Graphics_DrawEnabledFrameEntryWithTransform(char* self,int index,int mode){if(!((DrawFlags*)self)->a)return;if(!((DrawFlags*)self)->b)return;if(H(self,130)<=0)return;char* entry=P(self,8)+index*8;if(!P(entry,4)||!B(entry,2))return;volatile unsigned* fifo=(volatile unsigned*)0x04000444;fifo[0]=0;fifo[31]=0x7fffffff;fifo[32]=0x4210;int x=W(self,28)-(((int)B(entry,0)>>1))*W(self,52);int z=W(self,36),y=W(self,32);fifo[11]=x;fifo[11]=y;fifo[11]=z;BuildAndDispatchYRotationMatrixWhenAngleNonzero(W(self,44));unsigned sx=W(self,52),sz=W(self,60),sy=W(self,56);volatile unsigned* scale=(volatile unsigned*)0x0400046c;*scale=sx;*scale=sy;*scale=sz;char* item=P(entry,4);for(int i=0;i<B(entry,2);i++,item+=8)ZoneContainerRenderPart_DrawTexturedQuad(self,item,mode);*(volatile unsigned*)0x04000448=1;}
