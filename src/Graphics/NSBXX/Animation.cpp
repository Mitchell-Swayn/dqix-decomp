#include "Graphics/NSBXX/Animation.h"

#pragma optimize_for_size off

#if defined(jpn)
#define MIi_CpuClear32 func_020cbeb8

#define InitializeModelAnimation_UnknownRoleInitializedBytes data_020f1dd8
#define PopulateModelRenderContext_UnknownRoleProcedureReferenceRecords data_020f1df0
#define PopulateModelRenderContext_UnknownRoleProcedureReferenceRecords_Variant2 data_020f1df4
#define PopulateModelRenderContext_UnknownRoleProcedureReferenceRecords_Variant3 data_020f1df8
#define InitializeModelAnimation_UnknownRoleInitializedBytes_Variant2 data_020f1dfc
#endif

extern "C"
{
    // memset
    void MIi_CpuClear32(int value, void* dst, unsigned len);
}

// Original data: arm9/main @ 0x20f1c6c; symbol: data_020f1c6c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 05000000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned int InitializeModelAnimation_UnknownRoleInitializedBytes; // number of animation types (5)

// Original data: arm9/main @ 0x20f1c84; symbol: data_020f1c84.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 983f0b02.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern bool (*PopulateModelRenderContext_UnknownRoleProcedureReferenceRecords)(int*, AnimationData*, unsigned int);
// Original data: arm9/main @ 0x20f1c88; symbol: data_020f1c88.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex ac3b0b02.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern bool (*PopulateModelRenderContext_UnknownRoleProcedureReferenceRecords_Variant2)(BoneMatrixRenderData*, AnimationData*, unsigned int);
// Original data: arm9/main @ 0x20f1c8c; symbol: data_020f1c8c.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex d03a0b02.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern bool (*PopulateModelRenderContext_UnknownRoleProcedureReferenceRecords_Variant3)(MaterialRenderData*, AnimationData*, unsigned int);

struct AnimationTypeDescription
{
    NSBXXAnimationSignature signature;
    void (*initializer)(AnimationData* anim, void* pvMAT, NSBXXInternalModel* model);
// Original data: arm9/main @ 0x20f1c90; symbol: data_020f1c90.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 4d00414d.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
} extern InitializeModelAnimation_UnknownRoleInitializedBytes_Variant2[];

// Original: arm9/main @ 0x020B2ACC; symbol: _Z24InitializeModelAnimationP13AnimationDataPvP18NSBXXInternalModelP8NSBXXTex; size: 0xA0.
void InitializeModelAnimation(AnimationData *anim, void *pRawData, NSBXXInternalModel *model, NSBXXTex *tex)
{
    unsigned int animType = 0;
    anim->time_ = 0;
    anim->pRawData_ = pRawData;
    anim->pNext_ = NULL;
    anim->unk_18 = 0x7f;
    anim->weight_ = 1 << 12;
    anim->pTex0_ = tex;
    anim->numEntries_ = 0;
    anim->callback_ = NULL;

    NSBXXAnimationSignature* signature = (NSBXXAnimationSignature*)pRawData;

    unsigned int numAnimationTypes = InitializeModelAnimation_UnknownRoleInitializedBytes;
    if (animType < numAnimationTypes)
    {
        int thisInitial = signature->signatureInitial_;
        while (true)
        {
            NSBXXAnimationSignature* targetSig = &InitializeModelAnimation_UnknownRoleInitializedBytes_Variant2[animType].signature;
            int targetInitial = targetSig->signatureInitial_;
            
            if (thisInitial == targetInitial)
            {
                // annoying but necessary for matching assembly
                NSBXXAnimationSignature* foo = (NSBXXAnimationSignature*)((intptr_t)InitializeModelAnimation_UnknownRoleInitializedBytes_Variant2 + animType * sizeof(AnimationTypeDescription));
                int targetEnd = foo->signatureEnd_;
                if (signature->signatureEnd_ == targetEnd)
                {
                    if (InitializeModelAnimation_UnknownRoleInitializedBytes_Variant2[animType].initializer != NULL)
                        InitializeModelAnimation_UnknownRoleInitializedBytes_Variant2[animType].initializer(anim, pRawData, model);
                    return;
                }
            }
            animType++;
            if (animType >= numAnimationTypes)
                return;
        }
    }
}

// Original: arm9/main @ 0x020B2B6C; symbol: _Z26PopulateModelRenderContextP18ModelRenderContextP18NSBXXInternalModel; size: 0x54.
void PopulateModelRenderContext(ModelRenderContext *context, NSBXXInternalModel *model)
{
    MIi_CpuClear32(0, context, sizeof(ModelRenderContext));
    context->pfnProcessMaterialAnimations_ = PopulateModelRenderContext_UnknownRoleProcedureReferenceRecords_Variant3;
    context->pfnProcessJointAnimations_ = PopulateModelRenderContext_UnknownRoleProcedureReferenceRecords_Variant2;
    context->pfnProcessVisibilityAnimations_ = PopulateModelRenderContext_UnknownRoleProcedureReferenceRecords;
    context->internalModel_ = model;
}

