#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
#pragma always_inline on
struct A;
union Vec {
    struct {
        int x, y, z;
    };
    int words[3];
};
extern "C" {
void *GameState_ReadUnknownB0(GameState *state);
ARM int Camera_GetInverseViewRotation(int param_1);
void RenderConfig_CopyTransformAndClearFlagsA4(void *input);
void _ZN12RenderConfig17SetObjectPositionEP8Vector3i(Vec *);
void _ZN12RenderConfig14SetObjectScaleEP8Vector3i(Vec *);
void _ZN12RenderConfig12SubmitToFifoEv();
int Graphics_ReadGeometryStatusUnlessBusy(unsigned *result);
void Graphics_AdvanceTimedFrameSequence(A *a);
void Graphics_DrawEnabledVisibleFrameGeometry(char *p, int value);
void ZoneContainerRenderPart_DrawFrameCenteredAtOrigin(char *self, int index, int argument);
char *_ZN15LightingManager11GetInstanceEv();
int _Z8fix32cosi(int);
int _Z8fix32sini(int);
}
extern "C" Vec Zone3DDrawBreakableContainers_UnknownRoleInitializedBytes;
extern "C" int Zone3DDrawBreakableContainers_UnknownRoleInitializedBytes_Variant2[];
// Original: arm9/main @ 0x0201730C; symbol: func_0201730c; size: 0x234.
// Box-tests breakable container records, lights them from the lighting manager, and draws kind-3 children with Y rotation.
extern "C" void Zone3D_DrawBreakableContainers(char *owner)
{
    Vec scale;
    short box[6];
    int rotation[9];
    int combined[9];
    unsigned visible;
    if (!*(void **)(owner + 0x2750))
        return;
    GameState *state = GameState::GetInstance();
    int context = (int)GameState_ReadUnknownB0(state);
    if (!context)
        return;
    state->GetTickCount();
    unsigned short color = *(unsigned short *)(_ZN15LightingManager11GetInstanceEv() + 0x42);
    RenderConfig_CopyTransformAndClearFlagsA4((void *)Camera_GetInverseViewRotation(context));
    for (int i = 0; i < *(unsigned char *)(owner + 0x476); ++i) {
        char *entry = *(char **)(owner + 0x478) + i * 0x368;
        if (*(short *)(entry + 2) == -1)
            continue;
        _ZN12RenderConfig17SetObjectPositionEP8Vector3i((Vec *)(entry + 0x24));
        scale = Zone3DDrawBreakableContainers_UnknownRoleInitializedBytes;
        _ZN12RenderConfig14SetObjectScaleEP8Vector3i(&scale);
        _ZN12RenderConfig12SubmitToFifoEv();
        box[0] = -0x800;
        box[1] = 0;
        box[2] = -0x800;
        box[3] = 0x1000;
        box[4] = 0x1000;
        box[5] = 0x1000;
        *(volatile unsigned *)0x040005c0 = *(unsigned *)box;
        *(volatile unsigned *)0x040005c0 = *(unsigned *)(box + 2);
        *(volatile unsigned *)0x040005c0 = *(unsigned *)(box + 4);
        while (Graphics_ReadGeometryStatusUnlessBusy(&visible) != 0) {
        }
        if (!visible)
            continue;
        *(Vector3i *)&scale = *(Vector3i *)(entry + 0x3c);
        _ZN12RenderConfig14SetObjectScaleEP8Vector3i(&scale);
        _ZN12RenderConfig12SubmitToFifoEv();
        *(unsigned short *)(entry + 0x88) = color;
        *(unsigned short *)(entry + 0x110) = color;
        for (int j = 0; j < 4; ++j)
            *(unsigned short *)(entry + j * 0x88 + 0x198) = color;
        if (*(short *)(entry + 2) != 3)
            ZoneContainerRenderPart_DrawFrameCenteredAtOrigin(entry + 8, 0, 1);
        else if (*(short *)(entry + 2) == 3) {
            if (*(short *)(entry + 4) < 12) {
                Graphics_AdvanceTimedFrameSequence((A *)(entry + 0x90));
                Graphics_DrawEnabledVisibleFrameGeometry(entry + 0x90, 1);
            }
            entry += 0x118;
            for (int j = 0; j < 4; ++j) {
                char *child = entry + j * 0x88;
                _ZN12RenderConfig17SetObjectPositionEP8Vector3i((Vec *)(child + 0x1c));
                void *transform = (void *)Camera_GetInverseViewRotation(context);
                int angle = Zone3DDrawBreakableContainers_UnknownRoleInitializedBytes_Variant2[j];
                int cosine = _Z8fix32cosi(angle);
                MTX_RotY33_((Matrix3x3 *)rotation, _Z8fix32sini(angle), cosine);
                Mat3x3_Multiply((const Matrix3x3 *)transform, (const Matrix3x3 *)rotation, (Matrix3x3 *)combined);
                RenderConfig_CopyTransformAndClearFlagsA4(combined);
                _ZN12RenderConfig12SubmitToFifoEv();
                ZoneContainerRenderPart_DrawFrameCenteredAtOrigin(child, 0, 1);
            }
        }
    }
}
