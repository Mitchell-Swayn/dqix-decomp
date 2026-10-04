#include "Graphics/NSBXX/JACInternal.h"

void ApplyBindPoseRotation(BoneMatrixRenderData* bmrd)
{  
    RenderCommandHandler* handler = data_0210a274;
    NSBXXBoneMatrix* boneMatrix = handler->boneList_->GetEntryFromu32Offset_v2<NSBXXBoneMatrix>(handler->instructionPointer_[1]);

    intptr_t addrRotation = (intptr_t)(boneMatrix + 1);
    if (!(boneMatrix->flags_ & 1)) // has translation data
        addrRotation += sizeof(NSBXXBoneMatrix::Translation);

    if (!(boneMatrix->flags_ & 2)) // has rotation data
    {
        if (boneMatrix->flags_ & 8) // pivot matrix format
        {
            int pivotForm;
            pivotForm = (boneMatrix->flags_ & 0xf0) >> 4;
            NSBXXBoneMatrix::PivotMatrixData* pivot = (NSBXXBoneMatrix::PivotMatrixData*)addrRotation;
            fix32_t entryA = pivot->a;
            fix32_t entryB = pivot->b;

            func_020ca7d0(&bmrd->rotationMatrix_);
            fix32_t unit = (boneMatrix->flags_ & 0x100) ? -1 << 12 : 1 << 12;

            int indexA = data_020e9284[pivotForm].a;
            int indexB = data_020e9284[pivotForm].b;
            
            bmrd->rotationMatrix_.entries[pivotForm] = unit;
            bmrd->rotationMatrix_.entries[indexA] = entryA;
            bmrd->rotationMatrix_.entries[indexB] = entryB;

            fix32_t entryC = (boneMatrix->flags_ & 0x200) ? -entryB : entryB;
            int indexC = data_020e9284[pivotForm].c;
            bmrd->rotationMatrix_.entries[data_020e9284[pivotForm].c] = entryC;

            fix32_t entryD = (boneMatrix->flags_ & 0x400) ? -entryA : entryA;
            int indexD = data_020e9284[pivotForm].d;
            bmrd->rotationMatrix_.entries[indexD] = entryD;
        }
        else // generic 3x3 matrix format
        {
            bmrd->rotationMatrix_.entries[0] = boneMatrix->m_11;
            NSBXXBoneMatrix::RotationMatrixData* rot = (NSBXXBoneMatrix::RotationMatrixData*)addrRotation;
            bmrd->rotationMatrix_.entries[1] = rot->entries[0];
            bmrd->rotationMatrix_.entries[2] = rot->entries[1];
            bmrd->rotationMatrix_.entries[3] = rot->entries[2];
            bmrd->rotationMatrix_.entries[4] = rot->entries[3];
            bmrd->rotationMatrix_.entries[5] = rot->entries[4];
            bmrd->rotationMatrix_.entries[6] = rot->entries[5];
            bmrd->rotationMatrix_.entries[7] = rot->entries[6];
            bmrd->rotationMatrix_.entries[8] = rot->entries[7];
        }
    }
    else // no rotation data
    {
        bmrd->flags_ |= 2;
    }
}

void CalculateTranslationAmountFrameAligned(fix32_t* out, fix32_t time, NSBXXAnimationJAC::Track::ChannelNonConst* channel, NSBXXAnimationJAC* jac)
{
    unsigned int highWeightFrame, lowWeightFrame;
    unsigned int metadata;
    unsigned int thisFrame = time >> 12;
    fix32_t* samples = (fix32_t*)((intptr_t)jac + channel->samplesOffset_);
    fix16_t* samples16 = (fix16_t*)samples;

    unsigned int averageIndex, directIndex = thisFrame;

    metadata = channel->metadata_;
    // log-rate = 0: every frame is sampled, no need for averaging
    if ((metadata & 0xc0000000) == 0)
        goto compute_directly;

{
    unsigned int endFrame = (metadata & 0x1fff0000) >> 16;

    // log-rate = 1 or 3: case 3 ignored, so only case 1 (sample every 2nd frame)
    if (metadata & 0x40000000)
    {
        if (thisFrame & 1) // odd frame, need to average
        {
            if (thisFrame > endFrame)
            {
                directIndex = (endFrame / 2) + 1;
                goto compute_directly;
            }
            else
            {
                averageIndex = thisFrame / 2;
                goto compute_average;
            }
        }
        else
        {
            directIndex = thisFrame / 2;
            goto compute_directly;
        }
    }
    else // log-rate = 2, sample every 4th frame
    {
        unsigned int mod4 = thisFrame & 3;
        if (mod4 != 0)
        {
            if (thisFrame > endFrame)
            {
                directIndex = (endFrame / 4) + mod4;
                goto compute_directly;
            }
            else if (thisFrame & 1) // odd frame: interpolate with 1/4, 3/4 or vice versa
            {
                if (thisFrame & 2) // 3 mod 4: put weight on the later frame
                {
                    highWeightFrame = (thisFrame / 4) + 1;
                    lowWeightFrame = thisFrame / 4;
                }
                else // 1 mod 4: put weight on the earlier frame
                {
                    lowWeightFrame = (thisFrame / 4) + 1;
                    highWeightFrame = thisFrame / 4;
                }

                if (metadata & 0x20000000) // 16-bit samples
                {
                    fix32_t rescaledHigh = samples16[highWeightFrame] * 3;
                    *out = (rescaledHigh + samples16[lowWeightFrame]) >> 2;
                }
                else
                {
                    int64_t high = samples[highWeightFrame];
                    *out = (high * 3 + samples[lowWeightFrame]) >> 2;
                }
                return;
            }
            else // 2 mod 4: can do 50/50 averaging
            {
                averageIndex = thisFrame / 4;
                goto compute_average;
            }
        }
        else
        {
            directIndex = thisFrame / 4;
            goto compute_directly;
        }
    }
}

compute_average:
    if (metadata & 0x20000000) // 16-bit samples
        *out = (*(samples16 + averageIndex) + *(samples16 + averageIndex + 1)) >> 1;
    else // 32-bit samples
        *out = (*(samples + averageIndex) >> 1) + (*(samples + averageIndex + 1) >> 1);
    return;
compute_directly:
    if (metadata & 0x20000000) // 16-bit samples
        *out = samples16[directIndex];
    else
        *out = samples[directIndex];
}

