#include <globaldefs.h>
struct Pair {unsigned first,second;}; struct RecordArray { void* records;Pair* pairs;int count;int pairCount; };
// Original: arm9/ov015 @ 0x0218BA1C; symbol: func_ov015_0218ba1c; size: 0x28.
extern "C" ARM void CharacterViewer_AppendScenePreset(RecordArray* p,const Pair* value){int index=p->pairCount++;Pair* target=p->pairs+index;target->first=value->first;target->second=value->second;}
