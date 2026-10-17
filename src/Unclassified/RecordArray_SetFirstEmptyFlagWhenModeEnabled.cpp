#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
void *Object_GetGlobalConnectionState();int IsFirstWordNonzero(void *);
// Original: arm9/main @ 0x020E3368; symbol: func_020e3368; size: 0x4C.
void RecordArray_SetFirstEmptyFlagWhenModeEnabled(unsigned char *p,unsigned char v){if(!IsFirstWordNonzero(Object_GetGlobalConnectionState()))return;unsigned char *q=p+32;for(int i=0;i<8;i++,q++)if(!*q){*q=v;return;}}
}
