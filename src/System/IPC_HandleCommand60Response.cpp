#include <globaldefs.h>
ARM
#pragma opt_propagation off
// Original: arm9/main @ 0x020CE308; symbol: func_020ce308; size: 0x94.

#pragma always_inline on
// Original data: arm9/main @ 0x21117ec; symbol: data_021117ec.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" {extern unsigned PMGoSleepMode_UnknownRoleZeroInitializedStorage[];void IPC_ClearPendingAndInvokeCompletionCallback(void*);}
inline void* ErrorResult(unsigned short command){switch(command){case 0x61:case 0x62:return (void*)1;default:return (void*)2;}}
extern "C" void IPC_HandleCommand60Response(int tag,unsigned response,int error){
unsigned short command=(response&0x7f00)>>8;
unsigned short result=response&0xff;
if(error){IPC_ClearPendingAndInvokeCompletionCallback((void*)ErrorResult(command));return;}
switch(command){
case 0x61:{unsigned short* out=(unsigned short*)PMGoSleepMode_UnknownRoleZeroInitializedStorage[10];if(out)*out=result;result=0;break;}
case 0x60:result=0;break;
case 0x62:break;
case 0x63:PMGoSleepMode_UnknownRoleZeroInitializedStorage[3]=1;break;
}
IPC_ClearPendingAndInvokeCompletionCallback((void*)result);
}
