#pragma dont_inline on
#include "CartridgeService.h"
extern void ARM7_BiosCpuSet(const void*,void*,unsigned int);
extern int ARM7_AllocateLockOwner(void);
/* Clear the boot word with BIOS CpuSet, then reserve a cartridge lock owner. */
// Original: arm7/wram @ 0x03807348; symbol: ARM7_InitializeCartridgeLockState.
void ARM7_InitializeCartridgeLockState(void)
{
 unsigned int zero=0;
 ARM7_BiosCpuSet(&zero,&ARM7_CartridgeBootWord,0x05000001);
 ARM7_CartridgeLockState.lockOwner=ARM7_AllocateLockOwner();
}
