#include <globaldefs.h>
struct Buffer { unsigned remaining; signed char* cursor; };
// Original: arm9/main @ 0x020D3108; symbol: func_020d3108; size: 0x58.
extern "C" void CopyAvailableBytesAndAdvanceCursorByRequestedCount(Buffer* p, const signed char* src, int count) { if(count<=0)return; unsigned i; unsigned n=p->remaining; if(n>(unsigned)count)n=count; i=0; if(i<n)do {p->cursor[i]=src[i]; i++;}while(i<n); p->remaining-=n; p->cursor+=count; }