void CalculateScalingAmountFrameAligned(fix32_t* out, fix32_t time, NSBXXAnimationJAC::Track::ChannelNonConst* channel, NSBXXAnimationJAC* jac)
{
    unsigned int metadata;   
    unsigned int thisFrame = time >> 12;
    
    NSBXXAnimationJAC::ScaleSample32* samples = (NSBXXAnimationJAC::ScaleSample32*)((intptr_t)jac + channel->samplesOffset_);
    NSBXXAnimationJAC::ScaleSample16* samples16 = (NSBXXAnimationJAC::ScaleSample16*)samples;

    metadata = channel->metadata_;
    
    unsigned int averageIdx;
    
    if ((metadata & 0xc0000000) == 0)
        goto compute_directly;

{
    unsigned int endFrame = (metadata & 0x1fff0000) >> 16;

    // log-rate = 1 or 3: case 3 ignored, so only case 1 (sample every 2nd frame)
    if (metadata & 0x40000000)
    {
        if (thisFrame & 1) // odd frame, need to average
        {
            if (thisFrame > endFrame)
            {
                thisFrame = (endFrame / 2) + 1;
                goto compute_directly;
            }
            else
            {
                averageIdx = thisFrame / 2;
                goto compute_average;
            }
        }
        else
        {
            thisFrame = thisFrame / 2;
            goto compute_directly;
        }
    }
    else // log-rate = 2, sample every 4th frame
    {
        unsigned int mod4 = thisFrame & 3;
        if (mod4 != 0)
        {
            if (thisFrame > endFrame)
            {
                // why do we add mod4 here?
                thisFrame = (endFrame / 4) + mod4;
                goto compute_directly;
            }
            else if (thisFrame & 1) // odd frame: interpolate with 1/4, 3/4 or vice versa
            {
                unsigned int highWeightFrame;
                unsigned int lowWeightFrame;
                if (thisFrame & 2) // 3 mod 4: put weight on the later frame
                {
                    highWeightFrame = (thisFrame / 4) + 1;
                    lowWeightFrame = thisFrame / 4;
                }
                else // 1 mod 4: put weight on the earlier frame
                {
                    lowWeightFrame = (thisFrame / 4) + 1;
                    highWeightFrame = thisFrame / 4;
                }

                if (metadata & 0x20000000) // 16-bit samples
                {
                    fix32_t sumPrim = samples16[highWeightFrame].primary_;
                    fix32_t lowPrim = samples16[lowWeightFrame].primary_;
                    sumPrim = sumPrim * 3 + lowPrim;
                    out[0] = sumPrim >> 2;
                    fix32_t sumSec = samples16[highWeightFrame].secondary_;
                    fix32_t lowSec = samples16[lowWeightFrame].secondary_;
                    sumSec = sumSec * 3 + lowSec;
                    out[1] = sumSec >> 2;
                    return;
                }
                else
                {
                    int64_t highPrim = (int64_t)samples[highWeightFrame].primary_ * 3;
                    int64_t lowPrim = samples[lowWeightFrame].primary_;
                    // this assignment is important...
                    int64_t sumPrim = lowPrim;
                    sumPrim = highPrim + lowPrim;
                    out[0] = sumPrim >> 2;
                    int64_t highSec = (int64_t)samples[highWeightFrame].secondary_ * 3;
                    out[1] = (highSec + samples[lowWeightFrame].secondary_) >> 2;
                    return;
                }
            }
            else // 2 mod 4: can do 50/50 averaging
            {
                averageIdx = thisFrame / 4;
                goto compute_average;
            }
        }
        else
        {
            thisFrame = thisFrame / 4;
            goto compute_directly;
        }
    }
}
    
compute_directly:
    if (metadata & 0x20000000)
    {
        out[0] = samples16[thisFrame].primary_;
        out[1] = samples16[thisFrame].secondary_;
    }
    else
    {
        out[0] = samples[thisFrame].primary_;
        out[1] = samples[thisFrame].secondary_;
    }
    return;
compute_average:
    if (metadata & 0x20000000)
    {
        out[0] = ((samples16 + averageIdx)->primary_ + (samples16 + averageIdx + 1)->primary_) >> 1;
        out[1] = ((samples16 + averageIdx)->secondary_ + (samples16 + averageIdx + 1)->secondary_) >> 1;
    }
    else
    {
        out[0] = ((samples + averageIdx)[0].primary_ + (samples + averageIdx)[1].primary_) >> 1;
        out[1] = ((samples + averageIdx)[0].secondary_ + (samples + averageIdx)[1].secondary_) >> 1;
    }
}
