#pragma thumb off
#pragma force_active on
// Original: arm9/ov000 @ 0x021620D8; symbol: ClearByteHalfwordAndWordFields; size: 0x18.
extern "C" void ClearByteHalfwordAndWordFields(void* record)
{
    volatile unsigned char* bytes = (volatile unsigned char*)record;
    *(volatile unsigned short*)(bytes + 2) = 0;
    bytes[0] = 0;
    bytes[1] = 0;
    *(volatile unsigned int*)(bytes + 4) = 0;
}
