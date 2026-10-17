extern "C" void Object_SetVectorComponentsThroughPositionSetter(void*, const void*);
extern "C" void SetAngleAndCacheTrig(void*, int);
// Original: arm9/main @ 0x020A2800; symbol: func_020a2800; size: 0x30.
extern "C" void SetFixedPointCoordinatesAndObjectScale(void* object)
{
    unsigned char* bytes = (unsigned char*)object;
    *(int*)(bytes + 0x224) = 0x6000;
    *(int*)(bytes + 0x228) = 0xb000;
    Object_SetVectorComponentsThroughPositionSetter(object, bytes + 0x220);
    SetAngleAndCacheTrig(object, 0xf000);
}
