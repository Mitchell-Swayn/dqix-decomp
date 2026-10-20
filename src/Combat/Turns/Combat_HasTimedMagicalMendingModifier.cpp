#pragma thumb off
#pragma force_active on
// Original: arm9/ov000 @ 0x02159994; symbol: TestNestedFlags8000At13814; size: 0x18.
extern "C" int Combat_HasTimedMagicalMendingModifier(void* object)
{
    unsigned char* nested = *(unsigned char**)((unsigned char*)object + 0x138);
    return (*(unsigned int*)(nested + 0x14) & 0x8000) != 0;
}
