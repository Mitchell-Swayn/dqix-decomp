#include <globaldefs.h>
extern "C" unsigned char data_02109bf4[];
extern "C" void func_ov017_021aaf08(void*);
extern "C" bool Sound_HasTypeOneJobForOwnerId(void*);
extern "C" void ResourceHandle_UpdateModeSelectedSecondaryHandle(char*);
extern "C" void UpdateByteLevelTransitionAndThreeChannels(unsigned char*, unsigned char, int);
// Original: arm9/ov017 @ 0x021AB010; symbol: func_ov017_021ab010; size: 0x50.
extern "C" ARM void Ov017_SetOwnerActiveAndUpdateSound(bool* owner, int updateSound) {
    func_ov017_021aaf08(owner);
    if (updateSound && !Sound_HasTypeOneJobForOwnerId((void*)data_02109bf4)) {
        ResourceHandle_UpdateModeSelectedSecondaryHandle((char*)data_02109bf4);
        UpdateByteLevelTransitionAndThreeChannels(data_02109bf4, 0x7f, 0);
    }
    *((unsigned char*)owner + 1) = 1;
}
