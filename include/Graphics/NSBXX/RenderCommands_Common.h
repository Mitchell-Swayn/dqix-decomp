#pragma once

// This header is for use only by the 2 (3) RenderCommands.cpp source files.
// Once command 9 is decompiled we can merge the files into one and paste
// this in instead

#include "NSBXX.h"
#include "../../System/Graphics.h"
#include "GeometryFifo.h"
#include "RenderCommands.h"
#include "RenderConfig.h"
#include "Animation.h"
#include <asmhacks.h>

#pragma optimize_for_size off

#if defined(jpn)
#define MaterialBindProc_UnknownRoleInitializedBytes data_020e934c
#define RenderCommand6_UnknownRoleInitializedBytes data_020e936c
#define GetMatrixFromIndex_UnknownRoleInitializedBytes data_020e9390
#define SetUpRenderCommandHandler_UnknownRoleProcedureReferenceRecords data_020f1e4c
#define SetUpRenderCommandHandler_UnknownRoleProcedureReferenceRecords_Variant2 data_020f1e58
#define RenderMeshWithMaterial_UnknownRoleProcedureReferenceRecords data_020f1e64
#define RenderCommand12_UnknownRoleProcedureReferenceRecords data_020f1e74
#define RenderCommand7_UnknownRoleInitializedBytes data_020f1ee4
#define RenderCommand8_UnknownRoleInitializedBytes data_020f1f2c
#define ExecuteRenderCommands_UnknownRoleProcedureReferenceRecords data_020f1f74
#define ApplyBindPoseScaling_UnknownRoleZeroInitializedStorage data_02109f2c
#define MaterialBindProc_UnknownRoleZeroInitializedStorage data_02109f30
#define BoneMatrixScaleCalculationProcType2_UnknownRoleZeroInitializedStorage data_0210ad30

#define func_020c1868 func_020c3334
#define func_020c223c func_020c3d08
#define func_020c2c5c func_020c4728
#define func_020c2cf0 func_020c47bc
#define func_020c2eb8 func_020c4984
#define func_020c2f18 func_020c49e4
#define Geometry_ReadClipMatrixWhenIdle func_020c6fc8
#define MIi_CpuClear32 func_020cbeb8
#define MIi_CpuCopy32 func_020cbed4
#define MI_Send32 func_020cbefc
#define MIi_CpuClearFast func_020cbf24
#define MI_Zero36B func_020cc29c
#endif

// holds values:
// { 0, 0x00007fff, 0x7fff0000, 0x7fff7fff, 
//   0x00008000, 0x0000ffff, 0x7fff8000, 0x7fffffff }
// i.e. data_020e9240[idx] sets bits
//    0-14 if (idx & 1)
//    16-30 if (idx & 2)
//    15 if (idx & 4)
// For DIF_AMB these are masks corresponding to diffuse reflection color,
// ambient reflection color and (set vertex color yes/no)
// For SPE_EMI these are masks corresponding to specular reflection color,
// emission color and (enable specular reflection shininess table yes/no)
// Original data: arm9/main @ 0x20e9240; symbol: data_020e9240.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00000000ff7f00000000ff7fff7fff7f00800000ffff00000080ff7fffffff7f.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned int const MaterialBindProc_UnknownRoleInitializedBytes[];

// pivot matrix a/b/c/d position lookup
// both arrays are identical
struct PivotMatrixPositions {
    uint8_t a, b, c, d;
};
// Original data: arm9/main @ 0x20e9260; symbol: data_020e9260.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 040507080305060803040607010207080002060800010607010204050002030500010304.
// Observed span: 36 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20e9284; symbol: data_020e9284.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 040507080305060803040607010207080002060800010607010204050002030500010304.
// Observed span: 36 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern const PivotMatrixPositions RenderCommand6_UnknownRoleInitializedBytes[], GetMatrixFromIndex_UnknownRoleInitializedBytes[];

// Holds { func_020b9a2c, func_020b9b30, func_020ba390 }.
// Called by command 6 to populate scaling data for the bone matrix
// Original data: arm9/main @ 0x20f1cec; symbol: data_020f1cec.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 2c9a0b02309b0b0290a30b02.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern void (*SetUpRenderCommandHandler_UnknownRoleProcedureReferenceRecords_Variant2[])(BoneMatrixRenderData*, NSBXXBoneMatrix::Scaling* boneMatrixScaleData, uint8_t* ip, int boneMatrixFlags);
// Holds { func_020b99b0, func_020b9a6c, func_020ba264 }
// Called by command 6 to apply bone matrix transformations via the GXFifo
// Original data: arm9/main @ 0x20f1ce0; symbol: data_020f1ce0.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex b0990b026c9a0b0264a20b02.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern void (*SetUpRenderCommandHandler_UnknownRoleProcedureReferenceRecords[])(BoneMatrixRenderData*);
// Holds { func_020ba11c func_020ba5ac, func_020bac74, func_020bb29c }
// Original data: arm9/main @ 0x20f1cf8; symbol: data_020f1cf8.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 1ca10b02aca50b0274ac0b029cb20b02.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern void (*RenderMeshWithMaterial_UnknownRoleProcedureReferenceRecords[])(MaterialRenderData*);

extern struct Struct_020f1d08
{
    // used for render command 13
    unsigned int commandTexImageParams_0_; // holds 0x2A = GXFifoCommand_SetTexImageParams
    unsigned int texImageParamsArg_4_;
    // used for render command 12
    unsigned int commandTexImageParams_8_; // holds 0x2a = GXFifoCommand_SetTexImageParams
    unsigned int texImageParamsArg_c_;

    // only one of these is not null
    void (*materialBindFunctions[4])(RenderCommandHandler*, int modifier, NSBXXMaterial*, unsigned int idx);
    // only one of these is not null
    void (*meshDrawFunctions[4])(RenderCommandHandler*, int modifier, NSBXXMesh*, unsigned int idx);

    Matrix4x4 command13Matrix4x4_;
} RenderCommand12_UnknownRoleProcedureReferenceRecords;

