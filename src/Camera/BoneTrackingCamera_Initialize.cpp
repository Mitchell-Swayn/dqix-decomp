extern "C" void Camera_InitializeManualControlState();
extern "C" void Camera_SetObjectFlags(void*, unsigned int);
// Original: arm9/main @ 0x0204A120; symbol: func_0204a120; size: 0x50.
extern "C" void BoneTrackingCamera_Initialize(unsigned char* object)
{
    Camera_InitializeManualControlState();
    Camera_SetObjectFlags(object, 0x10);
    *(unsigned int*)(object + 0x21c) = 0;
    *(unsigned int*)(object + 0x220) = 0;
    object[0x224] = 0;
    object[0x234] = 0;
    object[0x244] = 0;
    *(unsigned int*)(object + 0x254) = 0xffffffff;
    *(unsigned int*)(object + 0x258) = 0xffffffff;
    *(unsigned int*)(object + 0x25c) = 0xffffffff;
    *(unsigned int*)(object + 0x260) = 0xffffffff;
    object[0x264] = 0;
    object[0x265] = 0;
}
