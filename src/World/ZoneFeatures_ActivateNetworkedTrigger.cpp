#include <globaldefs.h>
struct Object {unsigned char a,b,c,pad,enabled,mask;};
extern "C" void* GameResources_GetInstance();
extern "C" int GameResources_IsSelectedScreenBrightnessWithinExtremes(void*,unsigned);
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage[];
extern "C" void SoundSfx_RestoreCurrentHeapState(void*);
extern "C" void ResourceHandle_ApplyPreviousAndNewStateWithValue(void*,unsigned,unsigned);
extern "C" void SoundSfx_StartCurrentGroupSequenceArchiveEntry(void*,unsigned,unsigned);
extern "C" void* Network_GetConnectionManager();
extern "C" signed char Network_GetLocalMemberId(void*);
extern "C" void ZoneFeatures_QueueTriggerSynchronization(unsigned,unsigned,unsigned,unsigned,unsigned char,unsigned,unsigned);
// Original: arm9/main @ 0x020A87D0; symbol: func_020a87d0; size: 0xA4.
extern "C" void ZoneFeatures_ActivateNetworkedTrigger(Object* p) {if(p->enabled!=1){p->enabled=1;if(GameResources_IsSelectedScreenBrightnessWithinExtremes(GameResources_GetInstance(),0)){SoundSfx_RestoreCurrentHeapState(Main_UnknownRoleZeroInitializedStorage);ResourceHandle_ApplyPreviousAndNewStateWithValue(Main_UnknownRoleZeroInitializedStorage,0x72,0x72);SoundSfx_StartCurrentGroupSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,0,0);}int index=Network_GetLocalMemberId(Network_GetConnectionManager());p->mask|=1u<<index;ZoneFeatures_QueueTriggerSynchronization(p->a,p->b,p->c,1,(unsigned char)index,0,0);}}
