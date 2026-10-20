#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
unsigned char *DisplayLayout_FindPartById(char *,int);
// Original: arm9/main @ 0x02080798; symbol: func_02080798; size: 0x2C.
void TextCanvas_SetEntryTextAlignmentMode(char *p,int i,int v){unsigned char *q=DisplayLayout_FindPartById(p+4,i);if(q)q[20]=(q[20]&~3)|(v&3);}
}
