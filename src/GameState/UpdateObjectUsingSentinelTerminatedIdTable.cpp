#include <globaldefs.h>
ARM
#include <GameState/GameState.h>
// Original data: arm9/main @ 0x20e8846; symbol: data_020e8846.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 000002000100040005000600ffff.
// Observed span: 14 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" short UpdateObjectUsingSentinelTerminatedIdTable_UnknownRoleInitializedBytes[];extern "C" void PartyAppearance_ApplyEquipmentPalette(int,int);extern "C" void Resource_ApplyUpdateOnlyWhenValidationPasses(GameResources*,int,unsigned short);
// Original: arm9/main @ 0x02073240; symbol: func_02073240; size: 0x68.
extern "C" void UpdateObjectUsingSentinelTerminatedIdTable(int index){GameObject* obj=GameState::GetInstance()->GetGameObjectByIndex(index);if(!obj)return;for(int i=0;UpdateObjectUsingSentinelTerminatedIdTable_UnknownRoleInitializedBytes[i]>=0;i++)PartyAppearance_ApplyEquipmentPalette(index,UpdateObjectUsingSentinelTerminatedIdTable_UnknownRoleInitializedBytes[i]);if(!*(unsigned short*)((char*)obj+0x9c))return;GameResources* resources=GameResources_GetInstance();Resource_ApplyUpdateOnlyWhenValidationPasses(resources,index,(unsigned short)obj->obj3D_.unknown_9c_);}
