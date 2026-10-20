#pragma thumb off
#pragma force_active on
// Original: arm9/ov023 @ 0x021F9DA0; symbol: WriteByteAtOffset60; size: 0x8.
extern "C" void Menu_SetGridNavigationWrapEnabled(void* object, unsigned char value)
{
    ((unsigned char*)object)[0x60] = value;
}
