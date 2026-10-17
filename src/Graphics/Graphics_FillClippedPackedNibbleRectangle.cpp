#include <globaldefs.h>
ARM
extern "C" unsigned char* data_020fe9a4;
// Original: arm9/main @ 0x0202920C; symbol: func_0202920c; size: 0xE0.
// Fills a clipped rectangle in a 256x192 packed-nibble buffer (128-byte row pitch).
// Original clipping uses 255-x / 191-y when right/bottom reaches the display bounds.
// Proposed name: Graphics_FillClippedPackedNibbleRectangle; old ABI retained for proof.
extern "C" void Graphics_FillClippedPackedNibbleRectangle(unsigned color,int x,int y,int width,int height){
 int coordinate; unsigned char high; unsigned low; unsigned char* row;
 unsigned char* buffer=data_020fe9a4;

 if(!buffer)return;
 int right=x+width;if(right<0)return;
 int bottom=y+height;if(bottom<0)return;
 if(x>=256 || y>=192)return;
 if(x<0){width=right;x=0;}
 if(x+width>=256)width=255-x;
 if(y<0){height+=y;y=0;}
 if(y+height>=192)height=191-y;
 low=(unsigned char)color; high=(unsigned char)(low<<4);
 row=buffer+y*128+x/2;

 for(int j=0;j<height;++j){
  unsigned char* p=row;coordinate=x;
  for(int i=0;i<width;++i){
   if(coordinate&1){*p=(*p&15)|high;++p;}
   else *p=(*p&240)|low;
   ++coordinate;
  }
  row+=128;
 }
}
