#include <globaldefs.h>
ARM
#include <World/Object3D.h>
#include <Graphics/Model3D.h>
// Original data: arm9/main @ 0x2107870; symbol: data_02107870.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x21078a8; symbol: data_021078a8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x21078e0; symbol: data_021078e0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern Object3D::TrackedBoneMatrix BoneTrackingCameraRefreshTrackedBones_UnknownRoleZeroInitializedStorage;extern unsigned char BoneTrackingCameraRefreshTrackedBones_UnknownRoleZeroInitializedStorage_Variant2[],BoneTrackingCameraRefreshTrackedBones_UnknownRoleZeroInitializedStorage_Variant3[];
// Original: arm9/main @ 0x0204A4AC; symbol: func_0204a4ac; size: 0x128.
extern "C" void BoneTrackingCamera_RefreshTrackedBones(unsigned char* object){Object3D* model=*(Object3D**)(object+0x21c);Model3D* mesh;if(!model||!(mesh=*(Model3D**)((unsigned char*)model+8)))return;if(*(int*)(object+0x258)>=0)model->UntrackBoneByIndex(*(int*)(object+0x254));if(*(int*)(object+0x258)>=0)(*(Object3D**)(object+0x21c))->UntrackBoneByIndex(*(int*)(object+0x258));if(*(int*)(object+0x25c)>=0)(*(Object3D**)(object+0x21c))->UntrackBoneByIndex(*(int*)(object+0x25c));if(*(int*)(object+0x254)==-1)*(int*)(object+0x254)=mesh->GetBoneIndex((char*)object+0x224);if(*(int*)(object+0x258)==-1)*(int*)(object+0x258)=mesh->GetBoneIndex((char*)object+0x234);if(*(int*)(object+0x25c)==-1)*(int*)(object+0x25c)=mesh->GetBoneIndex((char*)object+0x244);if(*(int*)(object+0x258)>=0){*(short*)&BoneTrackingCameraRefreshTrackedBones_UnknownRoleZeroInitializedStorage=*(int*)(object+0x254);(*(Object3D**)(object+0x21c))->TrackBone(&BoneTrackingCameraRefreshTrackedBones_UnknownRoleZeroInitializedStorage);}if(*(int*)(object+0x258)>=0){*(short*)((unsigned char*)&BoneTrackingCameraRefreshTrackedBones_UnknownRoleZeroInitializedStorage+0x38)=*(int*)(object+0x258);(*(Object3D**)(object+0x21c))->TrackBone((Object3D::TrackedBoneMatrix*)BoneTrackingCameraRefreshTrackedBones_UnknownRoleZeroInitializedStorage_Variant2);}if(*(int*)(object+0x25c)>=0){*(short*)((unsigned char*)&BoneTrackingCameraRefreshTrackedBones_UnknownRoleZeroInitializedStorage+0x70)=*(int*)(object+0x25c);(*(Object3D**)(object+0x21c))->TrackBone((Object3D::TrackedBoneMatrix*)BoneTrackingCameraRefreshTrackedBones_UnknownRoleZeroInitializedStorage_Variant3);}}
