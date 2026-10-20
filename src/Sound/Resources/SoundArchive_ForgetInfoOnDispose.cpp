#include <globaldefs.h>
// func_020bd8f0: 0x020bd8f0–0x020bd8fc, arm; 12 bytes
// Original: arm9/main @ 0x020BD8F0; symbol: func_020bd8f0; size: 0xC.
extern "C" void SoundArchive_ForgetInfoOnDispose(unsigned int ignored0, unsigned int ignored1, int self) {
    *(unsigned int*)(self + 0x8c) = 0;
}
