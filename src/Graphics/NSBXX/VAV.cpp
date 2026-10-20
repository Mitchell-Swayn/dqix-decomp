#include "Graphics/NSBXX/NSBXX.h"
#include "Graphics/NSBXX/RenderCommands_Common.h"
#include "Graphics/NSBXX/Animation.h"

#pragma optimize_for_size off

#if defined(jpn)
#define InitializeModelAnimationFromVAV_UnknownRoleProcedureReferenceRecords data_020f1ddc
#endif

// processing callback for V.AV animations
// Original data: arm9/main @ 0x20f1c70; symbol: data_020f1c70.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 78990b02.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern void (*InitializeModelAnimationFromVAV_UnknownRoleProcedureReferenceRecords)(void* data, AnimationData* anim, int arg);

// Original: arm9/main @ 0x020B992C; symbol: _Z31InitializeModelAnimationFromVAVP13AnimationDataPvP18NSBXXInternalModel; size: 0x4C.
void InitializeModelAnimationFromVAV(AnimationData* anim, void* pvVAV, NSBXXInternalModel* model)
{
    unsigned int index = 0;
    anim->callback_ = InitializeModelAnimationFromVAV_UnknownRoleProcedureReferenceRecords;
    anim->numEntries_ = model->numBoneMatrices_;
    anim->pRawData_ = pvVAV;
    if (index < anim->numEntries_)
    {
        do
        {
            anim->entries_[index] = index | 0x100;
            index++;
        } while (index < anim->numEntries_);
    }
}

// Original: arm9/main @ 0x020B9978; symbol: _Z30VAVAnimationProcessingCallbackPvP13AnimationDatai; size: 0x38.
void VAVAnimationProcessingCallback(void* data, AnimationData* anim, int arg)
{
    int* outVis = (int*)data;
    NSBXXAnimationVAV* vav = (NSBXXAnimationVAV*)anim->pRawData_;
    unsigned int frame = anim->time_ >> 12;
    unsigned int testIndex = frame * vav->numConditions_ + arg;
    *outVis = vav->bitfield_[testIndex >> 5] & (1 << (testIndex & 0x1f));
}