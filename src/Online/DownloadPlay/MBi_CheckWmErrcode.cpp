#include <globaldefs.h>
ARM
// Original data: arm9/ov027 @ 0x21e33e0; symbol: data_ov027_021e33e0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov027.md.
extern "C" unsigned char MBEnd_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov027 @ 0x021DD0CC; symbol: func_ov027_021dd0cc; size: 0x38.
// Reports wireless command errors except success and pending via the registered callback.
extern "C" void MBi_CheckWmErrcode(int operation,int result)
{
    if(result==2 || result==0)return;
    unsigned short error[2];
    error[0]=operation;
    error[1]=result;
    ((void(*)(int,void*))(*(unsigned*)(*(unsigned char**)(MBEnd_UnknownRoleZeroInitializedStorage+8)+0x51c)))(255,error);
}
