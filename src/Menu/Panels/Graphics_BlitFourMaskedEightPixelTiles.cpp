#include <globaldefs.h>
ARM
extern "C" void TextCanvas_BlitMasked4bppPixels(void*,void*,int,int,int,int,int,int);
// Original: arm9/ov023 @ 0x021E2030; symbol: func_ov023_021e2030; size: 0x90.
extern "C" void Graphics_BlitFourMaskedEightPixelTiles(void* canvas,int x,int y,unsigned char* pixels){
short yy;
for(int row=0;row<2;row++){
yy=y+row*8;
for(int col=0;col<2;col++){
TextCanvas_BlitMasked4bppPixels(canvas,pixels,(short)(x+col*8),yy,8,8,0xf0,15);
pixels+=32;
}
}
}
