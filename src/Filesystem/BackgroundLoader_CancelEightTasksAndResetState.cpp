#include "Filesystem/BackgroundLoader.h"
// Only the task slots and reset flags touched here have established meanings.
struct LoaderTaskOwner {
    unsigned char unknown0[0x14];
    int tasks[8];
    int state34, state38;
    unsigned char unknown3c[0x18];
    unsigned char flag54, flag55, flag56, flag57;
    unsigned char unknown58[9];
    unsigned char flag61, flag62;
};
// Original: arm9/main @ 0x02094AB0; symbol: func_02094ab0; size: 0x7C.
extern "C" void BackgroundLoader_CancelEightTasksAndResetState(LoaderTaskOwner* owner)
{
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    for (unsigned char i = 0; i < 8; ++i) {
        if (owner->tasks[i] >= 0) {
            loader->RemoveTask(owner->tasks[i]);
            owner->tasks[i] = -1;
        }
    }
    owner->state34 = owner->state38 = -1;
    owner->flag56 = 1;
    owner->flag54 = owner->flag55 = owner->flag61 = owner->flag62 = owner->flag57 = 0;
}
