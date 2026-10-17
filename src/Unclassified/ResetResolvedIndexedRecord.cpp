#include <globaldefs.h>
extern "C" {
void *FindKeyAmongFourRecords(void *,int);void InitializeHalfwordKeyAndInvalidByteIds(void *);
// Original: arm9/main @ 0x0207DA7C; symbol: func_0207da7c; size: 0x18.
void ResetResolvedIndexedRecord(void *p,int i){void *q=FindKeyAmongFourRecords(p,i);if(q)InitializeHalfwordKeyAndInvalidByteIds(q);}
}
