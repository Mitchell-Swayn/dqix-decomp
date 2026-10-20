#include <globaldefs.h>
#include <GameState/GameState.h>
// Original data: arm9/main @ 0x2109be0; symbol: data_02109be0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct Owner {char pad[0x2786];unsigned short mode;unsigned char flag;};struct Entry {char pad[13];unsigned char value:7;unsigned char flag:1;};extern "C" void* GameState_GetFieldAddress468(GameState*);extern "C" Owner* Zone3D_GetMainInstance();extern "C" Entry* ZoneTable_FindEntryById(void*,int);extern "C" int Bgm_MapZoneKindForLightingAndNetworkSession(unsigned);extern "C" int Bgm_FindConditionalZoneOverride(void*,int);extern "C" char BgmGetGlobalZoneOverrideTable_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x0209CD50; symbol: func_0209cd50; size: 0xA8.
extern "C" int Object_ReadIdValueWithZoneRemapAndOverride(int id) {int result=0;void* state=GameState_GetFieldAddress468(GameState::GetInstance());Owner* owner=Zone3D_GetMainInstance();if((id/100)*100==5900 && owner->flag==0 && owner->mode==1900)id=1900;Entry* entry=ZoneTable_FindEntryById(state,id);if(entry)result=Bgm_MapZoneKindForLightingAndNetworkSession(entry->value);int custom=Bgm_FindConditionalZoneOverride(BgmGetGlobalZoneOverrideTable_UnknownRoleZeroInitializedStorage,id);if(custom>=0)result=custom;return result;}
