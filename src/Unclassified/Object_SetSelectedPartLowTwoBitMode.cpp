#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
unsigned char *FindNonnegativeKeyInEntryArray(char *,int);
// Original: arm9/main @ 0x02080798; symbol: func_02080798; size: 0x2C.
void Object_SetSelectedPartLowTwoBitMode(char *p,int i,int v){unsigned char *q=FindNonnegativeKeyInEntryArray(p+4,i);if(q)q[20]=(q[20]&~3)|(v&3);}
}
