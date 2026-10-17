#include <globaldefs.h>
extern "C" {
unsigned int *FindNonnegativeKeyInEntryArray(char *,int);
// Original: arm9/main @ 0x02080FC4; symbol: func_02080fc4; size: 0x1C.
void WriteResolvedEntryWord0(char *p,int i,unsigned int v){unsigned int *q=FindNonnegativeKeyInEntryArray(p+4,i);if(q)*q=v;}
}
