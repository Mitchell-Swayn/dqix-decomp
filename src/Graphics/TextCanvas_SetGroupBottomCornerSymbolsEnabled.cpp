#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
unsigned char *DisplayLayout_FindGroupById(char *,int);
// Original: arm9/main @ 0x02081130; symbol: func_02081130; size: 0x34.
void TextCanvas_SetGroupBottomCornerSymbolsEnabled(char *p,int i,int v){unsigned char *q=DisplayLayout_FindGroupById(p+12,i);if(!q)return;if(v)q[21]|=1;else q[21]&=~1;}
}
