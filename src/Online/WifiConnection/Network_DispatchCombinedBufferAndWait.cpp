#include <globaldefs.h>
ARM
extern "C" int _Z20DisableIRQInterruptsv();
extern "C" int _Z20SetIRQInterruptStatei(int);
extern "C" unsigned Network_GetWirelessWorkspace();
extern "C" void _Z9LockMutexP5Mutex(void*);
extern "C" void _Z11UnlockMutexP5Mutex(void*);
extern "C" void _Z19BlockCurrentContextP18BlockedContextList(void*);
extern "C" void MI_CpuCopy8(const void*,void*,unsigned);
extern "C" int WM_SetDCFData(int,const void*,void*,unsigned);
extern "C" void System_HandleType12Message();
// Original data: arm9/ov031 @ 0x224e540; symbol: data_ov031_0224e540.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x224e544; symbol: data_ov031_0224e544.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x224e54c; symbol: data_ov031_0224e54c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char NetworkSendEmptyDcfFrame_UnknownRoleZeroInitializedStorage[],SystemHandleType12Message_UnknownRoleZeroInitializedStorage_Variant2[],SystemHandleType12Message_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x0220F104; symbol: func_ov031_0220f104; size: 0x188.
extern "C" int Network_DispatchCombinedBufferAndWait(void* command,const void* first,int firstSize,const void* second,int secondSize) {
 int irq=_Z20DisableIRQInterruptsv();
 int total;
 if(!Network_GetWirelessWorkspace()){_Z20SetIRQInterruptStatei(irq);return -1;}
 _Z9LockMutexP5Mutex(NetworkSendEmptyDcfFrame_UnknownRoleZeroInitializedStorage);
 char* state=(char*)Network_GetWirelessWorkspace();
 if(!state){_Z11UnlockMutexP5Mutex(NetworkSendEmptyDcfFrame_UnknownRoleZeroInitializedStorage);_Z20SetIRQInterruptStatei(irq);return -1;}
 if(*(int*)(state+0x2260)!=9 || *(unsigned char*)(state+0x226b)==1){_Z11UnlockMutexP5Mutex(NetworkSendEmptyDcfFrame_UnknownRoleZeroInitializedStorage);_Z20SetIRQInterruptStatei(irq);return -4;}
 MI_CpuCopy8(first,state+0xf00,firstSize);
 if(secondSize>0)MI_CpuCopy8(second,state+0xf00+firstSize,secondSize);
 total=firstSize+secondSize;
 switch(WM_SetDCFData((int)System_HandleType12Message,command,state+0xf00,(unsigned short)total)){
 case 0:case 1:case 3:case 4:case 5:case 6:case 7:case 8:default:
 _Z11UnlockMutexP5Mutex(NetworkSendEmptyDcfFrame_UnknownRoleZeroInitializedStorage);_Z20SetIRQInterruptStatei(irq);return -5;
 case 2:break;
 }
 _Z19BlockCurrentContextP18BlockedContextList(SystemHandleType12Message_UnknownRoleZeroInitializedStorage_Variant2);
 switch(*(int*)(SystemHandleType12Message_UnknownRoleZeroInitializedStorage+0x24)){
 case 0:break;
 case 1:default:_Z11UnlockMutexP5Mutex(NetworkSendEmptyDcfFrame_UnknownRoleZeroInitializedStorage);_Z20SetIRQInterruptStatei(irq);return -5;
 }
 _Z11UnlockMutexP5Mutex(NetworkSendEmptyDcfFrame_UnknownRoleZeroInitializedStorage);_Z20SetIRQInterruptStatei(irq);return total;
}
