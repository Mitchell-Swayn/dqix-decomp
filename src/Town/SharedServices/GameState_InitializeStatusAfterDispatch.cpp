#include <globaldefs.h>
ARM
extern "C" bool DispatchNonnegativeMemberStateAndReadStatus(void*);
// Original: arm9/ov003 @ 0x02173490; symbol: func_ov003_02173490; size: 0x4C.
extern "C" void GameState_InitializeStatusAfterDispatch(void* state) {
    bool active = DispatchNonnegativeMemberStateAndReadStatus((char*)state + 0x1e0) != 0;
    if (!active) return;
    ((unsigned char*)state)[0xcc] = 1;
    ((unsigned char*)state)[0xd4] = 0;
    ((unsigned char*)state)[0xec] = 4;
    ((unsigned char*)state)[0xee] = 0;
    ((unsigned char*)state)[0xed] = 4;
    ((unsigned char*)state)[0xef] = 0;
}
