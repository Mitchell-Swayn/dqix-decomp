#include <globaldefs.h>
ARM
extern "C" void _Z30NitroVM_AwaitCommandCompletionP7NitroVM(void* vm);
extern "C" int _Z12NitroVM_SeekP7NitroVMii(void* vm, int position, int mode);
// Original: arm9/ov016 @ 0x0218F540; symbol: func_ov016_0218f540; size: 0x4C.
extern "C" int NitroVM_SeekAndTrackPosition(char* self, int position) {
    if ((unsigned char)self[0x10] == 1) {
        _Z30NitroVM_AwaitCommandCompletionP7NitroVM(*(void**)(self + 0xc));
        self[0x10] = 0;
    }
    int result = _Z12NitroVM_SeekP7NitroVMii(*(void**)(self + 0xc), position, 0);
    int success;
    if (result == 0) {
        success = 0;
    } else {
        *(int*)(self + 8) = position;
        success = 1;
    }
    return success;
}
