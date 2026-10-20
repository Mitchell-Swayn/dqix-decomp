#include <globaldefs.h>
// func_0203db24: 0x0203db24–0x0203db34, arm; 16 bytes
// Original: arm9/main @ 0x0203DB24; symbol: func_0203db24; size: 0x10.
extern "C" void ActorPool_BindSpriteResourceOwner(int self, unsigned int value) {
    int* output = *(int**)(self + 0x14);
        if (output != 0) {
            *output = (int)value;
        }
}
