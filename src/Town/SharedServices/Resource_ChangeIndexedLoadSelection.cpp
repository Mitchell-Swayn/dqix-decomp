#include <globaldefs.h>
ARM
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(void*, int);
// Original: arm9/ov003 @ 0x021538F4; symbol: func_ov003_021538f4; size: 0xAC.
extern "C" void Resource_ChangeIndexedLoadSelection(unsigned char *self, int selection) {
    if (!self[0x5a]) return;
    int index = *(signed char*)(self + 0x59);
    int valid = 0;
    if (index >= 0) valid = index <= 3;
    if (!valid) return;
    if (selection <= 0) return;
    if (selection >= 13) return;
    if (*(int*)(self + 0x14) == selection) return;
    void *loader = _ZN16BackgroundLoader11GetInstanceEv();
    if (*(int*)(self + 0x50) >= 0) _ZN16BackgroundLoader10RemoveTaskEi(loader, *(int*)(self + 0x50));
    if (*(int*)(self + 0x54) >= 0) _ZN16BackgroundLoader10RemoveTaskEi(loader, *(int*)(self + 0x54));
    *(int*)(self + 0x50) = -1;
    *(int*)(self + 0x54) = -1;
    *(int*)(self + 0x14) = selection;
    self[0x5b] = 0;
    self[0x5c] = 0;
    self[0x5d] |= 1;
}
