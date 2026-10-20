#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Resource/GameResources.h>
#include <Filesystem/BackgroundLoader.h>
ARM
#pragma always_inline on
struct IntegerParameterView;struct Owner;
extern "C" GameObject* GameState_GetObjectWithFlag100(GameState*,int);
extern "C" void* GameState_GetIndexList(GameState*);
extern "C" void GameResources_ClearPrimaryFlags(unsigned*,unsigned);
extern "C" void GameObject_SetLinkedStatAndMarkChanged(Owner*,int,int);
extern "C" int GameObject_GetLinkedStatOrInvalid(char*,int);
extern "C" char* GameObject_ResolveLinkedStatsOrNull(char**);
extern "C" void Field_QueuePartyMemberEquipmentRefresh(GameResources*,int,int,int,int);
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView*);
struct ScriptGlobalState {unsigned unknown[6];unsigned flags;};
struct StatParameterMap {unsigned unknown[12];int objectIndex;int parameterIds[8];};
// Original data: arm9/ov001 @ 0x2165880; symbol: data_ov001_02165880.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" ScriptGlobalState EventGetObjectSession_UnknownRoleZeroInitializedStorage;
// Original data: arm9/ov001 @ 0x2164d14; symbol: data_ov001_02164d14.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 000034430000f041000034430000f041.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" StatParameterMap LightingApplyScriptPresetAndUpdateScene_UnknownRoleInitializedBytes;
// Original data: arm9/ov001 @ 0x2164a30; symbol: data_ov001_02164a30.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0000000001000000020000000300000005000000060000000700000008000000090000000a000000.
// Observed span: 40 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
// Original data: arm9/ov001 @ 0x2164d44; symbol: data_ov001_02164d44.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 000000000000000000000000000000000000000000000000000000000000000000000000ffffffff.
// Observed span: 40 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" unsigned ScriptSaveOrRestoreIndexedCharacterStat_UnknownRoleInitializedBytes[],ScriptSaveOrRestoreIndexedCharacterStat_UnknownRoleInitializedBytes_Variant2[];
static inline char *LinkedStatRecord(char *object,unsigned char slot) {return *(char**)(object+0x150)+0x194+slot*32;}
static inline void InitializeStatParameterMap(int index,ScriptGlobalState *state,StatParameterMap *map) {
 unsigned flags=state->flags;
 if(!(flags&1)) {
  int offset=index*12;
  map->objectIndex=index;
  map->parameterIds[0]=offset+19;
  map->parameterIds[1]=offset+20;
  map->parameterIds[2]=offset+21;
  map->parameterIds[3]=offset+23;
  map->parameterIds[4]=offset+25;
  map->parameterIds[5]=offset+27;
  map->parameterIds[6]=offset+28;
  map->parameterIds[7]=offset+29;
  state->flags=flags|1;
 }
}
// Original: arm9/ov001 @ 0x02162DB0; symbol: func_ov001_02162db0; size: 0x1DC.
// Saves or restores a selected linked character stat and schedules a resource refresh.
extern "C" int Script_SaveOrRestoreIndexedCharacterStat(char *parameters,int count) {
 GameState *game;char *object;int restore;GameResources *resources;char *scene;int index,stat;short *values;int saved;
 game=GameState::GetInstance();
 index=Script_ReadParameterAsInteger((IntegerParameterView*)parameters);
 object=(char*)GameState_GetObjectWithFlag100(game,index);
 if(!object)return 0;
 stat=Script_ReadParameterAsInteger((IntegerParameterView*)(parameters+8));
 restore=0;
 if(count>=3)restore=Script_ReadParameterAsInteger((IntegerParameterView*)(parameters+16));
 InitializeStatParameterMap(index,&EventGetObjectSession_UnknownRoleZeroInitializedStorage,&LightingApplyScriptPresetAndUpdateScene_UnknownRoleInitializedBytes);
 char *record=LinkedStatRecord(object,ScriptSaveOrRestoreIndexedCharacterStat_UnknownRoleInitializedBytes[stat]);
 if(!record)return 0;
 values=(short*)GameObject_ResolveLinkedStatsOrNull((char**)object);
 if(!values)return 0;
 resources=GameResources_GetInstance();
 scene=*(char**)((char*)resources+0x3734);
 GameState_GetIndexList(game);
 game->GetGameObjectByIndex(ScriptSaveOrRestoreIndexedCharacterStat_UnknownRoleInitializedBytes_Variant2[stat]);
 if(!restore) {
  *(short*)(scene+0x182)=-1;
  *(signed char*)(scene+0x180)=-1;
  saved=values[stat];
  *(short*)(scene+0x182)=saved;
  GameObject_SetLinkedStatAndMarkChanged((Owner*)object,stat,-1);
 } else {
  saved=*(short*)(scene+0x182);
  restore=*(signed char*)(scene+0x180);
  *(short*)(scene+0x182)=-1;
  *(signed char*)(scene+0x180)=-1;
  if(GameObject_GetLinkedStatOrInvalid(object,stat)<0 && restore!=6)
   GameObject_SetLinkedStatAndMarkChanged((Owner*)object,stat,(short)saved);
 }
 GameResources_ClearPrimaryFlags((unsigned*)resources,16);
 BackgroundLoader::GetInstance();
 Field_QueuePartyMemberEquipmentRefresh(resources,index,1,0,0);
 return 1;
}
