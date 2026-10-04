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
bool (*data_020f1c88)(BoneMatrixRenderData*, AnimationData*, unsigned int) = ProcessJointAnimationsOnBoneMatrix;
bool (*data_020f1c84)(int*, AnimationData*, unsigned int) = ProcessVisibilityAnimations;
void (*data_020f1c80)(void*, AnimationData*, int) = MAMAnimationProcessingCallback;
void (*data_020f1c7c)(void*, AnimationData*, int) = MPTAnimationProcessingCallback;
void (*data_020f1c78)(void*, AnimationData*, int) = MATAnimationProcessingCallback;
void (*data_020f1c74)(void*, AnimationData*, int) = JACAnimationProcessingCallback;
void (*data_020f1c70)(void*, AnimationData*, int) = VAVAnimationProcessingCallback;
unsigned int data_020f1c6c = 5;
bool (*data_020f1c8c)(MaterialRenderData*, AnimationData*, unsigned int) = ProcessMaterialAnimationsOnBoundMaterial;
