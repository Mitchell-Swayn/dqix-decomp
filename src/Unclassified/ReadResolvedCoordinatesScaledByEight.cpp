#include <globaldefs.h>
extern "C" {
short *FindNonnegativeKeyInCountedRecordArray(char *,int);
// Original: arm9/main @ 0x020807C4; symbol: func_020807c4; size: 0x38.
void ReadResolvedCoordinatesScaledByEight(char *p,int i,short *x,short *y){short *q=FindNonnegativeKeyInCountedRecordArray(p+12,i);if(!q)return;*x=q[5]<<3;*y=q[6]<<3;}
}
