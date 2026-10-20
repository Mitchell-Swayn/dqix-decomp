#include <globaldefs.h>
ARM
extern "C" void _Z30NitroVM_AwaitCommandCompletionP7NitroVM(void*);
extern "C" int _Z12NitroVM_SeekP7NitroVMii(void*, int, int);
extern "C" int _Z16NitroVM_ReadSyncP7NitroVMPvi(void*, void*, int);
// Original: arm9/ov016 @ 0x0218F58C; symbol: func_ov016_0218f58c; size: 0x70.
extern "C" int Filesystem_ReadFromNitroVMState(void* self, void* destination, int length) {
    if (*(unsigned char*)((char*)self + 0x10) == 1) {
        _Z30NitroVM_AwaitCommandCompletionP7NitroVM(*(void**)((char*)self + 0xC));
        _Z12NitroVM_SeekP7NitroVMii(*(void**)((char*)self + 0xC), *(int*)((char*)self + 8), 0);
        *(unsigned char*)((char*)self + 0x10) = 0;
    }
    int result = _Z16NitroVM_ReadSyncP7NitroVMPvi(*(void**)((char*)self + 0xC), destination, length);
    if (result == -1) goto failed;
    *(int*)((char*)self + 8) += length;
    return 1;
failed:
    return 0;
}
