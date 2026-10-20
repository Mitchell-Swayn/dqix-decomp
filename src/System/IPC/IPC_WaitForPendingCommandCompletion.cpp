#pragma optimize_for_size off
#include <globaldefs.h>
ARM
#include "System/Interrupts.h"
#include "System/IPC.h"
// Original data: arm9/main @ 0x21117ec; symbol: data_021117ec.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2111808; symbol: data_02111808.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char PMGoSleepMode_UnknownRoleZeroInitializedStorage[];extern "C" volatile int IPCWaitForPendingCommandCompletion_UnknownRoleZeroInitializedStorage;
// Original: arm9/main @ 0x020CE1D8; symbol: func_020ce1d8; size: 0x5C.
extern "C" void IPC_WaitForPendingCommandCompletion() {volatile int* pending=&IPCWaitForPendingCommandCompletion_UnknownRoleZeroInitializedStorage;volatile unsigned short* reg=(volatile unsigned short*)0x04000208;if(!*(int*)(PMGoSleepMode_UnknownRoleZeroInitializedStorage+28))return;do{if(GetIRQInterruptState()==0x80||*reg==0||GetProcessorMode()==0x12)HandleCommandReceivedFromArm7();}while(*pending); }
