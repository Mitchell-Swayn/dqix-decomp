#include <globaldefs.h>
ARM
namespace {
typedef void (*ParentStateCallback)(unsigned,unsigned,void*);
struct ParentCallbackState { char prefix[0x14e4]; ParentStateCallback callback; };
}
// Original data: arm9/ov027 @ 0x021E33EC; symbol: data_ov027_021e33ec.
// Shared multiboot context pointer; the existing parent-state owner reads the same callback slot.
extern "C" unsigned char* MBRegisterFile_UnknownRoleZeroInitializedStorage_Variant2;
#pragma force_active on
// Original: arm9/ov027 @ 0x021D8C6C; symbol: func_ov027_021d8c6c; size: 0x28.
// Forwards the child ID, parent state and payload to the installed callback.
extern "C" void MBi_CommChangeParentStateCallbackOnly(unsigned child,unsigned state,void* payload)
{
    ParentStateCallback callback = ((ParentCallbackState*)MBRegisterFile_UnknownRoleZeroInitializedStorage_Variant2)->callback;
    if (callback) callback(child,state,payload);
}
#pragma force_active reset
