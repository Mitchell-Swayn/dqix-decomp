#include <globaldefs.h>
extern "C" {
unsigned int *DisplayLayout_FindPartById(char *,int);
// Original: arm9/main @ 0x02080FC4; symbol: func_02080fc4; size: 0x1C.
void TextCanvas_SetEntryFloatValue(char *p,int i,unsigned int v){unsigned int *q=DisplayLayout_FindPartById(p+4,i);if(q)*q=v;}
}
