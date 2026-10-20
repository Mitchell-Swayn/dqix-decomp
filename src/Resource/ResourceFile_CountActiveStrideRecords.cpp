#include <globaldefs.h>
struct Record { signed char active; char reserved[0x47]; int stride; inline int isActive() const { return active != 0; } };
// Original: arm9/main @ 0x02046900; symbol: func_02046900; size: 0x3C.
extern "C" int ResourceFile_CountActiveStrideRecords(Record* p) { int n=0; while(p->isActive()) { ++n; p=(Record*)((char*)p+p->stride); } return n; }
