#include <globaldefs.h>
ARM
// Original data: arm9/ov027 @ 0x21e33e0; symbol: data_ov027_021e33e0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov027.md.
extern "C" unsigned char MBEnd_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov027 @ 0x021DB430; symbol: func_ov027_021db430; size: 0x60.
// Requires active MP, no pending send or shutdown, and a nonempty destination bitmap.
extern "C" int MBi_IsSendEnabled(void)
{
    int result=0,b=0,a=0;
    unsigned char *state=*(unsigned char**)(MBEnd_UnknownRoleZeroInitializedStorage+8);
    if(*(unsigned short*)(state+0x528)==1 && state[0x50c]==0)a=1;
    if(a && *(unsigned short*)(state+0x526)==0)b=1;
    if(b && *(unsigned short*)(state+0x52a)!=0)result=1;
    return result;
}
