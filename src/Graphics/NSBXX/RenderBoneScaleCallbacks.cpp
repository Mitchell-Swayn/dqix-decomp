#include "Graphics/NSBXX/RenderCommands_Common.h"

void BoneMatrixScaleCalculationProc_Type0(BoneMatrixRenderData*, NSBXXBoneMatrix::Scaling*, uint8_t*, int);
void BoneMatrixScaleCalculationProc_Type1(BoneMatrixRenderData*, NSBXXBoneMatrix::Scaling*, uint8_t*, int);
void BoneMatrixScaleCalculationProc_Type2(BoneMatrixRenderData*, NSBXXBoneMatrix::Scaling*, uint8_t*, int);

void (*data_020f1cec[3])(BoneMatrixRenderData*, NSBXXBoneMatrix::Scaling*, uint8_t*, int) = {
    BoneMatrixScaleCalculationProc_Type0, BoneMatrixScaleCalculationProc_Type1, BoneMatrixScaleCalculationProc_Type2
};
