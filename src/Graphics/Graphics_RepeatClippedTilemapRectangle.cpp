#include <globaldefs.h>
ARM
extern "C" void Graphics_CopyClippedTilemapRectangle(void*,void*,const short*,int,int,unsigned,unsigned,int,int,unsigned short);

// Original: arm9/main @ 0x0204BAB4; symbol: Graphics_RepeatClippedTilemapRectangle; size: 0x100.
extern "C" void Graphics_RepeatClippedTilemapRectangle(char* target,short* source,int width,int height,short x,short y,int columns,int rows,unsigned short value){
if(width<=0||height<=0||!*(void**)((char*)source+12))return;
 short currentX;short currentY;unsigned short row;int maxWidth=source[0],maxHeight=source[1];if(maxWidth<width)width=maxWidth;if(maxHeight<height)height=maxHeight;
 currentY=y;for(row=0;row<rows;++row){currentX=x;for(unsigned short col=0;col<columns;++col){if(*(void**)(target+20))Graphics_CopyClippedTilemapRectangle(target,*(void**)(target+20),source,0,0,currentX,currentY,width,height,value);currentX+=width;}currentY+=height;}
}
