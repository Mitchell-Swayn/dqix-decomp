#include <globaldefs.h>
ARM
// Original data: arm9/ov027 @ 0x21e33e0; symbol: data_ov027_021e33e0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov027.md.
extern "C" unsigned char MBEnd_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov027 @ 0x021DB4E0; symbol: func_ov027_021db4e0; size: 0x44.
// Clears communication-start flags and forwards the original argument to the end notification.
extern "C" void MBi_EndCommon(void *argument)
{
    (*(unsigned char**)(MBEnd_UnknownRoleZeroInitializedStorage+8))[0x50d]=0;
    *(unsigned short*)(*(unsigned char**)(MBEnd_UnknownRoleZeroInitializedStorage+12)+0x1316)=0;
    void (*callback)(int,void*)=*(void(**)(int,void*))(*(unsigned char**)(MBEnd_UnknownRoleZeroInitializedStorage+8)+0x51c);
    if(callback)callback(17,argument);
}
