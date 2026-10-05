#include "Graphics/NSBXX/JACInternal.h"

void CalculateScalingAmountSmooth(fix32_t* out, fix32_t time, NSBXXAnimationJAC::Track::ChannelNonConst* channel, NSBXXAnimationJAC* jac)
{
    NSBXXAnimationJAC::ScaleSample32* samples = (NSBXXAnimationJAC::ScaleSample32*)((intptr_t)jac + channel->samplesOffset_);
    NSBXXAnimationJAC::ScaleSample16* samples16 = (NSBXXAnimationJAC::ScaleSample16*)samples;
    unsigned int flags = channel->metadata_;
    unsigned int frameIdx = time >> 12;
    unsigned int lerpEndIdx;

    int preMultiply;
    int rightShift;

    // at end of animation
    if (jac->numFrames_ - 1 == frameIdx)
    {
        if (flags & 0xc0000000) // log-rate != 0, i.e. samples less than once per frame
        {
            if (flags & 0x40000000) // log-rate = 1
            {
                frameIdx = (frameIdx & 1) + (frameIdx >> 1);
            }
            else // log-rate = 2
            {
                frameIdx = (frameIdx & 3) + (frameIdx >> 2);
            }
        }

        if (jac->unk_8 & 2)// probably means animation is looping?
        {
            lerpEndIdx = 0;
        }
        else
        {
            if (flags & 0x20000000) // 16-bit samples
            {
                out[0] = samples16[frameIdx].primary_;
                out[1] = samples16[frameIdx].secondary_;
            }
            else
            {
                out[0] = samples[frameIdx].primary_;
                out[1] = samples[frameIdx].secondary_;
            }
            return;
        }       
    }
    else if ((flags & 0xc0000000) != 0)
    {
        unsigned int endFrame = (flags & 0x1fff0000) >> 0x10;
        if (flags & 0x40000000) // log-rate = 1
        {
            if (frameIdx >= endFrame)
            {
                frameIdx = endFrame / 2;
                lerpEndIdx = frameIdx + 1;
            }
            else
            {
                frameIdx = frameIdx / 2;
                lerpEndIdx = frameIdx + 1;
                time &= 0x1fff;
                preMultiply = 2;
                rightShift = 1;
                goto skip_default_values;
            }
        }
        else // log-rate 2
        {
            if (frameIdx >= endFrame)
            {
                frameIdx = (frameIdx & 3) + (frameIdx / 4);
                lerpEndIdx = frameIdx + 1;
            }               
            else
            {
                frameIdx = frameIdx / 4;
                lerpEndIdx = frameIdx + 1;
                time &= 0x3fff;
                preMultiply = 4;
                rightShift = 2;
                goto skip_default_values;
            }
        }
    }
    else
        lerpEndIdx = frameIdx + 1;

default_values:
    time &= 0xfff;
    preMultiply = 1;
    rightShift = 0;
skip_default_values:
    fix32_t primaryLerp0;
    fix32_t primaryLerp1;
    fix32_t secondaryLerp0;
    fix32_t secondaryLerp1;
    if (flags & 0x20000000) // 16-bit samples
    {
        primaryLerp0 = samples16[frameIdx].primary_;
        secondaryLerp0 = samples16[frameIdx].secondary_;
        primaryLerp1 = samples16[lerpEndIdx].primary_;
        secondaryLerp1 = samples16[lerpEndIdx].secondary_;
    }
    else
    {
        primaryLerp0 = samples[frameIdx].primary_;
        secondaryLerp0 = samples[frameIdx].secondary_;
        primaryLerp1 = samples[lerpEndIdx].primary_;
        secondaryLerp1 = samples[lerpEndIdx].secondary_;
    }

    out[0] = (primaryLerp0 * preMultiply + ((time * (primaryLerp1 - primaryLerp0)) >> 12)) >> rightShift;
    out[1] = (secondaryLerp0 * preMultiply + ((time * (secondaryLerp1 - secondaryLerp0)) >> 12)) >> rightShift;
}

