#pragma once

#include "Graphics/NSBXX/NSBXX.h"
#include "Graphics/NSBXX/Animation.h"
#include "Graphics/NSBXX/RenderCommands_Common.h"

#pragma optimize_for_size off

#if defined(jpn)
#define MIi_CpuClear16 func_020cbe5c

#define InitializeModelAnimationFromJAC_UnknownRoleProcedureReferenceRecords data_020f1de0
#endif

extern "C"
{
    // memset 
    void MIi_CpuClear16(int value, void* dst, unsigned len);
}

void CalculateBoneMatrixRenderDataFromJAC(NSBXXAnimationJAC* jac, int arg, fix32_t time, BoneMatrixRenderData* bmrd);

void CalculateTranslationAmountFrameAligned(fix32_t* out, fix32_t time, NSBXXAnimationJAC::Track::ChannelNonConst* channel, NSBXXAnimationJAC* jac);
void CalculateTranslationAmountSmooth(fix32_t* out, fix32_t time, NSBXXAnimationJAC::Track::ChannelNonConst* channel, NSBXXAnimationJAC* jac);

void CalculateScalingAmountFrameAligned(fix32_t* out, fix32_t time, NSBXXAnimationJAC::Track::ChannelNonConst* channel, NSBXXAnimationJAC* jac);
void CalculateScalingAmountSmooth(fix32_t* out, fix32_t time, NSBXXAnimationJAC::Track::ChannelNonConst* channel, NSBXXAnimationJAC* jac);

void CalculateRotationFrameAligned(Matrix3x3* out, fix32_t time, NSBXXAnimationJAC::Track::ChannelNonConst* channel, NSBXXAnimationJAC* jac);
void CalculateRotationSmooth(Matrix3x3* out, fix32_t time, NSBXXAnimationJAC::Track::ChannelNonConst* channel, NSBXXAnimationJAC* jac);
bool GetMatrixFromIndex(Matrix3x3* out, intptr_t pivotList, intptr_t basisList, int index);

static inline void CalculateThirdRowByCrossProduct(Matrix3x3* mat)
{
    fix32_t m23 = mat->entries[5]; // yes, this order is actually important
    fix32_t m11 = mat->entries[0];
    fix32_t m21 = mat->entries[3];
    fix32_t m13 = mat->entries[2];
    fix32_t m12 = mat->entries[1];
    fix32_t m22 = mat->entries[4];

    mat->entries[6] = (m12 * m23 - m13 * m22) >> 12;
    mat->entries[7] = (m13 * m21 - m11 * m23) >> 12;
    mat->entries[8] = (m11 * m22 - m12 * m21) >> 12;
}

// processing callback for J.AC animations
// Original data: arm9/main @ 0x20f1c74; symbol: data_020f1c74.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex bc780b02.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern void (*InitializeModelAnimationFromJAC_UnknownRoleProcedureReferenceRecords)(void*, AnimationData*, int);


void ApplyBindPoseTranslation(BoneMatrixRenderData*);
void ApplyBindPoseScaling(BoneMatrixRenderData*);
void ApplyBindPoseRotation(BoneMatrixRenderData*);
