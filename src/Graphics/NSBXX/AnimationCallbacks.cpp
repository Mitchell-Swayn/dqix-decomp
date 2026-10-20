#include "Graphics/NSBXX/Animation.h"

void VAVAnimationProcessingCallback(void*, AnimationData*, int);
void JACAnimationProcessingCallback(void*, AnimationData*, int);
void MATAnimationProcessingCallback(void*, AnimationData*, int);
void MPTAnimationProcessingCallback(void*, AnimationData*, int);
void MAMAnimationProcessingCallback(void*, AnimationData*, int);
bool ProcessVisibilityAnimations(int*, AnimationData*, unsigned int);
bool ProcessJointAnimationsOnBoneMatrix(BoneMatrixRenderData*, AnimationData*, unsigned int);
bool ProcessMaterialAnimationsOnBoundMaterial(MaterialRenderData*, AnimationData*, unsigned int);

// Declaration order preserves MWCC data placement: the first eight definitions
// are emitted in reverse order; the final definition follows them.
bool (*PopulateModelRenderContext_UnknownRoleProcedureReferenceRecords_Variant2)(BoneMatrixRenderData*, AnimationData*, unsigned int) = ProcessJointAnimationsOnBoneMatrix;
bool (*PopulateModelRenderContext_UnknownRoleProcedureReferenceRecords)(int*, AnimationData*, unsigned int) = ProcessVisibilityAnimations;
void (*InitializeModelAnimationFromMAM_UnknownRoleProcedureReferenceRecords)(void*, AnimationData*, int) = MAMAnimationProcessingCallback;
void (*InitializeModelAnimationFromMPT_UnknownRoleProcedureReferenceRecords)(void*, AnimationData*, int) = MPTAnimationProcessingCallback;
void (*InitializeModelAnimationFromMAT_UnknownRoleProcedureReferenceRecords)(void*, AnimationData*, int) = MATAnimationProcessingCallback;
void (*InitializeModelAnimationFromJAC_UnknownRoleProcedureReferenceRecords)(void*, AnimationData*, int) = JACAnimationProcessingCallback;
void (*InitializeModelAnimationFromVAV_UnknownRoleProcedureReferenceRecords)(void*, AnimationData*, int) = VAVAnimationProcessingCallback;
unsigned int InitializeModelAnimation_UnknownRoleInitializedBytes = 5;
bool (*PopulateModelRenderContext_UnknownRoleProcedureReferenceRecords_Variant3)(MaterialRenderData*, AnimationData*, unsigned int) = ProcessMaterialAnimationsOnBoundMaterial;
