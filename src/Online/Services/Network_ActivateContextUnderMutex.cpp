#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290fc0; symbol: data_ov031_02290fc0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" { extern int HttpCreateRequestFromUrl_UnknownRoleZeroInitializedStorage; int AllocateCircularListNodeAndReturnId(void*); void System_LockGlobalMutex(); void Http_UnlockRequestQueueMutex(); int Network_SendZeroMessageToContextQueue(); }
// Original: arm9/ov031 @ 0x02240EE8; symbol: func_ov031_02240ee8; size: 0x8C.
extern "C" int Network_ActivateContextUnderMutex(unsigned char* context) {
 if(*(int*)context) { HttpCreateRequestFromUrl_UnknownRoleZeroInitializedStorage=11; return -1; }
 if(*(int*)(context+0x40)==1 && !*(int*)(context+0x38)) { HttpCreateRequestFromUrl_UnknownRoleZeroInitializedStorage=11; return -1; }
 System_LockGlobalMutex();
 int result=AllocateCircularListNodeAndReturnId(context);
 if(result>=0) { *(int*)context=1; Network_SendZeroMessageToContextQueue(); }
 else HttpCreateRequestFromUrl_UnknownRoleZeroInitializedStorage=1;
 Http_UnlockRequestQueueMutex();
 return result;
}