void CalculateRotationFrameAligned(Matrix3x3* out, fix32_t time, NSBXXAnimationJAC::Track::ChannelNonConst* channel, NSBXXAnimationJAC* jac)
{
    unsigned int flags = channel->metadata_;
    unsigned int frameIdx = time >> 12;
    unsigned int averageIdx;
    
    unsigned int basisOffset;
    unsigned int pivotOffset = jac->pivotDataOffset_;
    basisOffset = jac->basisMatricesOffset_;
    uint16_t* samples = (uint16_t*)((intptr_t)jac + channel->samplesOffset_);

    if ((flags & 0xc0000000) == 0)
        goto calculate_exact_frame;
    
{
    unsigned int endFrame = (flags & 0x1fff0000) >> 16;
    if (flags & 0x40000000) // log(rate) = 1, sample every second frame
    {
        if (frameIdx & 1)
        {
            if (frameIdx > endFrame)
            {
                frameIdx = (endFrame / 2) + 1;
                goto calculate_exact_frame;
            }
            else
            {
                averageIdx = (frameIdx / 2);
                goto calculate_by_average;
            }
        }
        else
        {
            frameIdx = frameIdx / 2;
            goto calculate_exact_frame;
        }
    }
    else
    {
        unsigned int mod4 = frameIdx & 3;
        if (mod4 != 0)
        {
            if (frameIdx > endFrame)
            {
                frameIdx = mod4 + (endFrame / 4);
                goto calculate_exact_frame;
            }
            else if (frameIdx & 1)
            {
                unsigned int lowWeightFrame;
                unsigned int highWeightFrame;
                int anyBasisMatrix = 0;
                if (frameIdx & 2)
                {
                    lowWeightFrame = frameIdx / 4;
                    highWeightFrame = lowWeightFrame + 1;
                }
                else
                {
                    highWeightFrame = frameIdx / 4;
                    lowWeightFrame = highWeightFrame + 1;
                }

                
                anyBasisMatrix |= GetMatrixFromIndex(out, (intptr_t)jac + pivotOffset,
                    (intptr_t)jac + basisOffset, samples[highWeightFrame]);
                Matrix3x3 tempMatrix;
                anyBasisMatrix |= GetMatrixFromIndex(&tempMatrix, (intptr_t)jac + pivotOffset,
                    (intptr_t)jac + basisOffset, samples[lowWeightFrame]);

                out->entries[0] = tempMatrix.entries[0] + out->entries[0] * 3;
                out->entries[1] = tempMatrix.entries[1] + out->entries[1] * 3;
                out->entries[2] = tempMatrix.entries[2] + out->entries[2] * 3;
                out->entries[3] = tempMatrix.entries[3] + out->entries[3] * 3;
                out->entries[4] = tempMatrix.entries[4] + out->entries[4] * 3;
                out->entries[5] = tempMatrix.entries[5] + out->entries[5] * 3;
                Vector3fix_Normalize(&out->rows[0], &out->rows[0]);
                Vector3fix_Normalize(&out->rows[1], &out->rows[1]);
                if (!anyBasisMatrix)
                {
                    out->entries[6] = tempMatrix.entries[6] + out->entries[6] * 3;
                    out->entries[7] = tempMatrix.entries[7] + out->entries[7] * 3;
                    out->entries[8] = tempMatrix.entries[8] + out->entries[8] * 3;
                    Vector3fix_Normalize(&out->rows[2], &out->rows[2]);
                }
                else
                    CalculateThirdRowByCrossProduct(out);
                return;
            }
            else // frameIdx is even, i.e. 2 mod 4, can do 50/50 average
            {
                averageIdx = frameIdx / 4;
                goto calculate_by_average;
            }
        }
        else
        {
            frameIdx = frameIdx / 4;
            goto calculate_exact_frame;
        }
    }
}

calculate_by_average:
{
    Matrix3x3 tempMatrix;
    int anyBasisMatrix = 0;
    anyBasisMatrix |= GetMatrixFromIndex(out, (intptr_t)jac + pivotOffset,
        (intptr_t)jac + basisOffset, (samples + averageIdx)[0]);
    anyBasisMatrix |= GetMatrixFromIndex(&tempMatrix, (intptr_t)jac + pivotOffset,
        (intptr_t)jac + basisOffset, (samples + averageIdx)[1]);

    out->entries[0] += tempMatrix.entries[0];
    out->entries[1] += tempMatrix.entries[1];
    out->entries[2] += tempMatrix.entries[2];
    out->entries[3] += tempMatrix.entries[3];
    out->entries[4] += tempMatrix.entries[4];
    out->entries[5] += tempMatrix.entries[5];
    Vector3fix_Normalize(&out->rows[0], &out->rows[0]);
    Vector3fix_Normalize(&out->rows[1], &out->rows[1]);

    if (!anyBasisMatrix) // both pivot matrices
    {
        out->entries[6] += tempMatrix.entries[6];
        out->entries[7] += tempMatrix.entries[7];
        out->entries[8] += tempMatrix.entries[8];
        Vector3fix_Normalize(&out->rows[2], &out->rows[2]);
    }
    else
        CalculateThirdRowByCrossProduct(out);

    return;
}
calculate_exact_frame:
{
    bool isBasis = GetMatrixFromIndex(out, (intptr_t)jac + pivotOffset,
        (intptr_t)jac + basisOffset, samples[frameIdx]);
    if (isBasis)
        CalculateThirdRowByCrossProduct(out);
    else
        Vector3fix_Normalize(&out->rows[2], &out->rows[2]);
}
}

