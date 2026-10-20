// Original BSS: arm9/main @ 0x0211e33c; symbol: data_0211e33c.
// Shared file/resource scratch backing, not initialized ROM data.
// LoadFileIntoMemory (0x02075098) tests whether its buffer lies in this
// exact [base, base + 0x30000) range before releasing BackgroundLoader
// allocations. Original main passes the same base/capacity at 0x02000D68.
// The next original global is at the exact end, 0x0214E33C. Five interior
// labels remain linker aliases because callers reference scratch offsets.
// Preserve the original four-byte address alignment.
extern "C" {
__declspec(align(4)) unsigned char Main_UnknownRoleZeroInitializedStorage_Variant6[0x30000];
}
