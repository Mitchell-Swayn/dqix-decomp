extern "C" void Object_SetStateTwoAndClearWord218();
extern "C" void SetWordFlagBits(void*, unsigned int);
// Original: arm9/main @ 0x0204A120; symbol: func_0204a120; size: 0x50.
extern "C" void InitializeObjectFlag10AndResourceIndices(unsigned char* object)
{
    Object_SetStateTwoAndClearWord218();
    SetWordFlagBits(object, 0x10);
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