// a blob of GXFIFO data used by command 7. The entries are
// - combined command (12, 10, 17, 1b) = (pop matrix, matrix mode, load 3x4, scale)
// - 1 (parameter for pop matrix)
// - 2 (parameter for matrix mode: position + vector)
// - nine entries for the identity matrix
// - 3 entries that make up the translation component of the matrix. Initially
//   zero but can be modified
// - 3 parameters for the scaling command
struct Struct_020f1d78 {
    // is always (12, 10, 17, 1b) = (pop matrix, matrix mode, load 4x3, scale)
    // which can be merged with subsequent data as a single command to the GXFIFO.
    uint32_t commandsCombined;
    // always 1
    uint32_t popMatrixParameter;
    // always 2 (position + vector?)
    uint32_t matrixModeParameter;
    // this is always the 3x3 identity, but combined with translation gives a 4x3 matrix
    Matrix4x3 rotationTranslation;

    Vector3fix scaling;
// Original data: arm9/main @ 0x20f1d78; symbol: data_020f1d78.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 1210171b010000000200000000100000000000000000000000000000001000000000000000000000000000000010000000000000000000000000000000000000 ...; full span in module reference.
// Observed span: 72 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20f1dc0; symbol: data_020f1dc0.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 1210171b010000000200000000100000000000000000000000000000001000000000000000000000000000000010000000000000000000000000000000000000 ...; full span in module reference.
// Observed span: 72 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
} extern RenderCommand7_UnknownRoleInitializedBytes, RenderCommand8_UnknownRoleInitializedBytes;

// render command lookup
// Original data: arm9/main @ 0x20f1e08; symbol: data_020f1e08.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 48430b0270430b0298430b0214450b02684a0b02ec4b0b028c4c0b02ec500b02f4530b0258570b02b45e0b02905f0b0200600b0244630b020000000000000000 ...; full span in module reference.
// Observed span: 128 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern void (*ExecuteRenderCommands_UnknownRoleProcedureReferenceRecords[])(RenderCommandHandler*, int);

// Original data: arm9/main @ 0x210a274; symbol: data_0210a274.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern struct RenderCommandHandler* ApplyBindPoseScaling_UnknownRoleZeroInitializedStorage;
// sizeof == 0x38
// Original data: arm9/main @ 0x210a278; symbol: data_0210a278.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 3584 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
MaterialRenderData extern MaterialBindProc_UnknownRoleZeroInitializedStorage[64];

struct Struct_0210b078
{
    Vector3fix vec0_;
    BoneMatrixRenderData::Scale vec1_;
// Original data: arm9/main @ 0x210b078; symbol: data_0210b078.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 1536 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
} extern BoneMatrixScaleCalculationProcType2_UnknownRoleZeroInitializedStorage[64];

struct Struct_0210b678
{
    Matrix4x4 mat4x4;
    Matrix3x3 mat3x3;
// Original data: arm9/main @ 0x210b678; symbol: data_0210b678.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 6400 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
} extern RenderCommand9_UnknownRoleZeroInitializedStorage[64];

extern "C"
{  
#if true
    // expand a 3x4 matrix (param 1) into a 4x4 matrix (param 2)
    void func_020c1868(const void*, void*);
    // multiply 4x4 matrices, store in param 3.
    // set up so that you can safely have param_3 = param_1 or param_2
    // The arrangement is such that param_3 represents the transformation
    // (do param_1) then (do param_2). In row major representation this is
    // param_1 * param_2, in col major it's param_2 * param_1.
    void func_020c223c(const void*, const void*, void*);
    // get length of vector3
    fix32_t func_020c2eb8(const void*);
    // fix32_t division: retrieve result from hardware divider
    fix32_t func_020c2c5c();
    // fix32_t division: set up hardware divider
    void func_020c2cf0(fix32_t a, fix32_t b);
    // normalize vector3 (param 1) into vector3 (param 2)
    void func_020c2f18(const void*, void*);
#endif
    // load the specified matrix into the current matrix (3x4).
    void Geometry_LoadMatrix4x3ToCommandFIFO(const fix32_t*);
    // multiply the current matrix by the specified one (3x4), i.e carry
    // out GXFIFO operation 0x19
    void Graphics_SubmitGeometryCommand25(const fix32_t*);
    // multiply by the specified 3x3 matrix (instruction 0x1a)
    void Graphics_WriteGeometryCommand26AndDataBlock(const fix32_t*);
    // try to get the clip matrix into the pointer specified (4x4 fix32_t matrix)
    // returns -1 if still waiting, 0 if done
    int Geometry_ReadClipMatrixWhenIdle(void*);
    // try to get the result matrix (current directional vector matrix)
    // returns -1 if still waiting, 0 if done
    int Graphics_ReadMatrixWhenGeometryNotBusy(void*);
    // memset via u32 values
    void MIi_CpuClear32(int value, void* dst, unsigned int len);
    // memcpy via u32 values
    void MIi_CpuCopy32(const void* src, void* dst, unsigned int numBytes);
    // repeatedly write u32s to dst (useful for hardware registers)
    void MI_Send32(const void* src, volatile void* dst, unsigned int numBytes);
    // aligned 32-byte-looped memset
    void MIi_CpuClearFast(int value, void* dst, unsigned int len);
    // zero-initialize matrix
    void MI_Zero36B(void*);
}