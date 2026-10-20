#include <globaldefs.h>
ARM
#pragma optimize_for_size off
struct Direction{signed char x,y;};
extern "C" int Font_ComputeLineWidthUntilNewline(void*,int,unsigned,unsigned*);
extern "C" void Text_RenderLineAndAdvanceCursor(unsigned*,int,int,unsigned,unsigned,unsigned*,Direction);
// Original: arm9/main @ 0x020B245C; symbol: func_020b245c; size: 0x168.
extern "C" void Graphics_RenderAlignedTextLinesInDirection(unsigned* self,int x,int y,int width,unsigned value,unsigned flags,unsigned text,Direction direction){
 int px,py,ox,oy,dirY,dirX;
 int step=self[3]+(int)*(signed char*)(*(char**)(self[1])+1);
 dirY=direction.y;dirX=direction.x;
 int dx=step*-dirY,dy=step*dirX;
 unsigned cursor=text;
 if(!text)return;
 ox=0;oy=0;
 do{
  px=x+ox;py=y+oy;
  if(flags&0x800){int length=Font_ComputeLineWidthUntilNewline((void*)self[1],self[2],cursor,0);int offset=width-length;px+=offset*dirX;py+=offset*dirY;}
  else if(flags&0x400){int length=Font_ComputeLineWidthUntilNewline((void*)self[1],self[2],cursor,0);int offset=(width+1)/2-(length+1)/2;px+=offset*dirX;py+=offset*dirY;}
  Text_RenderLineAndAdvanceCursor(self,px,py,value,cursor,&cursor,direction);
  ox+=dx;oy+=dy;
 }while(cursor);
}
