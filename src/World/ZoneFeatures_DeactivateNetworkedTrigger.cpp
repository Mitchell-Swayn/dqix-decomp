#include <globaldefs.h>
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct Owner {unsigned char a,b,c,unused;bool active;unsigned char flags;};extern "C" {extern char Main_UnknownRoleZeroInitializedStorage[];void SoundSfx_RestoreCurrentHeapState(void*,int);void* Network_GetConnectionManager();int Network_GetLocalMemberId(void*);void ZoneFeatures_QueueTriggerSynchronization(unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned);
// Original: arm9/main @ 0x020A8874; symbol: func_020a8874; size: 0x74.
void ZoneFeatures_DeactivateNetworkedTrigger(Owner* p){if(!p->active)return;p->active=false;SoundSfx_RestoreCurrentHeapState(Main_UnknownRoleZeroInitializedStorage,0);int bit=Network_GetLocalMemberId(Network_GetConnectionManager());p->flags&=~(1u<<bit);ZoneFeatures_QueueTriggerSynchronization(p->a,p->b,p->c,0,(unsigned char)bit,0,0);} }
