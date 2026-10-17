#include <globaldefs.h>
struct Pair {unsigned first,second;}; struct RecordArray { void* records;Pair* pairs;int count;int pairCount; };
// Original: arm9/ov015 @ 0x0218BB14; symbol: func_ov015_0218bb14; size: 0x28.
extern "C" ARM Pair* func_ov015_0218bb14(RecordArray* p,int index){if(index<0 || p->pairCount<=index)return 0;return p->pairs+index;}
