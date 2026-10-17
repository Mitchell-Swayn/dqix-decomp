#include <globaldefs.h>
extern "C" {
short *FindNonnegativeKeyInCountedRecordArray(char *,int);
// Original: arm9/main @ 0x02080878; symbol: func_02080878; size: 0x2C.
void ReadKeyedGroupCoordinateHalfwords(char *p,int i,short *x,short *y){short *q=FindNonnegativeKeyInCountedRecordArray(p+12,i);if(q){*x=q[7];*y=q[8];}}
}
