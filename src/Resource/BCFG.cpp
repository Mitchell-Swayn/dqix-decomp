#include "Resource/BCFG.h"
#include "Resource/Script.h"

#pragma pool_strings on
#pragma dont_reuse_strings off

struct Struct_02104b10
{
    SafeAllocator* allocator;
    BCFG* pBCFG;
} static currentBCFGScriptData;

// Original: arm9/main @ 0x020343A0; symbol: _Z20BCFGScript_Opcode_64PN6Script9ParameterEi; size: 0x28.
int BCFGScript_AllocateAnimationEntries(Script::Parameter* params, int paramCount)
{
    currentBCFGScriptData.pBCFG->AllocateAnimationEntries(currentBCFGScriptData.allocator, params[0].ToInt());
    return 1;
}

// Original: arm9/main @ 0x020343C8; symbol: _Z20BCFGScript_Opcode_65PN6Script9ParameterEi; size: 0x8.
int BCFGScript_Opcode_65(Script::Parameter* params, int paramCount)
{
    return 1;
}

// Original: arm9/main @ 0x020343D0; symbol: _Z20BCFGScript_Opcode_66PN6Script9ParameterEi; size: 0xA8.
int BCFGScript_InsertAnimationRecord(Script::Parameter* params, int paramCount)
{
    const char* name = params[0].ToString();
    int success;
    if (name == NULL)
        success = false;
    else
    {
        BCFG::AnimationRecord entry;
        strcpy(entry.name, name);
        entry.startTime = 4096 * params[1].ToFloat();
        entry.endTime = 4096 * params[2].ToFloat();
        entry.frameRate = 4096 * params[3].ToFloat();
        entry.firstSizeC = NULL;
        entry.firstAlt = 0;
        currentBCFGScriptData.pBCFG->InsertAnimationRecord(&entry);
        success = true;
    }
    return success;
}

// Original: arm9/main @ 0x02034478; symbol: _Z20BCFGScript_Opcode_6aPN6Script9ParameterEi; size: 0x28.
int BCFGScript_AllocateSizeCEntries(Script::Parameter* params, int paramCount)
{
    currentBCFGScriptData.pBCFG->AllocateSizeCEntries(currentBCFGScriptData.allocator, params[0].ToInt());
    return 1;
}

// Original: arm9/main @ 0x020344A0; symbol: _Z20BCFGScript_Opcode_6bPN6Script9ParameterEi; size: 0x8.
int BCFGScript_Opcode_6b(Script::Parameter* params, int paramCount)
{
    return 1;
}

// when enemies have these it's nearly always only attack1 or attack1a,
// i.e. the regular attack.
// Original: arm9/main @ 0x020344A8; symbol: _Z20BCFGScript_Opcode_6cPN6Script9ParameterEi; size: 0x70.
int BCFGScript_InsertSizeCEntry(Script::Parameter* params, int paramCount)
{
    BCFG::SizeCEntry entry;

    entry.animationIndex = currentBCFGScriptData.pBCFG->SearchAnimationByName(params[0].ToString());
    entry.unk_4 = 4096 * params[1].ToFloat();
    entry.unk_0 = params[2].ToInt();
    currentBCFGScriptData.pBCFG->InsertSizeCEntry(&entry);
    return 1;
}

// Original: arm9/main @ 0x02034518; symbol: _Z20BCFGScript_Opcode_6dPN6Script9ParameterEi; size: 0x28.
int BCFGScript_AllocateAltSizeCEntries(Script::Parameter* params, int paramCount)
{
    currentBCFGScriptData.pBCFG->AllocateAltSizeCEntries(currentBCFGScriptData.allocator, params[0].ToInt());
    return 1;
}

// Original: arm9/main @ 0x02034540; symbol: _Z20BCFGScript_Opcode_6ePN6Script9ParameterEi; size: 0x8.
int BCFGScript_Opcode_6e(Script::Parameter* params, int paramCount)
{
    return 1;
}

// Original: arm9/main @ 0x02034548; symbol: _Z20BCFGScript_Opcode_6fPN6Script9ParameterEi; size: 0x70.
int BCFGScript_InsertAltSizeCEntry(Script::Parameter* params, int paramCount)
{
    BCFG::AltSizeCEntry entry;

    entry.animationIndex = currentBCFGScriptData.pBCFG->SearchAnimationByName(params[0].ToString());
    entry.triggerTime = 4096 * params[1].ToFloat();
    entry.maybeSoundEffect = params[2].ToInt();
    currentBCFGScriptData.pBCFG->InsertAltSizeCEntry(&entry);
    return 1;
}

