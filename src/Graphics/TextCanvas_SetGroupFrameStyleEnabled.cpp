#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
unsigned char *DisplayLayout_FindGroupById(char *,int);
// Original: arm9/main @ 0x02081198; symbol: func_02081198; size: 0x38.
void TextCanvas_SetGroupFrameStyleEnabled(char *p,int i,int v){unsigned char *q=DisplayLayout_FindGroupById(p+12,i);if(!q)return;if(v)q[18]=(q[18]&~240)|16;else q[18]&=~240;}
}
