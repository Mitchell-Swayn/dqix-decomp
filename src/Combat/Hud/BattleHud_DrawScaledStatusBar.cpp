#include <globaldefs.h>
#include <System/Matrix.h>
extern "C" void Graphics_SubmitTransformedCellToOam(void*,void*);
struct BarCell {unsigned char prefix[12];int scaleX,scaleY,x,y;unsigned char unknown[4];unsigned short palette;unsigned char flag,unknown23[3],kind,unknown27;};
// Original: arm9/ov000 @ 0x021741E0; symbol: func_ov000_021741e0; size: 0xE8.
// Clamps the bar amount, computes its fixed-point horizontal scale and submits
// the selected status-bar cell with the requested position and display flags.
extern "C" void BattleHud_DrawScaledStatusBar(unsigned char* self,float value,float maximum,int x,int y,unsigned char index,unsigned char flag,unsigned char palette,unsigned char kind,bool roundUp){
 if(maximum<value)value=maximum;
 BarCell* cell=&(*(BarCell**)(self+0x170))[index];
 int screenX=x<<12,screenY=y<<12;
 int amount=(int)(4096.0f*value);
 int width=(int)(((long long)amount*65536+2048)>>12);
 if(roundUp)width+=4096;
 int scale=fix32_Divide(width&~4095,65536);
 if(scale<65){if(0.0f<value)scale=65;else return;}
 cell->x=screenX;cell->y=screenY;cell->scaleX=scale;cell->scaleY=4096;
 cell->palette=palette;cell->flag=flag;cell->kind=kind;
 Graphics_SubmitTransformedCellToOam(self+0x11c,cell);
}
