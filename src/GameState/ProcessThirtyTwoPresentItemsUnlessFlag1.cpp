#include <globaldefs.h>
#include "GameState/GameState.h"
extern "C" void FlushChangedSelectedResourceRangeList(void*);
struct Item {char pad[0x14];void* data;};struct Obj {char pad[12];Item* items[32];char rest[12];unsigned flags;};
// Original: arm9/main @ 0x0203DD94; symbol: func_0203dd94; size: 0x4C.
extern "C" ARM void ProcessThirtyTwoPresentItemsUnlessFlag1(Obj* p){if(p->flags&1)return;GameState::GetInstance();for(int i=0;i<32;i++){Item* item=p->items[i];if(item&&item->data)FlushChangedSelectedResourceRangeList(item->data);}}
