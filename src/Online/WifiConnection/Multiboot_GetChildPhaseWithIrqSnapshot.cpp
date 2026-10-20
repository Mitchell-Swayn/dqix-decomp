#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290d14; symbol: data_ov031_02290d14.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
struct State{unsigned short fields[7];};extern "C" {int _Z20DisableIRQInterruptsv();int _Z20SetIRQInterruptStatei(int);void MI_CpuCopy8(const void*,void*,unsigned);extern State* MultibootGetParentState_UnknownRoleZeroInitializedStorage;}
// Original: arm9/ov031 @ 0x02239188; symbol: System_ReadChannelStatusWithIRQSnapshot; size: 0xc8.
extern "C" int Multiboot_GetChildPhaseWithIrqSnapshot(int channel){int irq=_Z20DisableIRQInterruptsv();unsigned short bit=1;bit<<=channel;State* state=MultibootGetParentState_UnknownRoleZeroInitializedStorage;if(!(state->fields[1]&bit)){_Z20SetIRQInterruptStatei(irq);return 0;}State copy;MI_CpuCopy8(state,&copy,14);_Z20SetIRQInterruptStatei(irq);if(copy.fields[2]&bit)return 2;if(copy.fields[3]&bit)return 3;if(copy.fields[4]&bit)return 4;if(copy.fields[5]&bit)return 5;if(copy.fields[6]&bit)return 6;return 1;}
