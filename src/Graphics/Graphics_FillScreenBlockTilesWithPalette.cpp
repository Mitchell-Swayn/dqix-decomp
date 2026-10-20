#include <globaldefs.h>
ARM
extern "C" void Tilemap_FillSequentialTilesWithPalette(unsigned short*,int,int,int,unsigned,unsigned);
// Original: arm9/main @ 0x020B1F48; symbol: func_020b1f48; size: 0xB0.
extern "C" void Graphics_FillScreenBlockTilesWithPalette(unsigned short* map,int width,int height,int x,int y,int stride,unsigned tile,unsigned palette) {
if(stride<=32) {
Tilemap_FillSequentialTilesWithPalette(map+(stride*y+x),width,height,stride,tile,palette);
return;
}
int right=x+width;
int bottom=y+height;
unsigned short color=palette<<12;
if(y<bottom) do {
int row=y<32?y:y+32;
int col=x;
unsigned short* dst=map+row*32;
if(col<right) do {
int offset=col<32?col:col+0x3e0;
dst[offset]=tile|color;
++col;
++tile;
} while(col<right);
++y;
} while(y<bottom);
}
