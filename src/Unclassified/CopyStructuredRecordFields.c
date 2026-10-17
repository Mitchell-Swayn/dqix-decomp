#include <globaldefs.h>
typedef struct { char bytes[6]; } Six;
typedef struct { char bytes[32]; } Bytes;
typedef struct { unsigned words[32]; } Words;
typedef struct { unsigned short a,b; Six six; unsigned short c; Bytes bytes; unsigned short d,e,f,g,h,i,j,k,l,m; Words words; } Record;
// Original: arm9/main @ 0x0202BA08; symbol: func_0202ba08; size: 0xCC.
Record* CopyStructuredRecordFields(Record* dst,const Record* src) { dst->a=src->a;dst->b=src->b;dst->six=src->six;dst->c=src->c;dst->bytes=src->bytes;dst->d=src->d;dst->e=src->e;dst->f=src->f;dst->g=src->g;dst->h=src->h;dst->i=src->i;dst->j=src->j;dst->k=src->k;dst->l=src->l;dst->m=src->m;dst->words=src->words;return dst; }
