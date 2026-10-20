#include <globaldefs.h>
struct Records { unsigned flags:12; unsigned rest:20; char* records; };
typedef void (*Callback)(Records*,char*);
// Original: arm9/main @ 0x020A8F70; symbol: func_020a8f70; size: 0x60.
extern "C" int MonsterOverrideTable_ForEachRecord(Records* p,Callback callback) { int count; char* cur=p->records; if(cur==0 || (count=p->flags)==0 || callback==0)return 0; for(int i=0;i<count;i++,cur+=64)callback(p,cur); return 1; }
