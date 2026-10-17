#include <globaldefs.h>
typedef struct { unsigned a,b,c,d; } Four; typedef struct { unsigned a,b,c; } Three; typedef struct { Four head; unsigned value; Three first,second; } Record;
// Original: arm9/main @ 0x020A2928; symbol: func_020a2928; size: 0x44.
Record *CopyHeadAndThreeScalarFields(Record *dst,const Record *src) { dst->head=src->head; dst->value=src->value; dst->first=src->first; dst->second=src->second; return dst; }
