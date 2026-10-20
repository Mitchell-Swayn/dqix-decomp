#include <globaldefs.h>
ARM
extern "C" void WindowFrame_BlitSharedBorderTile(void*,int,int,int);
struct Rect {short x,y,width,height;};
// Original: arm9/main @ 0x02043600; symbol: func_02043600; size: 0x1BC.
extern "C" void Graphics_PopulateEightTileRectangleBorder(unsigned char* self,const Rect* rect) {
 if(!self || !rect) return;
 short top,right,bottom;
 short i;
 short left=rect->x;
 bottom=rect->y+rect->height;
 right=rect->x+rect->width;
 bottom-=*(short*)(self+0xae)*8;
 top=rect->y-*(short*)(self+0xae)*8;
 right-=8;
 bottom-=8;
 if(left<0 || top<0 || bottom<0 || right<0) return;
 for(i=left+8;i<right;i+=8) WindowFrame_BlitSharedBorderTile(self,i,top,1);
 for(short j=left+8;j<right;j+=8) WindowFrame_BlitSharedBorderTile(self,j,bottom,6);
 for(i=top+8;i<bottom;i+=8) WindowFrame_BlitSharedBorderTile(self,left,i,3);
 for(short j=top+8;j<bottom;j+=8) WindowFrame_BlitSharedBorderTile(self,right,j,4);
 WindowFrame_BlitSharedBorderTile(self,left,top,0);
 WindowFrame_BlitSharedBorderTile(self,right,top,2);
 WindowFrame_BlitSharedBorderTile(self,left,bottom,5);
 WindowFrame_BlitSharedBorderTile(self,right,bottom,7);
}
