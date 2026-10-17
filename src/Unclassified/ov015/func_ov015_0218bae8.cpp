#include <globaldefs.h>
struct Record { unsigned words[3]; }; struct RecordArray { Record* records;void* pairs;int count;int pairCount; };
// Original: arm9/ov015 @ 0x0218BAE8; symbol: func_ov015_0218bae8; size: 0x2C.
extern "C" ARM Record* func_ov015_0218bae8(RecordArray* p,int index){if(index<0 || p->count<=index)return 0;return p->records+index;}
