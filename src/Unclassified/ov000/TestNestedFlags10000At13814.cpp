#pragma thumb off
#pragma force_active on
// Original: arm9/ov000 @ 0x021599AC; symbol: TestNestedFlags10000At13814; size: 0x18.
extern "C" int TestNestedFlags10000At13814(void* object)
{
    unsigned char* nested = *(unsigned char**)((unsigned char*)object + 0x138);
    return (*(unsigned int*)(nested + 0x14) & 0x10000) != 0;
}
