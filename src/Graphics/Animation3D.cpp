#include "Graphics/Animation3D.h"
#include "Graphics/Model3D.h"
#include "World/Object3D.h"

#define ANIMATION_FLAG_NOT_LOOPING 0

// Original: arm9/main @ 0x0207E060; symbol: _ZN11Animation3D17DefaultInitializeEv; size: 0x1C.
void Animation3D::DefaultInitialize()
{
    pRawFile_ = NULL;
    pAnimData_ = NULL;
    playbackSpeed_ = 1 << 12;
    flags_ = 0;
}

// Original: arm9/main @ 0x0207E07C; symbol: _ZN11Animation3D10SetRawFileEP14NSBXXContainer; size: 0x14.
bool Animation3D::SetRawFile(NSBXXContainer* file)
{
    if (file == NULL)
        return false;
    pRawFile_ = file;
    return true;
}

// Original: arm9/main @ 0x0207E090; symbol: _ZN11Animation3D10CreateDataEP7Model3DP13SafeAllocatorS1_; size: 0xD8.
bool Animation3D::CreateData(Model3D *attachedModel, SafeAllocator *alloc, Model3D *alternateModel)
{
    if (pRawFile_ == NULL)
        return false;

    if (attachedModel == NULL)
        return false;

    if (alloc == NULL)
        return false;

    Model3D* modelIfValid = (attachedModel->unknown_flags_a8_0_) ? attachedModel : NULL;
    NSBXXTex* tex0;
    NSBXXInternalModel* internalModel = attachedModel->rawInternalModel_;

    tex0 = attachedModel->GetTEX0();
    if (alternateModel != NULL)
        tex0 = alternateModel->GetTEX0();

    if (modelIfValid == NULL)
        return false;

    if (internalModel == NULL)
        return false;

    void* rawInnerAnim = NSBXX_GetObjectFromFirstSubfile(pRawFile_, 0);
    if (rawInnerAnim == NULL)
        return false;

    AnimationData* allocatedData = NSBXX_Model_AllocateAnimationData(&alloc->allocUnion, rawInnerAnim, internalModel);
    if (allocatedData == NULL)
        return false;

    InitializeModelAnimation(allocatedData, rawInnerAnim, internalModel, tex0);
    pAnimData_ = allocatedData;
    return true;
}

// Original: arm9/main @ 0x0207E168; symbol: _ZN11Animation3D12AdvanceTimerEi; size: 0xBC.
void Animation3D::AdvanceTimer(fix32_t dt)
{
    if (!(pAnimData_ != NULL ? 1 : 0))
        return;

    int64_t prod = (int64_t)dt;
    prod = ((playbackSpeed_ * prod) + 0x800) >> 12;
    pAnimData_->time_ += (fix32_t)prod;
    if (GetAnimationFrameCountFix32(pAnimData_) <= pAnimData_->time_)
    {
        if (flags_ & (1 << ANIMATION_FLAG_NOT_LOOPING))
        {
            pAnimData_->time_ = GetAnimationFrameCountFix32(pAnimData_);
        }
        else
        {
            while (GetAnimationFrameCountFix32(pAnimData_) <= pAnimData_->time_)
            {
                pAnimData_->time_ -= GetAnimationFrameCountFix32(pAnimData_);
            }
            if (pAnimData_->time_ < 0)
                pAnimData_->time_ = 0;
        }
    }
}

// Original: arm9/main @ 0x0207E224; symbol: _ZN11Animation3D21GetBasicAnimationDataEv; size: 0x8.
AnimationData* Animation3D::GetBasicAnimationData() { return pAnimData_; }

// Original: arm9/main @ 0x0207E22C; symbol: _ZN11Animation3D16SetAnimationTimeEi; size: 0x10.
void Animation3D::SetAnimationTime(fix32_t to)
{
    if (pAnimData_ != NULL)
        pAnimData_->time_ = to;
}