#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
char *FindNonnegativeKeyInEntryArray(char *,int);
// Original: arm9/main @ 0x0208103C; symbol: func_0208103c; size: 0x1C.
void WriteResolvedEntryHalfword0E(char *p,int i,short v){char *q=FindNonnegativeKeyInEntryArray(p+4,i);if(q)*(short *)(q+14)=v;}
}
