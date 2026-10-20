#pragma thumb off
#pragma force_active on
// Original: arm9/ov000 @ 0x021599C4; symbol: TestNestedFlags20000At13814; size: 0x18.
extern "C" int Combat_HasBreathResistanceModifier(void* object)
{
    unsigned char* nested = *(unsigned char**)((unsigned char*)object + 0x138);
    return (*(unsigned int*)(nested + 0x14) & 0x20000) != 0;
}
