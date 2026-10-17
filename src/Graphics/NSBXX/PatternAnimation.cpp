#include "Graphics/NSBXX/NSBXX.h"

#pragma optimize_for_size off

#define SUBFILE_OFFSETS(nsb) ((uint32_t*)((intptr_t)(nsb) + nsb->headerSize_))

// Original: arm9/main @ 0x020B7694; symbol: NSBXX_GetFirstSubfile; size: 0x10.
void* NSBXX_GetFirstSubfile(NSBXXContainer* nsbxx)
{
    return (char*)nsbxx + SUBFILE_OFFSETS(nsbxx)[0];
}

// Original: arm9/main @ 0x020B76A4; symbol: NSBXX_GetTEXFile; size: 0x40.
NSBXXTex* NSBXX_GetTEXFile(NSBXXContainer* nsbxx)
{
    const uint32_t* subfiles = SUBFILE_OFFSETS(nsbxx);
    if (nsbxx->numSubfiles_ == 1)
    {
        if (nsbxx->signature_ == SIGNATURE_NSBTX)
            return (NSBXXTex*)((intptr_t)nsbxx + subfiles[0]);

        return NULL;
    }
    return (NSBXXTex*)((intptr_t)nsbxx + subfiles[1]);
}

// Original: arm9/main @ 0x020B76E4; symbol: NSBXX_GetObjectFromFirstSubfile; size: 0x5C.
void* NSBXX_GetObjectFromFirstSubfile(NSBXXContainer* nsbxx, unsigned int idx)
{
    if (nsbxx != NULL)
    {
        NSBXXInnerFileCommon* innerData = (NSBXXInnerFileCommon*)((intptr_t)nsbxx + SUBFILE_OFFSETS(nsbxx)[0]);

        intptr_t namelistPtr = (intptr_t)&innerData->nameList;
        uint32_t* pInnerOffset;
        if (namelistPtr != NULL && idx < innerData->nameList.numEntries_)
        {
            uint16_t stride = *(uint16_t*)(namelistPtr + innerData->nameList.offsetToDataStart_);
            pInnerOffset = (uint32_t*)(namelistPtr + innerData->nameList.offsetToDataStart_ + 4 + stride * idx);
        }
        else
        {
            pInnerOffset = NULL;
        }

        if (pInnerOffset != NULL)
        {
            return (char*)innerData + *pInnerOffset;
        }
    }
    return NULL;
}

// Original: arm9/main @ 0x020B7740; symbol: NSBXX_PatternAnimation_GetTextureName; size: 0x2C.
const char* NSBXX_PatternAnimation_GetTextureName(NSBXXAnimationMPT* anim, unsigned int idx)
{
    if (anim != NULL && idx < anim->numTextureNames_)
    {
        return (const char*)((intptr_t)anim + anim->textureNamesOffset_ + idx * 0x10);
    }
    return NULL;
}

// Original: arm9/main @ 0x020B776C; symbol: NSBXX_PatternAnimation_GetPaletteName; size: 0x2C.
const char* NSBXX_PatternAnimation_GetPaletteName(NSBXXAnimationMPT* anim, unsigned int idx)
{
    if (anim != NULL && idx < anim->numPaletteNames_)
    {
        return (const char*)((intptr_t)anim + anim->paletteNamesOffset_ + idx * 0x10);
    }
    return NULL;
}

// Original: arm9/main @ 0x020B7798; symbol: NSBXX_PatternAnimation_GetKeyframe; size: 0x74.
NSBXXAnimationMPT::Track::Keyframe* NSBXX_PatternAnimation_GetKeyframe(
    NSBXXAnimationMPT* anim, uint16_t track, uint16_t frameTime)
{
    NSBXXAnimationMPT::Track* pTrack = NSBXX_PatternAnimation_GetTrack(anim, track);
    NSBXXAnimationMPT::Track::Keyframe* keyframes =
        (NSBXXAnimationMPT::Track::Keyframe*)((intptr_t)anim + pTrack->keyframeArrayOffset_);
    
    // Start with a heuristic for the index
    unsigned int index = (unsigned int)(pTrack->maybeSpeed_4_ * frameTime) >> 12u;

    while (index != 0 && keyframes[index].frameTime_ >= frameTime)
        index--;

    int maxKeyframes = pTrack->numKeyframes_;
    while (index + 1 < maxKeyframes && (keyframes + 1)[index].frameTime_ <= frameTime)
        index++;

    return &keyframes[index];
}

// Original: arm9/main @ 0x020B780C; symbol: NSBXX_PatternAnimation_GetTrack; size: 0x34.
NSBXXAnimationMPT::Track* NSBXX_PatternAnimation_GetTrack(
    NSBXXAnimationMPT* anim, unsigned int track)
{
    intptr_t nameList = (intptr_t)&anim->tracks_;
    if (nameList != 0 && track < anim->tracks_.numEntries_)
    {
        uint16_t stride = *(uint16_t*)(nameList + anim->tracks_.offsetToDataStart_);
        intptr_t ret = nameList + anim->tracks_.offsetToDataStart_ + 4 + stride * track;
        return (NSBXXAnimationMPT::Track*)ret;
    }
    return NULL;
}