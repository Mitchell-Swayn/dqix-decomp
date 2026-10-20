#include <globaldefs.h>
ARM
struct RectList { short x,y; signed char count; char pad[3]; short *xs,*ys,*widths,*heights; };
// Original: arm9/ov003 @ 0x02169674; symbol: func_ov003_02169674; size: 0x80.
extern "C" int Graphics_FindContainingRectangle(void*,int x,int y,RectList* list) {
 x-=list->x; y-=list->y;
 short* xs=list->xs; short* ys=list->ys; short* widths=list->widths; short* heights=list->heights;
 int count=list->count;
 for(int i=0;i<count;++i) {
  int left=xs[i]; int right=left+widths[i]; int top=ys[i]; int bottom=top+heights[i];
  if(x>=left && x<=right && y>=top && y<=bottom) return i;
 }
 return -1;
}
