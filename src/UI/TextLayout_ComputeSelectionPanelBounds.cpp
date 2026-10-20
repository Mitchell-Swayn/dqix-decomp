#include <globaldefs.h>
ARM
extern "C" void* TextContext_GetSharedInstance(); extern "C" void Grid_SetTouchCellBounds(void*,int,short*,short*,short*,short*);
struct Object { unsigned char pad0[0x58]; short x,y; unsigned char pad1[0x20]; int rows; unsigned char pad2[0x34]; short sourceX,sourceY,width,height; unsigned char pad3[0x14]; int baseWidth,unknown,rowHeight,count; short xs[8],ys[8],widths[8],heights[8]; };
// Original: arm9/main @ 0x0205CC50; symbol: func_0205cc50; size: 0xD8.
extern "C" void TextLayout_ComputeSelectionPanelBounds(Object* object,int align,short extra) { TextContext_GetSharedInstance(); int rows=object->rows; int base=rows*12+16; object->width=object->baseWidth+24; object->height=(rows-1)*(object->rowHeight-12)+base; if(align)object->width=extra+(short)((object->width+7)&~7); for(int i=0;i<object->count;i++){object->xs[i]=12;object->ys[i]=object->rowHeight*i+8;}short sy=object->sourceY; short sx=object->sourceX; object->x=sx;object->y=sy;Grid_SetTouchCellBounds((unsigned char*)object+32,object->count,object->xs,object->ys,object->widths,object->heights); }
