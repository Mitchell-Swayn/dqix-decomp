#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
unsigned char *FindNonnegativeKeyInCountedRecordArray(char *,int);
// Original: arm9/main @ 0x02081130; symbol: func_02081130; size: 0x34.
void Object_SetSelectedGroupBooleanFlag(char *p,int i,int v){unsigned char *q=FindNonnegativeKeyInCountedRecordArray(p+12,i);if(!q)return;if(v)q[21]|=1;else q[21]&=~1;}
}
