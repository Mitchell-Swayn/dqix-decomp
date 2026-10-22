#include <globaldefs.h>
#include <System/Matrix.h>
ARM

struct CameraVector { int x, y, z; };
struct AngleState { char unknown[0x58]; int angle; int sine; int cosine; };

extern "C" {
void BattleCamera_ResetShotAndTransitions(unsigned char* camera, int roll, int projection, int yaw);
void Camera_SetProjectionAngle(AngleState* state, int angle);
void Combat_StoreThreeWords(void* destination, unsigned int first, unsigned int second, unsigned int third);
unsigned BattleScene_GetActiveInstance();
void _ZN8Vector3iaSERKS_(void*, const void*);
void Camera_RecalculateOrbitAndEye(void* object);
int Math_ComputeCosineEasingFromHorizontalLength(unsigned char* p, int* length);
}

// Original: arm9/ov000 @ 0x0216D600; symbol: func_ov000_0216d600; size: 0x30c.
// Frames the battle formation: derives an orbit distance from the formation
// width/depth for the chosen side and field of view, clamps distance and height,
// applies the mode-specific offset (raise, scaled float offset, or offset with
// transition timings), optionally takes the scene's override orbit, mirrors the
// orbit for side 0, then stores it as both current and saved camera orbit.
extern "C" void BattleCamera_FrameFormation(unsigned char* camera, int side, int closeUp, int mode,
                                            float offsetX, float offsetY, float offsetZ, bool useSceneOrbit)
{
    BattleCamera_ResetShotAndTransitions(camera, 1, 1, 1);
    camera[0x220] = 2;

    int width;
    int depth;
    if (side == 0) {
        width = *(int*)(camera + 0x228);
        depth = *(int*)(camera + 0x22c);
    } else {
        width = *(int*)(camera + 0x230);
        depth = *(int*)(camera + 0x234);
    }

    int fieldOfView;
    int scale;
    if (closeUp == 0) {
        fieldOfView = 0x424;
        scale = fieldOfView + 0xb50;
    } else {
        Camera_SetProjectionAngle((AngleState*)camera, 0x16000);
        fieldOfView = 0x5fe;
        scale = 0xed6;
    }

    int scaled = FIX32_MULTIPLY(width, scale);
    int distance = fix32_Divide(scaled, (int)(2.2f * fieldOfView)) - 0x2800;
    scaled = FIX32_MULTIPLY(depth, scale);
    scaled = fix32_Divide(scaled, (int)(1.5f * fieldOfView)) - 0x2800;
    if (scaled >= distance)
        distance = scaled;
    int minimum = 0x6800;
    if (closeUp != 0)
        minimum = 0x3000;
    if (distance < minimum)
        distance = minimum;

    int height = depth / 2;
    if (height < 0x1333)
        height = 0x1333;

    CameraVector orbit;
    CameraVector target;
    int length;
    Combat_StoreThreeWords(&orbit, 0, height, distance);
    Combat_StoreThreeWords(&target, 0, height, 0);
    if (orbit.y > 0x2000)
        orbit.y = 0x2000;

    if (closeUp == 0) {
        if (mode == 1) {
            orbit.y += 0x1000;
        } else if (mode == 2) {
            orbit.x += (int)(4096.0f * offsetX);
            orbit.y += (int)(4096.0f * offsetY);
            orbit.z += (int)(4096.0f * offsetZ);
        } else if (mode == 3) {
            *(int*)(camera + 0x238) = 0x1c;
            *(int*)(camera + 0x23c) = 0x14;
            orbit.x += (int)(4096.0f * offsetX);
            orbit.y += (int)(4096.0f * offsetY);
            orbit.z += (int)(4096.0f * offsetZ);
        }
    }

    if (useSceneOrbit) {
        unsigned char* scene = (unsigned char*)BattleScene_GetActiveInstance();
        if (scene != 0 && *(int*)(scene + 0x77f0) != -1) {
            Combat_StoreThreeWords(&orbit, *(int*)(scene + 0x77f4), *(int*)(scene + 0x77f8), *(int*)(scene + 0x77fc));
            Combat_StoreThreeWords(&target, *(int*)(scene + 0x7800), *(int*)(scene + 0x7804), *(int*)(scene + 0x7808));
        }
    }

    if (side == 0) {
        orbit.z = -orbit.z;
        target.z = -target.z;
    }

    _ZN8Vector3iaSERKS_(camera + 4, &orbit);
    _ZN8Vector3iaSERKS_(camera + 0x10, &target);
    Camera_RecalculateOrbitAndEye(camera);
    _ZN8Vector3iaSERKS_(camera + 0x240, &orbit);
    _ZN8Vector3iaSERKS_(camera + 0x24c, &target);
    *(int*)(camera + 0x258) = Math_ComputeCosineEasingFromHorizontalLength(camera, &length);
}
