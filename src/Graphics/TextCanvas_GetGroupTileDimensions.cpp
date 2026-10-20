#include <globaldefs.h>
extern "C" {
short *DisplayLayout_FindGroupById(char *,int);
// Original: arm9/main @ 0x02080878; symbol: func_02080878; size: 0x2C.
void TextCanvas_GetGroupTileDimensions(char *p,int i,short *x,short *y){short *q=DisplayLayout_FindGroupById(p+12,i);if(q){*x=q[7];*y=q[8];}}
}
