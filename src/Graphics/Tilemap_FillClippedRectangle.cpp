#pragma opt_unpromotetypes on
#include <globaldefs.h>
struct TilemapOwner { unsigned int field0[5]; unsigned short* tiles; };
// Fills a tilemap rectangle after clipping against 32 columns and 25 rows.
// Original: arm9/main @ 0x0204BC74; symbol: func_0204bc74; size: 0x108.
extern "C" void Tilemap_FillClippedRectangle(TilemapOwner* owner, unsigned int tile, short x, short y, short width, short height, unsigned int palette)
{
 unsigned short* map=owner->tiles;
 if (!map) return;
 int right, bottom;
 if ((right=x+width)<=0 || (bottom=y+height)<=0) return;
 if (x>=32 || y>=25) return;
 if (x<0) { width+=x; x=0; }
 else if(right>=32) width=32-x;
 if (y<0) { height+=y; y=0; }
 else if(bottom>=25) height=25-y;
 map+=y*32;
 map+=x;
 if(palette!=0xffff) palette=(unsigned short)(palette<<12); else palette=0;
 tile=(unsigned short)(tile&0xfff);
 tile=palette|tile;
 for(short row=0;row<height;row++) {
  for(short col=0;col<width;col++) map[col]=tile;
  map+=32;
 }
}
