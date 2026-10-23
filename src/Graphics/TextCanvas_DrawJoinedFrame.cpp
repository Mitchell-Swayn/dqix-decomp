#include <globaldefs.h>
struct TextCanvasPixels {unsigned char unknown0[8];unsigned char* pixels;unsigned char unknownC[0x9c];short tileWidth,tileHeight;};
extern "C" int TextCanvas_ClassifyOverlappingCorner(void*,int);
extern "C" char* TextLayout_GetThirtyTwoByteFontEntry(int);
extern "C" void TextCanvas_BlitMasked4bppPixels(TextCanvasPixels*,const unsigned char*,short,short,short,short,unsigned char,unsigned char);
// Chooses join-aware corner glyphs and repeats edge glyphs around the canvas.
// Four optional signed-byte insets move the matching outer frame edges.
// A shared integer edge coordinate narrows only at the signed-short blit API;
// shared short dimensions and counters preserve the original field snapshots.
// Original: arm9/main @ 0x0204ECB4; symbol: func_0204ecb4; size: 0x438.
extern "C" void TextCanvas_DrawJoinedFrame(void* canvas,int unusedX,int unusedY,int width,short height,const signed char* margins){
 TextCanvasPixels* p=(TextCanvasPixels*)canvas;if(width<0||height<0)return;
 int position;short i,cw,ch; int top=0,bottom=0,left=0,right=0;if(margins){top=margins[0];bottom=margins[1];left=margins[2];right=margins[3];}
 {
 int kind=TextCanvas_ClassifyOverlappingCorner(canvas,1);int id=0;if(kind==1)id=8;else if(kind==2)id=12;
 char* pixels=TextLayout_GetThirtyTwoByteFontEntry(id);if(pixels)TextCanvas_BlitMasked4bppPixels(p,(const unsigned char*)pixels,(short)left,(short)top,8,8,240,15);
 }
 {char* pixels=TextLayout_GetThirtyTwoByteFontEntry(1);if(pixels){for(i=1,position=top;i<p->tileWidth-1;++i)TextCanvas_BlitMasked4bppPixels(p,(const unsigned char*)pixels,(short)(i*8),position,8,8,240,15);}}
 {
 cw=p->tileWidth;int kind=TextCanvas_ClassifyOverlappingCorner(canvas,2);int id=2;if(kind==3)id=9;else if(kind==2)id=13;
 char* pixels=TextLayout_GetThirtyTwoByteFontEntry(id);if(pixels)TextCanvas_BlitMasked4bppPixels(p,(const unsigned char*)pixels,(short)((short)((short)(cw-1)*8)-right),(short)top,8,8,240,15);
 }
 {char* pixels=TextLayout_GetThirtyTwoByteFontEntry(3);if(pixels){for(i=1,position=left;i<p->tileHeight-1;++i)TextCanvas_BlitMasked4bppPixels(p,(const unsigned char*)pixels,position,(short)(i*8),8,8,240,15);}}
 {char* pixels=TextLayout_GetThirtyTwoByteFontEntry(4);short pos=(short)((short)(p->tileWidth-1)*8);if(pixels){for(i=1,position=pos-right;i<p->tileHeight-1;++i)TextCanvas_BlitMasked4bppPixels(p,(const unsigned char*)pixels,position,(short)(i*8),8,8,240,15);}}
 {
 ch=p->tileHeight;int kind=TextCanvas_ClassifyOverlappingCorner(canvas,4);int id=5;if(kind==1)id=10;else if(kind==4)id=14;
 char* pixels=TextLayout_GetThirtyTwoByteFontEntry(id);if(pixels)TextCanvas_BlitMasked4bppPixels(p,(const unsigned char*)pixels,(short)left,(short)((short)((short)(ch-1)*8)-bottom),8,8,240,15);
 }
 {char* pixels=TextLayout_GetThirtyTwoByteFontEntry(6);short pos=(short)((short)(p->tileHeight-1)*8);if(pixels){for(i=1,position=pos-bottom;i<p->tileWidth-1;++i)TextCanvas_BlitMasked4bppPixels(p,(const unsigned char*)pixels,(short)(i*8),position,8,8,240,15);}}
 {
 cw=p->tileWidth;ch=p->tileHeight;int kind=TextCanvas_ClassifyOverlappingCorner(canvas,8);int id=7;if(kind==3)id=11;else if(kind==4)id=15;
 char* pixels=TextLayout_GetThirtyTwoByteFontEntry(id);if(pixels)TextCanvas_BlitMasked4bppPixels(p,(const unsigned char*)pixels,(short)((short)((short)(cw-1)*8)-right),(short)((short)((short)(ch-1)*8)-bottom),8,8,240,15);
 }
}
