#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
char *DisplayLayout_GetPartByIndex(void *,int);void *DisplayLayout_FindPartById(void *,int);
// Original: arm9/main @ 0x0207F72C; symbol: func_0207f72c; size: 0x80.
void DisplayLayout_ResolvePartReferences(char *p){short count=*(short *)(p+4);for(short i=0;i<count;i++){char *q=DisplayLayout_GetPartByIndex(p,i);if(q){*(void **)(q+24)=DisplayLayout_FindPartById(p,*(short *)(q+24));*(void **)(q+28)=DisplayLayout_FindPartById(p,*(short *)(q+28));*(void **)(q+32)=DisplayLayout_FindPartById(p,*(short *)(q+32));*(void **)(q+36)=DisplayLayout_FindPartById(p,*(short *)(q+36));}}}
}
