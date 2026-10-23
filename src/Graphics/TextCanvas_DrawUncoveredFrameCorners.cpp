#include <globaldefs.h>
struct TiledPixelSurface {unsigned char reserved0[8];unsigned char* pixels;unsigned char reservedC[0x9c];short widthTiles,heightTiles;};
struct TextCanvasPixels {unsigned char unknown0[8];unsigned char* pixels;unsigned char unknownC[0x9c];short tileWidth,tileHeight;};
extern "C" int TextCanvas_ClassifyOverlappingCorner(void*,int);
extern "C" void Graphics_FillTiled4bppRectangle(TiledPixelSurface*,int,int,int,int,int);
extern "C" char* TextLayout_GetThirtyTwoByteFontEntry(int);
extern "C" void TextCanvas_BlitMasked4bppPixels(TextCanvasPixels*,const unsigned char*,short,short,short,short,unsigned char,unsigned char);
// Clears and draws each of the four frame-corner glyphs whose overlap classifier
// reports no covering region, unless the canvas has its frameless flag set.
// Original: arm9/main @ 0x0204EA5C; symbol: func_0204ea5c; size: 0x258.
extern "C" void TextCanvas_DrawUncoveredFrameCorners(void* canvas){
 TextCanvasPixels* p=(TextCanvasPixels*)canvas;
 if(((unsigned char*)canvas)[0xc5]&16)return;
 if(!TextCanvas_ClassifyOverlappingCorner(canvas,1)){
 Graphics_FillTiled4bppRectangle((TiledPixelSurface*)canvas,0,0,0,8,8);
 char* pixels=TextLayout_GetThirtyTwoByteFontEntry(21);if(pixels)TextCanvas_BlitMasked4bppPixels(p,(const unsigned char*)pixels,0,0,8,8,240,15);
 }
 if(!TextCanvas_ClassifyOverlappingCorner(canvas,2)){
 Graphics_FillTiled4bppRectangle((TiledPixelSurface*)canvas,0,(short)((p->tileWidth-1)*8),0,(short)(p->tileWidth*8),8);
 char* pixels=TextLayout_GetThirtyTwoByteFontEntry(22);if(pixels)TextCanvas_BlitMasked4bppPixels(p,(const unsigned char*)pixels,(short)((p->tileWidth-1)*8),0,8,8,240,15);
 }
 if(!TextCanvas_ClassifyOverlappingCorner(canvas,4)){
 Graphics_FillTiled4bppRectangle((TiledPixelSurface*)canvas,0,0,(short)((p->tileHeight-1)*8),8,(short)(p->tileHeight*8));
 char* pixels=TextLayout_GetThirtyTwoByteFontEntry(24);if(pixels)TextCanvas_BlitMasked4bppPixels(p,(const unsigned char*)pixels,0,(short)((p->tileHeight-1)*8),8,8,240,15);
 }
 if(!TextCanvas_ClassifyOverlappingCorner(canvas,8)){
 Graphics_FillTiled4bppRectangle((TiledPixelSurface*)canvas,0,(short)((p->tileWidth-1)*8),(short)((p->tileHeight-1)*8),(short)(p->tileWidth*8),(short)(p->tileHeight*8));
 char* pixels=TextLayout_GetThirtyTwoByteFontEntry(23);if(pixels)TextCanvas_BlitMasked4bppPixels(p,(const unsigned char*)pixels,(short)((p->tileWidth-1)*8),(short)((p->tileHeight-1)*8),8,8,240,15);
 }
}
