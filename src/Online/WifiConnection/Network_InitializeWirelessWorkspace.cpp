#include "globaldefs.h"
#include "std_library_functions.h"
#define H(p,o) (*(unsigned short*)((unsigned char*)(p)+(o)))
#define S(p,o) (*(short*)((unsigned char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((unsigned char*)(p)+(o)))
#define P(p,o) (*(unsigned char**)((unsigned char*)(p)+(o)))
// Original data: arm9/ov031 @ 0x224e53c; symbol: data_ov031_0224e53c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
struct Alarm;extern unsigned char*volatile NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage;extern "C" int _Z20DisableIRQInterruptsv(),_Z20SetIRQInterruptStatei(int);extern "C" bool _Z23Is64BitTimerInitializedv(),_Z22IsAlarmListInitializedv();extern "C" void _Z20Initialize64BitTimerv(),_Z25InitializeActiveAlarmListv(),_Z19ZeroInitializeAlarmP5Alarm(Alarm*),System_SetWorkspaceTimerControlWord(),System_InitializeWorkspaceMutex();
// Original: arm9/ov031 @ 0x0220C970; symbol: func_ov031_0220c970; size: 0x118.
extern "C" ARM int Network_InitializeWirelessWorkspace(unsigned char*buffer,unsigned size){int irq=_Z20DisableIRQInterruptsv();if(NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage){_Z20SetIRQInterruptStatei(irq);return 1;}if(!buffer){_Z20SetIRQInterruptStatei(irq);return 1;}if((unsigned)buffer&31){_Z20SetIRQInterruptStatei(irq);return 1;}if(size<0x2300){_Z20SetIRQInterruptStatei(irq);return 6;}NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage=buffer;W(buffer,0x2260)=1;H(NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage,0x2280)=0;H(NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage,0x2268)=0;NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage[0x226a]=0;NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage[0x226b]=0;H(NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage,0x2282)=0;H(NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage,0x22f8)=0;System_SetWorkspaceTimerControlWord();System_InitializeWorkspaceMutex();if(!_Z23Is64BitTimerInitializedv())_Z20Initialize64BitTimerv();if(!_Z22IsAlarmListInitializedv())_Z25InitializeActiveAlarmListv();_Z19ZeroInitializeAlarmP5Alarm((Alarm*)(NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage+0x22cc));_Z20SetIRQInterruptStatei(irq);return 0;}