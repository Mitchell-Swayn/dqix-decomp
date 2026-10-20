// Original BSS: arm9/main @ 0x02114ec4; symbol: data_02114ec4.
// Zero-filled backing for the text bootstrap SafeAllocator. Original main
// loads this address and capacity 0x9478 at 0x02000DD4/0x02000DD8, then
// calls SafeAllocator::CreateTypeA at 0x02000DE0, Reset at 0x02000DE8, and
// Text_InitializeSharedContextAndResources at 0x02000DF0. The exact end is
// the shared file scratch arena at 0x0211E33C.
// Preserve the original four-byte address alignment.
extern "C" {
__declspec(align(4)) unsigned char Main_UnknownRoleZeroInitializedStorage_Variant5[0x9478];
}
