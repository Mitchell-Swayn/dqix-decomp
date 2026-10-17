#include <globaldefs.h>
ARM
#include <World/Zone3D.h>
#include <World/ZonePredicates.h>
#include <Graphics/LightingManager.h>
#include <Graphics/NSBXX/RenderConfig.h>
extern "C" void RenderConfig_CopyTransformAndClearFlagsA4(void*);
// Original: arm9/main @ 0x0201AEDC; symbol: func_0201aedc; size: 0xF4.
extern "C" void Zone3D_DrawAmbientModelsInGroupsFourAndFive(Zone3D* p) {if(IsGrottoBossFloorZone(*(unsigned short*)p))return;char* transforms=(char*)p+0x25b4;Zone3D_BMDJStruct* group=p->GetBMDJGroupAtIndex(5);if(group && !(group->ptr_44->flags&4)) {Model3D* model=(*(Zone3D_BMDJStruct::ObjectEntry**)((char*)group->ptr_44+0x24))->model;if(model && *(NSBXXInternalModel* volatile*)&model->rawInternalModel_) {LightingManager::GetInstance()->ApplyAmbientColorToModel(*(NSBXXInternalModel* volatile*)&model->rawInternalModel_);RenderConfig_CopyTransformAndClearFlagsA4(transforms+0x48);RenderConfig::SetObjectPosition((Vector3fix*)(transforms+0x6c));RenderConfig::SubmitToFifo();model->Draw(true);}}group=p->GetBMDJGroupAtIndex(4);if(!group)return;if(group->ptr_44->flags&4)return;Model3D* model=(*(Zone3D_BMDJStruct::ObjectEntry**)((char*)group->ptr_44+0x24))->model;if(model && *(NSBXXInternalModel* volatile*)&model->rawInternalModel_) {LightingManager::GetInstance()->ApplyAmbientColorToModel(*(NSBXXInternalModel* volatile*)&model->rawInternalModel_);RenderConfig_CopyTransformAndClearFlagsA4(transforms+0x14);RenderConfig::SetObjectPosition((Vector3fix*)(transforms+0x38));RenderConfig::SubmitToFifo();model->Draw(true);} }
