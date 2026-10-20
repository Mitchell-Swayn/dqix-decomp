#include "Graphics/NSBXX/RenderConfig.h"
#include "Graphics/NSBXX/GeometryFifo.h"
#include <globaldefs.h>

#pragma optimize_for_size off

#define BUILD_LIGHT_VECTOR(idx, x, y, z) (((unsigned)(idx) << 30) | ((unsigned)(z) << 20) | ((unsigned)(y) << 10) | ((unsigned)(x)))
#define RGB(r,g,b) (((unsigned)(r)) | ((unsigned)(g) << 5) | ((unsigned)(b) << 10))
#define BUILD_LIGHT_COLOR(idx, r,g,b) (((unsigned)(idx) << 30) | RGB((r),(g),(b)))

// kind of evil but this prevents invoking Vector3fix::operator=
static inline void ArrayCopyVec3(void* dst, const void* src)
{
    struct ArrayVec3 { fix32_t values[3]; };
    *(ArrayVec3*)dst = *(const ArrayVec3*)src;
}

// Original: arm9/main @ 0x020B36C0; symbol: _ZN12RenderConfig5ResetEv; size: 0x154.
void RenderConfig::Reset()
{
    RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.magicCommands_0 = COMBINE_GXFIFO_COMMANDS4(
        GXFifoCommand_SetMatrixMode,
        GXFifoCommand_LoadMat4x4,
        GXFifoCommand_SetMatrixMode,
        GXFifoCommand_LoadMat4x3
    );

    RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.magicParam_4 = 0;
    RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.magicParam_48 = 2;

    RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.magicCommands_7c = COMBINE_GXFIFO_COMMANDS4(
        GXFifoCommand_SetLightVector,
        GXFifoCommand_SetLightVector,
        GXFifoCommand_SetLightVector,
        GXFifoCommand_SetLightVector
    );

    RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.magicCommands_90 = COMBINE_GXFIFO_COMMANDS4(
        GXFifoCommand_DiffuseAmbientReflect,
        GXFifoCommand_SpecularReflectEmit,
        GXFifoCommand_SetPolygonAttr,
        GXFifoCommand_SetViewport
    );

    RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.magicCommands_a4 = COMBINE_GXFIFO_COMMANDS4(
        GXFifoCommand_SetLightColor,
        GXFifoCommand_SetLightColor,
        GXFifoCommand_SetLightColor,
        GXFifoCommand_SetLightColor
    );

    RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.magicCommands_b8 = COMBINE_GXFIFO_COMMANDS3(
        GXFifoCommand_MultiplyMat4x3,
        GXFifoCommand_ScaleMatrix,
        GXFifoCommand_SetTexImageParams
    );

    MTX_Identity43_(&RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.viewMatrix);
    MTX_Identity44(&RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.projectionMatrix);

    uint32_t minusInvSqrt3 = 0x2d8;
    RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.lightVectors[0] = BUILD_LIGHT_VECTOR(0,
        minusInvSqrt3, minusInvSqrt3, minusInvSqrt3);
    RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.lightVectors[1] = BUILD_LIGHT_VECTOR(1, 0x200, 0, 0);
    RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.lightVectors[2] = BUILD_LIGHT_VECTOR(2, 0x1ff, 0, 0);
    RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.lightVectors[3] = BUILD_LIGHT_VECTOR(3, 0, 0x200, 0);

    RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.diffuseAmbientArg = (RGB(16, 16, 16) << 16) | (1 << 15) | RGB(16, 16, 16);
    RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.specularArg = (RGB(16, 16, 16) << 16) | (1 << 15) | RGB(16, 16, 16);
    // alpha = 31 | render forward-facing polygons | enable all lights
    RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.polygonAttrArg = (0x1f << 16) | (1 << 7) | 0xf;
    // left = 0 | top = 0 | right = 255 | bottom = 191
    RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.viewportArg = 0 | (0 << 8) | (255 << 16) | (191 << 24);
    RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.lightColors[0] = BUILD_LIGHT_COLOR(0, 31, 31, 31);
    RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.lightColors[1] = BUILD_LIGHT_COLOR(1, 31, 0, 0);
    RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.lightColors[2] = BUILD_LIGHT_COLOR(2, 0, 31, 0);
    RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.lightColors[3] = BUILD_LIGHT_COLOR(3, 0, 0, 31);

    RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.objectRotationPosition.translation.x = 0;
    RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.objectRotationPosition.translation.y = 0;
    RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.objectRotationPosition.translation.z = 0;

    MTX_Identity33_(&RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.objectRotationPosition.rotation);

    RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.objectScale.x = 1 << 12;
    RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.objectScale.y = 1 << 12;
    RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.objectScale.z = 1 << 12;

    RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.texImageParams = 0;
    RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.flags = 0;

    RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.eyeVector.x = RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.eyeVector.y = RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.eyeVector.z = 0;
    RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.upVector.x = RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.upVector.z = 0;
    RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.upVector.y = 1 << 12;

    RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.targetVector.x = RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.targetVector.y = 0;
    RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.targetVector.z = -1 << 12;
}

