#include <globaldefs.h>
ARM

struct FloatVector { float x, y, z; };

// Eye at +0x04 is the orbit endpoint placed by ComputeRotatedEndpointFromAngleHeightAndLength
// around the target at +0x10; the orbit angle, height and distance are cached at +0x70.
struct CameraOrbit {
    int mode;
    int eyeX, eyeY, eyeZ;
    int targetX, targetY, targetZ;
    unsigned char reserved1C[0x70 - 0x1C];
    int orbitAngle;
    int orbitHeight;
    int orbitDistance;
};

extern "C" {
double RuntimeMathEntries_ComputeAtan2(double y, double x);
float Runtime_ComputeFloatSquareRoot(float);
void ComputeRotatedEndpointFromAngleHeightAndLength(char* self, int angle, int y, int length);
}

// Original: arm9/main @ 0x0202EAB8; symbol: func_0202eab8; size: 0x1A4.
// Derives the orbit angle, height and distance from the eye-target offset, then re-places the eye.
extern "C" void Camera_RecalculateOrbitAndEye(void* object)
{
    CameraOrbit* camera = (CameraOrbit*)object;
    FloatVector offset;
    offset.x = camera->eyeX / 4096.0f - camera->targetX / 4096.0f;
    offset.y = camera->eyeY / 4096.0f - camera->targetY / 4096.0f;
    float offsetZ = camera->eyeZ / 4096.0f - camera->targetZ / 4096.0f;
    offset.z = offsetZ;
    float angle = RuntimeMathEntries_ComputeAtan2(offset.x, offsetZ);
    if (angle < 0.0f)
        angle += 6.2831855f;
    camera->orbitAngle = 4096.0f * angle;
    camera->orbitHeight = 4096.0f * offset.y;
    camera->orbitDistance = 4096.0f * Runtime_ComputeFloatSquareRoot(offset.z * offset.z + (offset.x * offset.x + offset.y * offset.y));
    ComputeRotatedEndpointFromAngleHeightAndLength((char*)camera, camera->orbitAngle, camera->orbitHeight, camera->orbitDistance);
}
