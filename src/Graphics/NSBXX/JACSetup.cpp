#include "Graphics/NSBXX/JACInternal.h"

void InitializeModelAnimationFromJAC(AnimationData* anim, void* pvJAC, NSBXXInternalModel* model)
{
    NSBXXAnimationJAC* jac = (NSBXXAnimationJAC*)pvJAC;
    anim->pRawData_ = jac;
    anim->callback_ = data_020f1c74;
    anim->numEntries_ = model->numBoneMatrices_;
    func_020ca390(0, anim->entries_, 2 * anim->numEntries_);

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

void ApplyBindPoseTranslation(BoneMatrixRenderData* bmrd)
{
    RenderCommandHandler* handler = data_0210a274;
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

void ApplyBindPoseScaling(BoneMatrixRenderData* bmrd)
{
    RenderCommandHandler* handler = data_0210a274;
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
