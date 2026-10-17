#include <globaldefs.h>
extern "C" {
ARM struct Bytes { unsigned char data[48]; };struct Record { Bytes bytes; short a; signed char b; unsigned char c; };
// Original: arm9/main @ 0x02093B54; symbol: func_02093b54; size: 0x3C.
 void Object_CopyBytesToBytesAndCopyAToAAndCopyBToBAndCopyCToC(Record* dst,const Record* src) { dst->bytes=src->bytes;dst->a=src->a;dst->b=src->b;dst->c=src->c; }
}
