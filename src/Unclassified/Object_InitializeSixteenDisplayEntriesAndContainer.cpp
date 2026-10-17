#include <globaldefs.h>
ARM
struct Entry{unsigned char pad[0xd4];};struct State{int pad[2];Entry entries[16];};extern "C" {void Reset212ByteObjectRecordAndIndexSentinels(Entry*);void InitializeSixteenEmbeddedEntries(State*);
// Original: arm9/main @ 0x02058704; symbol: func_02058704; size: 0x38.
State* Object_InitializeSixteenDisplayEntriesAndContainer(State* p){Entry* end;Entry* cur=p->entries;end=p->entries+16;do{Reset212ByteObjectRecordAndIndexSentinels(cur);cur++;}while(cur<end);InitializeSixteenEmbeddedEntries(p);return p;}}