// Original: arm9/main @ 0x020345B8; symbol: _Z20BCFGScript_Opcode_71PN6Script9ParameterEi; size: 0x28.
int BCFGScript_SetRootBoneName(Script::Parameter* params, int paramCount)
{
    currentBCFGScriptData.pBCFG->MaybeSetRootBoneName(currentBCFGScriptData.allocator, params[0].ToString());
    return 1;
}

Script::OpcodeLookupEntry bcfgScriptOpcodes[] = {
    { 0x64, &BCFGScript_AllocateAnimationEntries },
    { 0x65, &BCFGScript_Opcode_65 },
    { 0x66, &BCFGScript_InsertAnimationRecord },
    { 0x6a, &BCFGScript_AllocateSizeCEntries },
    { 0x6b, &BCFGScript_Opcode_6b },
    { 0x6c, &BCFGScript_InsertSizeCEntry },
    { 0x6d, &BCFGScript_AllocateAltSizeCEntries },
    { 0x6e, &BCFGScript_Opcode_6e },
    { 0x6f, &BCFGScript_InsertAltSizeCEntry },
    { 0x71, &BCFGScript_SetRootBoneName },
    { 0 }
};

// Original: arm9/main @ 0x020345E0; symbol: _ZN4BCFG5ResetEv; size: 0x3C.
void BCFG::Reset()
{
    animations_ = NULL;
    maybeAnimationCount = 0;
    maybeAnimationCapacity = 0;
    sizeCEntries_ = NULL;
    sizeCCapacity_ = 0;
    sizeCCount_ = 0;
    altSizeCEntries_ = NULL;
    altSizeCCount_ = 0;
    altSizeCCapacity_ = 0;
    unknown_18 = 0xffff;
    maybeRootBoneName_ = NULL;
}

// Original: arm9/main @ 0x0203461C; symbol: _ZN4BCFG14LoadFromScriptEP13SafeAllocatorPKvj; size: 0x98.
void BCFG::LoadFromScript(SafeAllocator* alloc, const void *data, unsigned int length)
{
    if (length != 0 && data != NULL)
    {
        currentBCFGScriptData.pBCFG = this;
        currentBCFGScriptData.allocator = alloc;
        Script script;           
        script.Initialize();
        script.SetOpcodeLookup(bcfgScriptOpcodes);
        script.Load(data, length);
        script.Execute();
        if (currentBCFGScriptData.pBCFG->maybeRootBoneName_ == NULL)
            currentBCFGScriptData.pBCFG->MaybeSetRootBoneName(alloc, "waist");
        currentBCFGScriptData.pBCFG = NULL;
        currentBCFGScriptData.allocator = NULL;
    }
}

// Original: arm9/main @ 0x020346B4; symbol: _ZN4BCFG24AllocateAnimationEntriesEP13SafeAllocatori; size: 0x44.
void BCFG::AllocateAnimationEntries(SafeAllocator *alloc, int count)
{
    if (alloc == NULL)
        return;

    animations_ = (AnimationRecord*)alloc->Allocate(count * sizeof(AnimationRecord));
    if (animations_ != NULL)
    {
        maybeAnimationCount = 0;
        maybeAnimationCapacity = count;
    }
    else
    {
        maybeAnimationCount = 0;
        maybeAnimationCapacity = 0;
    }
}

// Original: arm9/main @ 0x020346F8; symbol: _ZN4BCFG21InsertAnimationRecordEPKNS_15AnimationRecordE; size: 0x70.
void BCFG::InsertAnimationRecord(const AnimationRecord *entry)
{
    if (maybeAnimationCapacity > maybeAnimationCount)
    {
        AnimationRecord* dest = &animations_[maybeAnimationCount++];
        COPY_ARRAY(dest->name, entry->name);
        dest->startTime = entry->startTime;
        dest->endTime = entry->endTime;
        dest->frameRate = entry->frameRate;
        dest->firstSizeC = entry->firstSizeC;
        dest->firstAlt = entry->firstAlt;
    }
}

// Original: arm9/main @ 0x02034768; symbol: _ZN4BCFG21SearchAnimationByNameEPKc; size: 0x4C.
int BCFG::SearchAnimationByName(const char* name)
{
    for (int i = 0; i < maybeAnimationCount; i++)
    {
        if (strcmp(animations_[i].name, name) == 0)
            return i;
    }
    return -1;
}