void RenderConfig::SubmitToFifo()
{
    RenderConfig* instance = &RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage;
    uint32_t* commands = 
#if defined(usa)
    (uint32_t*)0x0210a010; // i hate this
#elif defined(jpn)
    (uint32_t*)0x02109cc8;
#else
#error need to hardcode address of RenderConfig instance
#endif
    SubmitCommandToGeometryFifo(instance->magicCommands_0, commands + 1, 0x3e);

    instance->flags &= ~(1 << RENDER_CONFIG_FLAG_0);
    instance->flags &= ~(1 << RENDER_CONFIG_FLAG_1);
}

// Original: arm9/main @ 0x020B3850; symbol: _ZN12RenderConfig17SetObjectPositionEP8Vector3i; size: 0x30.
void RenderConfig::SetObjectPosition(Vector3fix *pos)
{
    if (pos != NULL)
    {
        ArrayCopyVec3(&RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.objectRotationPosition.translation, pos);
        RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.flags &= ~((1 << RENDER_CONFIG_FLAG_WORLDVIEW_CACHE_VALID) | (1 << RENDER_CONFIG_FLAG_5) | (1 << RENDER_CONFIG_FLAG_2));
    }
}

// Original: arm9/main @ 0x020B3880; symbol: _ZN12RenderConfig14SetObjectScaleEP8Vector3i; size: 0x30.
void RenderConfig::SetObjectScale(Vector3fix *scale)
{
    if (scale != NULL)
    {
        ArrayCopyVec3(&RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.objectScale, scale);
        RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.flags &= ~((1 << RENDER_CONFIG_FLAG_WORLDVIEW_CACHE_VALID) | (1 << RENDER_CONFIG_FLAG_5) | (1 << RENDER_CONFIG_FLAG_2));
    }
}

// Original: arm9/main @ 0x020B38B0; symbol: _ZN12RenderConfig14SetLightVectorEjsss; size: 0x3C.
void RenderConfig::SetLightVector(unsigned int light, fix16_t x, fix16_t y, fix16_t z)
{
    uint32_t formattedX = (x >> 3) & 0x3ff;
    uint32_t formattedY = ((uint32_t)(y >> 3) << 22) >> 12;
    uint32_t formattedZ = ((uint32_t)(z >> 3) << 22) >> 2;
    RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.lightVectors[light] = formattedX | formattedY | formattedZ | (light << 30);
}

// Original: arm9/main @ 0x020B38EC; symbol: _ZN12RenderConfig13SetLightColorEjj; size: 0x14.
void RenderConfig::SetLightColor(unsigned int light, uint32_t rgb)
{
    RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.lightColors[light] = rgb | (light << 30);
}

