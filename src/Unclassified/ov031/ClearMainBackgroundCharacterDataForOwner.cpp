#include <globaldefs.h>
#include <System/BGBases.h>
#include <Graphics/NSBXX/JACInternal.h>
ARM
extern "C" void func_ov031_0223e2e0(int, unsigned int);
extern "C" void FreeSharedAllocationAndClearFlagWithInterruptMask(void **);
extern "C" void *data_ov031_02290d38;
// Original: arm9/ov031 @ 0x0223C760; symbol: func_ov031_0223c760; size: 0x64.
extern "C" void ClearMainBackgroundCharacterDataForOwner(void *owner) {
    func_ov031_0223e2e0(1, *(unsigned int *)((char *)owner + 0x2c));
    void *base = (char *)data_ov031_02290d38 + 0x610;
    if (owner == base) {
        MIi_CpuClear16(0, (void *)GetMainBG0CharacterBase(), 0x6000);
    } else {
        MIi_CpuClear16(0, (void *)GetMainBG0CharacterBase(), 0x3000);
    }
    FreeSharedAllocationAndClearFlagWithInterruptMask((void **)((char *)owner + 0x28));
}
