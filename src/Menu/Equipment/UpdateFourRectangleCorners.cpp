#include <globaldefs.h>
ARM
struct State;
extern "C" void ZoneContainerRenderPart_DrawFrameWithObjectTransform(void*,int,int);
extern "C" int Sprite_DrawSelectedAnimationCell(State*,int,int);
// Original: arm9/ov005 @ 0x021537BC; symbol: func_ov005_021537bc; size: 0x140.
// Aligns rectangle corners to fixed-point pixels and updates one of three corner representations.
extern "C" void UpdateFourRectangleCorners(char* p,int mode,unsigned short value){
 if(!*(void**)p)return;
 int x=*(int*)(p+0x28)&~0xfff;
 int y=*(int*)(p+0x2c)&~0xfff;
 int right=(*(int*)(p+0x28)+*(int*)(p+0x30)-*(int*)(p+4))&~0xfff;
 int bottom=(*(int*)(p+0x2c)+*(int*)(p+0x34)-*(int*)(p+4))&~0xfff;
 int corners[4][2];
 corners[0][0]=x;corners[0][1]=y;
 corners[1][0]=right;corners[3][0]=right;corners[1][1]=y;
 corners[2][0]=x;corners[2][1]=bottom;
 corners[3][1]=bottom;
 for(int i=0;i<4;i++){
  int cx=corners[i][0],cy=corners[i][1];
  switch(mode){
   case 0:{
    volatile unsigned* port=(volatile unsigned*)0x04000444;
    *port=0;
    int z=*(int*)(p+0x38);
    port[11]=cx;port[11]=cy;port[11]=z;
    *(unsigned short*)(*(char**)p+i*0x88+0x80)=value;
    ZoneContainerRenderPart_DrawFrameWithObjectTransform(*(char**)p+i*0x88,0,1);
    port[1]=1;
    break;
   }
   case 1:Sprite_DrawSelectedAnimationCell((State*)(*(char**)p+i*0x70),cx>>12,cy>>12);break;
   case 2:{char* corner=*(char**)p+i*0x28;*(int*)(corner+0x14)=cx;*(int*)(corner+0x18)=cy;break;}
  }
 }
}
