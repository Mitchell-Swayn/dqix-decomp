#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
void *Object_GetGlobalConnectionState();int IsFirstWordNonzero(void *);
// Original: arm9/main @ 0x020E30A4; symbol: func_020e30a4; size: 0x4C.
unsigned char *RecordArray_FindFirstInactiveEntryWhenModeEnabled(unsigned char *p){if(!IsFirstWordNonzero(Object_GetGlobalConnectionState()))return 0;for(int i=0;i<8;p+=4,i++)if(!p[2])return p;return 0;}
}
