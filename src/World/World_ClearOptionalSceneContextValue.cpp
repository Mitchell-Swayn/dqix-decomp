#include <globaldefs.h>
// func_020733c8: 0x020733c8–0x020733d8, arm; 16 bytes
// Original: arm9/main @ 0x020733C8; symbol: func_020733c8; size: 0x10.
extern "C" void World_ClearOptionalSceneContextValue(int self) {
    if (self != 0) {
            *(unsigned int*)(self + 8) = 0;
        }
}