// Original: arm9/main @ 0x020B2BC0; symbol: _Z19AddAnimationsToListPP13AnimationDataS0_; size: 0xB8.
void AddAnimationsToList(AnimationData** pListStart, AnimationData* newEntry)
{
    AnimationData* mainListEntry = *pListStart;
    
    if (mainListEntry == NULL)
    {
        *pListStart = newEntry;
        return;
    }    

    if (mainListEntry->pNext_ == NULL)
    {
        if (mainListEntry->unk_18 > newEntry->unk_18)
        {
            AnimationData* newEntrySequenceEnd = newEntry;
            if (newEntrySequenceEnd->pNext_ != NULL)
            {
                do
                {
                    newEntrySequenceEnd = newEntrySequenceEnd->pNext_;
                } while (newEntrySequenceEnd->pNext_ != NULL);
            }
            newEntrySequenceEnd->pNext_ = mainListEntry;
            *pListStart = newEntry;
        }
        else
        {
            mainListEntry->pNext_ = newEntry;
        }
        return;
    }
    AnimationData* mainListNextEntry = mainListEntry->pNext_;
    
    if (mainListEntry->pNext_ != NULL)
    {
        unsigned int targetOrder = newEntry->unk_18;
        do
        {
            unsigned int nextOrder = mainListNextEntry->unk_18;
            if (nextOrder >= targetOrder)
            {
                AnimationData* newEntrySequenceEnd = newEntry;
                if (newEntrySequenceEnd->pNext_ != NULL)
                {
                    do
                    {
                        newEntrySequenceEnd = newEntrySequenceEnd->pNext_;
                    } while (newEntrySequenceEnd->pNext_ != NULL);
                }
                mainListEntry->pNext_ = newEntry;
                newEntrySequenceEnd->pNext_ = mainListNextEntry;
                return;
            }
            mainListEntry = mainListNextEntry;
            mainListNextEntry = mainListNextEntry->pNext_;
        } while (mainListEntry->pNext_ != NULL);
    }
    // If we get here, need to insert the new entry at the end, and
    // mainListEntry points to the final one currently in the list
    mainListEntry->pNext_ = newEntry;
}

// the exact same function exists in RenderCommands.cpp so we give it a slightly
// different name to distinguish it. Later can make both versions static
// Original: arm9/main @ 0x020B2C78; symbol: _Z29PopulateBitfieldFromAnimData0PjP13AnimationData; size: 0x68.
void PopulateBitfieldFromAnimData0(unsigned int* bitfield, AnimationData* anim)
{
    if (anim == NULL)
        return;

    do
    {
        int counter = 0;
        if (counter < anim->numEntries_)
        {
            do
            {
                if (anim->entries_[counter] & 0x100)
                {
                    bitfield[counter >> 5] |= 1 << (counter & 0x1f);
                }
                counter++;
            } while (counter < anim->numEntries_);
        }
        anim = anim->pNext_;
    } while (anim != NULL);
}

// Original: arm9/main @ 0x020B2CE0; symbol: _Z33AddAnimationsToModelRenderContextP18ModelRenderContextP13AnimationData; size: 0x80.
void AddAnimationsToModelRenderContext(ModelRenderContext *context, AnimationData *anim)
{
    if (anim == NULL || anim->pRawData_ == NULL)
        return;

    NSBXXAnimationSignature* signature = (NSBXXAnimationSignature*)anim->pRawData_;

    switch (signature->signatureInitial_)
    {
    case 'M':
        PopulateBitfieldFromAnimData0(context->animatedMaterials_, anim);
        AddAnimationsToList(&context->materialAnimations_, anim);
        break;
    case 'J':
        PopulateBitfieldFromAnimData0(context->animatedBoneMatrices_, anim);
        AddAnimationsToList(&context->jointAnimations_, anim);
        break;
    case 'V':
        PopulateBitfieldFromAnimData0(context->animatedVisibilityConditions_, anim);
        AddAnimationsToList(&context->visibilityAnimations_, anim);
        break;
    }
}

// can be made static
// Original: arm9/main @ 0x020B2D60; symbol: _Z23RemoveAnimationFromListPP13AnimationDataS0_; size: 0x74.
bool RemoveAnimationFromList(AnimationData** pList, AnimationData* entry)
{
    AnimationData* firstEntry = *pList;
    if (*pList == NULL)
        return false;
    

    if (firstEntry == entry)
    {
        *pList = firstEntry->pNext_;
        entry->pNext_ = NULL;
        return true;
    }
    
    AnimationData* nextEntry = firstEntry->pNext_;
    AnimationData* listEntry = firstEntry;
    if (nextEntry != NULL)
    {
        do
        {
            if (nextEntry == entry)
            {
                listEntry->pNext_ = nextEntry->pNext_;
                nextEntry->pNext_ = NULL;
                return true;
            }
            listEntry = nextEntry;
            nextEntry = nextEntry->pNext_;
        } while (nextEntry != NULL);
    }

    return false;
}

// Original: arm9/main @ 0x020B2DD4; symbol: _Z37RemoveAnimationFromModelRenderContextP18ModelRenderContextP13AnimationData; size: 0x54.
void RemoveAnimationFromModelRenderContext(ModelRenderContext *context, AnimationData *anim)
{
    if (RemoveAnimationFromList(&context->materialAnimations_, anim) ||
        RemoveAnimationFromList(&context->jointAnimations_, anim) ||
        RemoveAnimationFromList(&context->visibilityAnimations_, anim))
    {
        context->flags_ |= (1 << 4);
    }
}

// Original: arm9/main @ 0x020B2E28; symbol: _Z38SetModelRenderContextRenderCommandHookP18ModelRenderContextPFvP20RenderCommandHandlerEiii; size: 0x14.
void SetModelRenderContextRenderCommandHook(ModelRenderContext *context,
    RenderCommandHook hook, int unknown, int commandID, int stage)
{
    context->renderCommandHook_ = hook;
    context->renderCommandHookCommandID_ = commandID;
    context->renderCommandHookStage_ = stage;
}