// Original: arm9/main @ 0x020347B4; symbol: _ZN4BCFG18GetAnimationRecordEi; size: 0x2C.
BCFG::AnimationRecord* BCFG::GetAnimationRecord(int idx)
{
    if (idx < 0 || maybeAnimationCount <= idx)
        return NULL;
    return &animations_[idx];
}

// Original: arm9/main @ 0x020347E0; symbol: _ZNK4BCFG16GetNumAnimationsEv; size: 0x8.
int BCFG::GetNumAnimations() const
{
    return maybeAnimationCount;
}

// Original: arm9/main @ 0x020347E8; symbol: _ZN4BCFG20AllocateSizeCEntriesEP13SafeAllocatori; size: 0x38.
void BCFG::AllocateSizeCEntries(SafeAllocator *alloc, int count)
{
    sizeCEntries_ = (SizeCEntry*)alloc->Allocate(count * sizeof(SizeCEntry));
    if (sizeCEntries_ != NULL)
    {
        sizeCCapacity_ = count;
        sizeCCount_ = 0;
    }
    else
    {
        sizeCCapacity_ = 0;
        sizeCCount_ = 0;
    }
}

// Original: arm9/main @ 0x02034820; symbol: _ZN4BCFG16InsertSizeCEntryEPKNS_10SizeCEntryE; size: 0x94.
void BCFG::InsertSizeCEntry(const SizeCEntry *entry)
{
    if (sizeCCapacity_ > sizeCCount_)
    {
        AnimationRecord* anim = GetAnimationRecord(entry->animationIndex);
        if (anim == NULL)
            return;
        SizeCEntry* dest = &sizeCEntries_[sizeCCount_];
        dest->unk_0 = entry->unk_0;
        dest->animationIndex = entry->animationIndex;
        dest->unk_4 = entry->unk_4;
        dest->pNext = entry->pNext;
        sizeCEntries_[sizeCCount_].pNext = anim->firstSizeC;
        anim->firstSizeC = &sizeCEntries_[sizeCCount_];
        sizeCCount_++;
    }
}

// Original: arm9/main @ 0x020348B4; symbol: _ZN4BCFG23AllocateAltSizeCEntriesEP13SafeAllocatori; size: 0x38.
void BCFG::AllocateAltSizeCEntries(SafeAllocator *alloc, int count)
{
    altSizeCEntries_ = (AltSizeCEntry*)alloc->Allocate(count * sizeof(AltSizeCEntry));
    if (altSizeCEntries_ != NULL)
    {
        altSizeCCapacity_ = count;
        altSizeCCount_ = 0;
    }
    else
    {
        altSizeCCapacity_ = 0;
        altSizeCCount_ = 0;
    }
}

// Original: arm9/main @ 0x020348EC; symbol: _ZN4BCFG19InsertAltSizeCEntryEPKNS_13AltSizeCEntryE; size: 0x94.
void BCFG::InsertAltSizeCEntry(const AltSizeCEntry *entry)
{
    if (altSizeCCapacity_ > altSizeCCount_)
    {
        AnimationRecord* anim = GetAnimationRecord(entry->animationIndex);
        if (anim == NULL)
            return;
        AltSizeCEntry* dest = &altSizeCEntries_[altSizeCCount_];
        dest->maybeSoundEffect = entry->maybeSoundEffect;
        dest->animationIndex = entry->animationIndex;
        dest->triggerTime = entry->triggerTime;
        dest->pNext = entry->pNext;
        altSizeCEntries_[altSizeCCount_].pNext = anim->firstAlt;
        anim->firstAlt = &altSizeCEntries_[altSizeCCount_];
        altSizeCCount_++;
    }
}

// Original: arm9/main @ 0x02034980; symbol: _ZN4BCFG20MaybeSetRootBoneNameEP13SafeAllocatorPKc; size: 0x40.
void BCFG::MaybeSetRootBoneName(SafeAllocator *alloc, const char *name)
{
    maybeRootBoneName_ = (char*)alloc->Allocate(strlen(name) + 1);
    if (maybeRootBoneName_ != NULL)
        strcpy(maybeRootBoneName_, name);
}

// Original: arm9/main @ 0x020349C0; symbol: _ZN4BCFG20MaybeGetRootBoneNameEv; size: 0x8.
const char *BCFG::MaybeGetRootBoneName()
{
    return maybeRootBoneName_;
}