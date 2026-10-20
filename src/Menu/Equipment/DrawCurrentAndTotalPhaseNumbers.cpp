#include <globaldefs.h>
ARM
extern "C" unsigned TextContext_GetSharedInstance();
extern "C" void TextLayout_DrawCachedGlyphRun(unsigned,void*,int,int,unsigned,int,int,int,int,int);
// Original: arm9/ov005 @ 0x0215AA44; symbol: func_ov005_0215aa44; size: 0x27C.
// Draws current one-based phase and total phases as centered one/two-digit values.
extern "C" void DrawCurrentAndTotalPhaseNumbers(unsigned char* p){
 unsigned owner=TextContext_GetSharedInstance();
 int phase=*(signed char*)(p+0x3dbd)+1;
 int count=*(unsigned char*)((p+p[0x3dbc])+0x3df4);
 volatile unsigned* port=(volatile unsigned*)0x04000444;
 port[0]=0;port[47]=1;port[11]=0;port[11]=0;port[11]=0xffc01000;

 if(count/10){
  TextLayout_DrawCachedGlyphRun(owner,p+0x3e0c+(count/10)*6,200,158,0x7fff,8,0,0,0,17);
  TextLayout_DrawCachedGlyphRun(owner,p+0x3e0c+(count%10)*6,208,158,0x7fff,8,0,0,0,17);
 }else TextLayout_DrawCachedGlyphRun(owner,p+0x3e0c+count*6,204,158,0x7fff,8,0,0,0,17);
 if(phase/10){
  TextLayout_DrawCachedGlyphRun(owner,p+0x3e0c+(phase/10)*6,168,158,0x7fff,8,0,0,0,17);
  TextLayout_DrawCachedGlyphRun(owner,p+0x3e0c+(phase%10)*6,176,158,0x7fff,8,0,0,0,17);
 }else TextLayout_DrawCachedGlyphRun(owner,p+0x3e0c+phase*6,172,158,0x7fff,8,0,0,0,17);
 *(volatile unsigned*)0x04000504=0;*(volatile unsigned*)0x04000448=1;
}
