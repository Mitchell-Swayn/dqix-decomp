#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" unsigned char data_ov031_02290d40;
extern "C" int IPC_SendNormalizedBooleanModeCommand(int mode);
// Original: arm9/ov031 @ 0x0223D704; symbol: func_ov031_0223d704; size: 0x7C.
extern "C" void System_SynchronizeIpcModeWithHardwareFlag() {
 if (data_ov031_02290d40) {
 if (((*(volatile unsigned short*)0x027fffa8 & 0x8000) >> 15) == 0) {
 if (!IPC_SendNormalizedBooleanModeCommand(1)) return;
 data_ov031_02290d40=0;
 }
 } else {
 if (((*(volatile unsigned short*)0x027fffa8 & 0x8000) >> 15) != 0) {
 if (IPC_SendNormalizedBooleanModeCommand(0)) data_ov031_02290d40=1;
 }
 }
}
