#include "Graphics/NSBXX/JACInternal.h"

// Original: arm9/main @ 0x020B7840; symbol: _Z31InitializeModelAnimationFromJACP13AnimationDataPvP18NSBXXInternalModel; size: 0x7C.
void InitializeModelAnimationFromJAC(AnimationData* anim, void* pvJAC, NSBXXInternalModel* model)
{
    NSBXXAnimationJAC* jac = (NSBXXAnimationJAC*)pvJAC;
    anim->pRawData_ = jac;
    anim->callback_ = InitializeModelAnimationFromJAC_UnknownRoleProcedureReferenceRecords;
    anim->numEntries_ = model->numBoneMatrices_;
    MIi_CpuClear16(0, anim->entries_, 2 * anim->numEntries_);

    unsigned int trackIdx = 0;
    uint16_t* trackOffsets = jac->trackOffsets_;
    if (trackIdx < jac->numTracks_)
    {
        do
        {
            anim->entries_[trackIdx] = ((NSBXXAnimationJAC::Track*)((intptr_t)jac + trackOffsets[trackIdx]))->flagsAndTargetBoneMatrix_ >> 24 | 0x100;
            trackIdx++;
        } while (trackIdx < jac->numTracks_);
    }
}

// Original: arm9/main @ 0x020B78BC; symbol: _Z30JACAnimationProcessingCallbackPvP13AnimationDatai; size: 0x3C.
void JACAnimationProcessingCallback(void* data, AnimationData* anim, int arg)
{
    BoneMatrixRenderData* boneRenderData = (BoneMatrixRenderData*)data;

    fix32_t time = anim->time_;
    NSBXXAnimationJAC* jac = (NSBXXAnimationJAC*)anim->pRawData_;

    if (time >= jac->numFrames_ << 12)
        time = (jac->numFrames_ << 12) - 1;
    else if (time < 0)
        time = 0;

    CalculateBoneMatrixRenderDataFromJAC(jac, arg, time, boneRenderData);
}

// Original: arm9/main @ 0x020B78F8; symbol: _Z24ApplyBindPoseTranslationP20BoneMatrixRenderData; size: 0x98.
void ApplyBindPoseTranslation(BoneMatrixRenderData* bmrd)
{
    RenderCommandHandler* handler = ApplyBindPoseScaling_UnknownRoleZeroInitializedStorage;
    // this is super cursed, but I guess this executes during command 6 when
    // ip[1] holds the bone index to apply stuff to
    NSBXXBoneMatrix* boneMatrix = handler->boneList_->GetEntryFromu32Offset_v2<NSBXXBoneMatrix>(handler->instructionPointer_[1]);
    if (boneMatrix->flags_ & 1) // no translation data
    {
        bmrd->flags_ |= 4;
    }
    else
    {
        NSBXXBoneMatrix::Translation* tdata = (NSBXXBoneMatrix::Translation*)((intptr_t)boneMatrix + 4);
        bmrd->translate_.x = tdata->x;
        bmrd->translate_.y = tdata->y;
        bmrd->translate_.z = tdata->z;
    }
}

// Original: arm9/main @ 0x020B7990; symbol: _Z20ApplyBindPoseScalingP20BoneMatrixRenderData; size: 0x90.
void ApplyBindPoseScaling(BoneMatrixRenderData* bmrd)
{
    RenderCommandHandler* handler = ApplyBindPoseScaling_UnknownRoleZeroInitializedStorage;
    uint8_t* ip = handler->instructionPointer_;
    NSBXXBoneMatrix* boneMatrix = handler->boneList_->GetEntryFromu32Offset_v2<NSBXXBoneMatrix>(ip[1]);
    intptr_t addrScaling = (intptr_t)(boneMatrix + 1);
    unsigned int flags = boneMatrix->flags_;
    if (!(flags & 1)) // has translation data
        addrScaling += sizeof(NSBXXBoneMatrix::Translation);
    if (!(flags & 2))
    {
        if (flags & 8)
            addrScaling += sizeof(NSBXXBoneMatrix::PivotMatrixData);
        else
            addrScaling += sizeof(NSBXXBoneMatrix::RotationMatrixData);
    }
    handler->boneMatrixRenderDataScalePopulateProc_(bmrd, (NSBXXBoneMatrix::Scaling*)addrScaling, ip, flags);
}