void CalculateRotationSmooth(Matrix3x3* out, fix32_t time, NSBXXAnimationJAC::Track::ChannelNonConst* channel, NSBXXAnimationJAC* jac)
{
    unsigned int basisOffset, pivotOffset;
    pivotOffset = jac->pivotDataOffset_;
    basisOffset = jac->basisMatricesOffset_;
    unsigned int flags = channel->metadata_;
    
    unsigned int frameBIdx;
    unsigned int frameAIdx;
    fix32_t reducedTime;
    int preMultiply;
    uint16_t* samples = (uint16_t*)((intptr_t)jac + channel->samplesOffset_);
    
    frameAIdx = time >> 12;

    if (frameAIdx == jac->numFrames_ - 1)
    {
        if ((flags & 0xc0000000) != 0)
        {
            if (flags & 0x40000000)
            {
                frameAIdx = (frameAIdx & 1) + (frameAIdx / 2);
            }
            else
            {
                frameAIdx = (frameAIdx & 3) + (frameAIdx / 4);
            }
        }
        if (jac->unk_8 & 2)
        {
            frameBIdx = 0;
        }
        else
        {
            bool isBasis = GetMatrixFromIndex(out, (intptr_t)jac + pivotOffset,
                (intptr_t)jac + basisOffset, samples[frameAIdx]);
            if (isBasis)
                CalculateThirdRowByCrossProduct(out);
            else
                Vector3fix_Normalize(&out->rows[2], &out->rows[2]);
            return;    
        }
    }
    else if ((flags & 0xc0000000) != 0)
    {
        unsigned int endFrame = (flags & 0x1fff0000) >> 16;
        if (flags & 0x40000000)
        {
            if (frameAIdx >= endFrame)
            {
                frameAIdx = endFrame / 2;
                frameBIdx = frameAIdx + 1;
            }
            else
            {
                frameAIdx = frameAIdx / 2;
                frameBIdx = frameAIdx + 1;
                reducedTime = time & 0x1fff;
                preMultiply = 2;
                goto skip_default_values;
            }
        }
        else
        {
            if (frameAIdx >= endFrame)
            {
                frameAIdx = (frameAIdx & 3) + (frameAIdx / 4);
                frameBIdx = frameAIdx + 1;
            }
            else
            {
                frameAIdx = frameAIdx / 4;
                frameBIdx = frameAIdx + 1;
                reducedTime = time & 0x3fff;
                preMultiply = 4;
                goto skip_default_values;
            }
        }
    }
    else
    {
        frameBIdx = frameAIdx + 1;
    }

default_values:
    reducedTime = time & 0xfff;
    preMultiply = 1;
skip_default_values:
    int anyBasisMatrices = 0;
    Matrix3x3 matrixA;
    Matrix3x3 matrixB;

    anyBasisMatrices |= GetMatrixFromIndex(&matrixA, (intptr_t)jac + pivotOffset,
        (intptr_t)jac + basisOffset, samples[frameAIdx]);
    anyBasisMatrices |= GetMatrixFromIndex(&matrixB, (intptr_t)jac + pivotOffset,
        (intptr_t)jac + basisOffset, samples[frameBIdx]);

    out->entries[0] = matrixA.entries[0] * preMultiply + ((reducedTime * (matrixB.entries[0] - matrixA.entries[0])) >> 12);
    out->entries[1] = matrixA.entries[1] * preMultiply + ((reducedTime * (matrixB.entries[1] - matrixA.entries[1])) >> 12);
    out->entries[2] = matrixA.entries[2] * preMultiply + ((reducedTime * (matrixB.entries[2] - matrixA.entries[2])) >> 12);
    out->entries[3] = matrixA.entries[3] * preMultiply + ((reducedTime * (matrixB.entries[3] - matrixA.entries[3])) >> 12);
    out->entries[4] = matrixA.entries[4] * preMultiply + ((reducedTime * (matrixB.entries[4] - matrixA.entries[4])) >> 12);
    out->entries[5] = matrixA.entries[5] * preMultiply + ((reducedTime * (matrixB.entries[5] - matrixA.entries[5])) >> 12);
    Vector3fix_Normalize(&out->rows[0], &out->rows[0]);
    Vector3fix_Normalize(&out->rows[1], &out->rows[1]);
    if (!anyBasisMatrices)
    {
        out->entries[6] = matrixA.entries[6] * preMultiply + ((reducedTime * (matrixB.entries[6] - matrixA.entries[6])) >> 12);
        out->entries[7] = matrixA.entries[7] * preMultiply + ((reducedTime * (matrixB.entries[7] - matrixA.entries[7])) >> 12);
        out->entries[8] = matrixA.entries[8] * preMultiply + ((reducedTime * (matrixB.entries[8] - matrixA.entries[8])) >> 12);
        Vector3fix_Normalize(&out->rows[2], &out->rows[2]);
    }
    else
        CalculateThirdRowByCrossProduct(out);
}

