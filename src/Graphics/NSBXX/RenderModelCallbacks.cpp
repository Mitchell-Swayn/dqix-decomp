#include "Graphics/NSBXX/RenderCommands_Common.h"

void BoneMatrixDataSubmissionProc_Type0(BoneMatrixRenderData*);
void BoneMatrixDataSubmissionProc_Type1(BoneMatrixRenderData*);
void BoneMatrixDataSubmissionProc_Type2(BoneMatrixRenderData*);

void (*data_020f1ce0[3])(BoneMatrixRenderData*) = {
    BoneMatrixDataSubmissionProc_Type0, BoneMatrixDataSubmissionProc_Type1, BoneMatrixDataSubmissionProc_Type2
};
