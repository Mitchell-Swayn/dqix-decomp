#include <globaldefs.h>
ARM
extern "C" void Window_ResetResourceTransfers(void*);
extern "C" int Graphics_InvokeTwoIndexTransferCallback(void*, void*, int);
extern "C" void Graphics_TransferScreenBuffer(void*, int);
extern "C" void Resource_ResetOwnerCacheWhenFlagged(void*);
struct OwnerStateFlags { unsigned short lower:9; unsigned short bit9:1; unsigned short upper:6; };
// Original: arm9/ov023 @ 0x021EB4F4; symbol: func_ov023_021eb4f4; size: 0x70.
extern "C" void Resource_ResetActiveOwnerState(unsigned char* object) {
    if (object[0x431] == 0) return;
    Window_ResetResourceTransfers(object + 0xc4);
    if ((*(unsigned short*)(object + 0x438) & 0x40) != 0 || (*(unsigned short*)(object + 0x438) & 0x200) != 0) {
        int index = *(short*)(object + 0x43a);
        Graphics_InvokeTwoIndexTransferCallback(object + 0x64, 0, index);
        Graphics_TransferScreenBuffer(object + 0x64, 0);
        ((OwnerStateFlags*)(object + 0x438))->bit9 = 0;
    }
    Resource_ResetOwnerCacheWhenFlagged(object);
}
