#include <globaldefs.h>
ARM
#pragma opt_propagation off
#pragma force_active on
extern "C" void Graphics_SubmitTransformedCellToOam(void*,void*);
// Original: arm9/ov000 @ 0x02181164; symbol: func_ov000_02181164; size: 0x90.
extern "C" void BattleMenu_DrawDecimalSpriteNumber(char* self,int value,char* cells,int x,int y,int mode,int order,int spacing) {
 signed char flags;
 int fixedY;
 int savedY=y, savedMode=mode;
 if(value<0) return;
 if(!cells) return;
 fixedY=(unsigned)savedY<<12;
 flags=savedMode&3;
 do {
  char* cell=cells+(value%10)*0x28;
  *(int*)(cell+0x14)=(unsigned)x<<12;
  *(int*)(cell+0x18)=fixedY;
  cell[0x22]=order;
  cell[0x26]=flags;
  Graphics_SubmitTransformedCellToOam(self+0x11c,cell);
  ++order; x-=spacing;
  value/=10;
 } while(value);
}
