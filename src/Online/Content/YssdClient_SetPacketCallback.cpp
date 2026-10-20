#pragma thumb off
// Original data: arm9/ov031 @ 0x224e588; symbol: data_ov031_0224e588.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char* YssdClientRunWorker_UnknownRoleZeroInitializedStorage;
// Stores a word at offset 0xA0C through the pointer held in the overlay global.
// Original: arm9/ov031 @ 0x02210314; symbol: func_ov031_02210314; size: 0x18.
extern "C" void YssdClient_SetPacketCallback(unsigned int value)
{
    if (YssdClientRunWorker_UnknownRoleZeroInitializedStorage != 0)
        *(unsigned int*)(YssdClientRunWorker_UnknownRoleZeroInitializedStorage + 0xA0C) = value;
}
