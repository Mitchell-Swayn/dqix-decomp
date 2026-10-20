extern "C" void Camera_SetOrbitParameters(void*, const void*);
extern "C" void Camera_SetProjectionAngle(void*, int);
// Original: arm9/main @ 0x020A2800; symbol: func_020a2800; size: 0x30.
extern "C" void Camera_ApplyDefaultOrbitPreset(void* object)
{
    unsigned char* bytes = (unsigned char*)object;
    *(int*)(bytes + 0x224) = 0x6000;
    *(int*)(bytes + 0x228) = 0xb000;
    Camera_SetOrbitParameters(object, bytes + 0x220);
    Camera_SetProjectionAngle(object, 0xf000);
}