// Original: arm9/main @ 0x020B3900; symbol: _ZN12RenderConfig23SetDiffuseAmbientColorsEjji; size: 0x24.
void RenderConfig::SetDiffuseAmbientColors(uint32_t diffuseRGB, uint32_t ambientRGB, int setVertexColor)
{
    setVertexColor = (setVertexColor ? 1 : 0);
    RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.diffuseAmbientArg = diffuseRGB | (ambientRGB << 16) | (setVertexColor << 15);
}

// Original: arm9/main @ 0x020B3924; symbol: _ZN12RenderConfig20SetPolygonAttributesEjjjjjj; size: 0x2C.
void RenderConfig::SetPolygonAttributes(unsigned int lights, unsigned int mode,
    unsigned int culling, unsigned int polygonID, unsigned int alpha, unsigned int miscFlags)
{
    RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.polygonAttrArg = miscFlags | 
        (lights | mode << 4 | culling << 6) | polygonID << 24 | alpha << 16;
}

// Original: arm9/main @ 0x020B3950; symbol: _ZN12RenderConfig20GetInverseViewMatrixEv; size: 0x44.
const Matrix4x3* RenderConfig::GetInverseViewMatrix()
{
    if (!(RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.flags & (1 << RENDER_CONFIG_FLAG_INVERSE_VIEW_CACHE_VALID)))
    {
        Mat4x3_Invert(&RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.viewMatrix, &RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.cachedInverseView);
        RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.flags |= (1 << RENDER_CONFIG_FLAG_INVERSE_VIEW_CACHE_VALID);
    }
    return &RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.cachedInverseView;
}

// can be made static later
// Original: arm9/main @ 0x020B3994; symbol: _Z30RecalculateWorldViewAndInversev; size: 0x58.
void RecalculateWorldViewAndInverse()
{
    Mat4x3_Multiply(&RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.objectRotationPosition, &RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.viewMatrix, &RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.cachedWorldView);
    Mat4x3_ApplyScale(&RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.cachedWorldView, &RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.cachedWorldView,
        RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.objectScale.x, RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.objectScale.y, RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.objectScale.z);
    Mat4x3_Invert(&RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.cachedWorldView, &RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.cachedInverseWorldView);
}

// Original: arm9/main @ 0x020B39EC; symbol: _ZN12RenderConfig26GetCombinedWorldViewMatrixEv; size: 0x38.
const Matrix4x3* RenderConfig::GetCombinedWorldViewMatrix()
{
    if (!(RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.flags & (1 << RENDER_CONFIG_FLAG_WORLDVIEW_CACHE_VALID)))
    {
        RecalculateWorldViewAndInverse();
        RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.flags |= (1 << RENDER_CONFIG_FLAG_WORLDVIEW_CACHE_VALID);
    }
    return &RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.cachedWorldView;
}

// Original: arm9/main @ 0x020B3A24; symbol: _ZN12RenderConfig33GetInverseCombinedWorldViewMatrixEv; size: 0x38.
const Matrix4x3* RenderConfig::GetInverseCombinedWorldViewMatrix()
{
    if (!(RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.flags & (1 << RENDER_CONFIG_FLAG_WORLDVIEW_CACHE_VALID)))
    {
        RecalculateWorldViewAndInverse();
        RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.flags |= (1 << RENDER_CONFIG_FLAG_WORLDVIEW_CACHE_VALID);
    }
    return &RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.cachedInverseWorldView;
}

// Original: arm9/main @ 0x020B3A5C; symbol: _ZN12RenderConfig11GetViewportEPiS0_S0_S0_; size: 0x74.
void RenderConfig::GetViewport(int *left, int *top, int *right, int *bottom)
{
    if (left != NULL)
        *left = RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.viewportArg & 0xff;
    if (top != NULL)
        *top = (RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.viewportArg >> 8) & 0xff;
    if (right != NULL)
        *right = (RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.viewportArg >> 16) & 0xff;
    if (bottom != NULL)
        *bottom = (RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.viewportArg >> 24) & 0xff;
}