bool GetMatrixFromIndex(Matrix3x3* out, intptr_t pivotList, intptr_t basisList, int index)
{
    if (index & 0x8000) // pivot matrix
    {
        out->entries[0] = out->entries[1] = out->entries[2] =
        out->entries[3] = out->entries[4] = out->entries[5] = 
        out->entries[6] = out->entries[7] = out->entries[8] = 0;
        NSBXXAnimationJAC::PivotMatrix* pivot = (NSBXXAnimationJAC::PivotMatrix*)(pivotList + (((index & 0x7fff) * 3) << 1));
        fix32_t entryA = pivot->a;
        fix32_t entryB = pivot->b;
        
        int form = pivot->flags & 0xf;
        out->entries[form] = (pivot->flags & 0x10) ? -1 << 12 : 1 << 12;

        out->entries[data_020e9284[form].a] = entryA;
        out->entries[data_020e9284[form].b] = entryB;

        fix32_t entryC = (pivot->flags & 0x20) ? -entryB : entryB;
        out->entries[data_020e9284[form].c] = entryC;
        
        fix32_t entryD = (pivot->flags & 0x40) ? -entryA : entryA;
        out->entries[data_020e9284[form].d] = entryD;

        return false;
    }
    else // basis matrix
    {
        NSBXXAnimationJAC::BasisMatrix* basis = (NSBXXAnimationJAC::BasisMatrix*)(basisList + (((index & 0x7fff) * 5) << 1));
        short accumulation = 0;

        int d4 = basis->data[4];
        out->entries[4] = d4 >> 3;
        accumulation = (accumulation << 3) | (d4 & 7);

        int d0 = basis->data[0];
        out->entries[0] = d0 >> 3;
        accumulation = (accumulation << 3) | (d0 & 7);

        int d1 = basis->data[1];
        out->entries[1] = d1 >> 3;
        accumulation = (accumulation << 3) | (d1 & 7);

        int d2 = basis->data[2];
        out->entries[2] = d2 >> 3;
        accumulation = (accumulation << 3) | (d2 & 7);

        int d3 = basis->data[3];
        out->entries[3] = d3 >> 3;
        accumulation = (accumulation << 3) | (d3 & 7);
        
        out->entries[5] = (accumulation << 19) >> 19; // limit to 13 bits

        return true;
    }
}
