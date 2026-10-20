#include <globaldefs.h>
ARM
extern "C" void UpdateMatrixFromIndexedObjectHeading(void *object);
extern "C" void Camera_UpdateRenderView(void *);
// Original: arm9/ov000 @ 0x0216D50C; symbol: Camera_UpdateRenderViewAndConditionalTargetMatrix; size: 0x24.
// Updates the indexed target matrix when field 0x224 is nonnegative, then updates the render view.
extern "C" void Camera_UpdateRenderViewAndConditionalTargetMatrix(void *object) {
    if (*(int *)((char *)object + 0x224) >= 0)
        UpdateMatrixFromIndexedObjectHeading(object);
    Camera_UpdateRenderView(object);
}
