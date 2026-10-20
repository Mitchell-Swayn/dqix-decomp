#include <globaldefs.h>
#include <GameState/GameState.h>
// Original data: arm9/main @ 0x20e7bfc; symbol: data_020e7bfc.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 000000000000000000000000000000000000000000000000ffffffff.
// Observed span: 28 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct Indices {int values[7];};extern "C" Indices Object3DApplyDiffuseColorToMappedRelatedObjects_UnknownRoleInitializedBytes;
// Original: arm9/main @ 0x02053CF8; symbol: func_02053cf8; size: 0xA8.
extern "C" void Object3D_ApplyDiffuseColorToMappedRelatedObjects(Object3D* object) {GameState* state=GameState::GetInstance();object->UseRenderConfigDiffuseColor();int base=*(short*)((char*)object+4)*12;Indices indices=Object3DApplyDiffuseColorToMappedRelatedObjects_UnknownRoleInitializedBytes;indices.values[0]=base+19;indices.values[1]=base+20;indices.values[2]=base+21;indices.values[3]=base+27;indices.values[4]=base+28;indices.values[5]=base+29;for(int* id=indices.values;*id>=0;++id){GameObject* obj=state->GetGameObjectByIndex(*id);if(obj)obj->obj3D_.UseRenderConfigDiffuseColor();}}
