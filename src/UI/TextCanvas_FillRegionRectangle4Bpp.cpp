#include <globaldefs.h>
ARM
extern "C" char* Geometry_FindRectangleContainingPoint(char*,unsigned,int,int);
struct Canvas { unsigned char* pixels; char* rectangles; unsigned char count; };
// Original: arm9/main @ 0x0205B734; symbol: TextCanvas_FillRegionRectangle4Bpp; size: 0x15C.
// Fills the requested rectangle in a rectangle-mapped tiled four-bit canvas, preserving adjacent pixel nibbles.
extern "C" void TextCanvas_FillRegionRectangle4Bpp(Canvas* canvas,short startX,short startY,short endX,short endY,unsigned char color) {
 unsigned char count;
 char* rectangles;
 unsigned char* pixels=canvas->pixels;
 if(!pixels || !(rectangles=canvas->rectangles))return;
 count=canvas->count;
 unsigned char high;
 unsigned char low=color&15;
 high=low<<4;
 short width=endX-startX,height=endY-startY;
 short x;
 for(short row=0;row<height;++startY,++row) {
  x=startX;
  for(short col=0;col<width;++x,++col) {
   char* rect=Geometry_FindRectangleContainingPoint(rectangles,count,x,startY);
   if(rect) {
    unsigned char* base=pixels+*(unsigned*)rect;
    short dx=x-*(short*)(rect+4),dy=startY-*(short*)(rect+6);
    short tileY=dy>>3, tileWidth=*(short*)(rect+8)>>3;
    base+=(tileY*tileWidth+(dx>>3))*32;
    short px=dx&7,py=dy&7;
    int offset=(py<<2)+(px>>1);
    if(dx&1) {base[offset]&=15;base[offset]|=high;}
    else {base[offset]&=240;base[offset]|=low;}
   }
  }
 }
}
