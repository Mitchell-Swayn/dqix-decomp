#include <globaldefs.h>
ARM
extern "C" int WirelessCommand_SubmitOpcodeOne(void*);
extern "C" void MBi_CheckWmErrcode(int,int);
// Original data: arm9/ov027 @ 0x21e33e0; symbol: data_ov027_021e33e0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov027.md.
extern "C" unsigned char MBEnd_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov027 @ 0x021DCC48; symbol: func_ov027_021dcc48; size: 0x38.
// Submits wireless reset, reports errors and normalizes the pending result to success.
extern "C" int MBi_CallReset(void)
{
    int result=WirelessCommand_SubmitOpcodeOne(*(void**)(*(unsigned char**)(MBEnd_UnknownRoleZeroInitializedStorage+8)+0x508));
    MBi_CheckWmErrcode(1,result);
    if(result==2)result=0;
    return result;
}
