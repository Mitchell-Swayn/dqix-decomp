#pragma thumb off
#pragma force_active on
// Field roles are not established; names describe the observed layout operation.
// Original: arm9/ov023 @ 0x021F9BA8; symbol: func_ov023_021f9ba8; size: 0x8.
extern "C" void Menu_SetSelectedGridRow(void* self, unsigned value)
{
    *(unsigned short*)((char*)self + 0x28) = value;
}
