#pragma thumb off
#pragma force_active on
// Original: arm9/ov000 @ 0x02163404; symbol: SetByteAt5901AndFlag8000At55F4; size: 0x18.
extern "C" void SetByteAt5901AndFlag8000At55F4(void* base, unsigned char value)
{
    volatile unsigned char* bytes = (volatile unsigned char*)base;
    bytes[0x5901] = value;
    *(volatile unsigned int*)(bytes + 0x55F4) |= 0x8000;
}
