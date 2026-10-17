#include <globaldefs.h>
ARM
extern "C" unsigned int TextLookup_ReadIndexedGlobalWord(unsigned);
extern "C" char* Geometry_FindRectangleContainingPoint(char*,unsigned,int,int);
struct Canvas {unsigned char* pixels;char* rectangles;unsigned char count;};
struct Glyph {unsigned int unknown; signed char width;unsigned char pad;short x;};
struct Font {unsigned int unk;unsigned short width;unsigned char pad[6];unsigned char* pixels;};
// Original: arm9/main @ 0x0205B36C; symbol: func_0205b36c; size: 0x1C4.
extern "C" void Text_BlitMonochromeGlyphToTiledCanvas(Canvas* canvas,Glyph* glyph,short destX,short destY,unsigned char color,unsigned char fontIndex) {
 Font* font=(Font*)TextLookup_ReadIndexedGlobalWord(fontIndex);
 int sourceX=glyph->x;
 unsigned char high=color<<4;
 unsigned char low=color&15;
 int rowBytes=font->width>>3;
 signed char startBit=7-(sourceX&7);
 unsigned char count=canvas->count;
 char* rects=canvas->rectangles;
 for(int row=0;row<12;++row) {
  short y=destY+row;
  signed char bit=startBit;
  unsigned char* src=font->pixels+rowBytes*row+(sourceX>>3);
  for(int col=0;col<glyph->width;++col) {
   if(*src&(1<<bit)) {
    short x=destX+col;
    char* rect=Geometry_FindRectangleContainingPoint(rects,count,x,y);
    if(rect) {
     unsigned char* base=canvas->pixels+*(unsigned int*)rect;
     int odd=x&1;
     x-=*(short*)(rect+4);
     short ry=y-*(short*)(rect+6);
     short tileX=x>>3;
     short tileY=ry>>3;
     short tilesWide=*(short*)(rect+8)>>3;
     short tile=tileY*tilesWide+tileX;
     base+=tile*32;
     short px=x&7;
     short py=ry&7;
     int offset=(py<<2)+(px>>1);
     if(odd) {base[offset]&=15; base[offset]|=high;}
     else {base[offset]&=240; base[offset]|=low;}
    }
   }
   --bit;
   if(bit<0) {bit=7;++src;}
  }
 }
}
