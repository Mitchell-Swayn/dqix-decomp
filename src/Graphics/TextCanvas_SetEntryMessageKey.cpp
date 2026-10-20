#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
char *DisplayLayout_FindPartById(char *,int);
// Original: arm9/main @ 0x0208103C; symbol: func_0208103c; size: 0x1C.
void TextCanvas_SetEntryMessageKey(char *p,int i,short v){char *q=DisplayLayout_FindPartById(p+4,i);if(q)*(short *)(q+14)=v;}
}
