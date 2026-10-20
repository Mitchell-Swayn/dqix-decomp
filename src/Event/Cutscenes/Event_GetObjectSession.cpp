#include <globaldefs.h>
ARM
extern "C" {
// Original data: arm9/ov001 @ 0x2165880; symbol: data_ov001_02165880.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
    extern char EventGetObjectSession_UnknownRoleZeroInitializedStorage[];
}
// Original: arm9/ov001 @ 0x0215AB20; symbol: func_ov001_0215ab20; size: 0x34.
// Field roles beyond the stated offset operations remain uncertain.
extern "C" char* Event_GetObjectSession(int i) {
    if(i<0||i>=24)return 0;
    return *(char**)(EventGetObjectSession_UnknownRoleZeroInitializedStorage+28)+i*1416;
}
