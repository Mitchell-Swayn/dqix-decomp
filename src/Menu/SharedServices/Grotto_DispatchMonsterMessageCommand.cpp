#include <globaldefs.h>
extern "C" void Grotto_AdvanceMonsterMessageScene(void);
ARM
// Original: arm9/ov004 @ 0x0216FA3C; symbol: func_ov004_0216fa3c; size: 0xC.
extern "C" void Grotto_DispatchMonsterMessageCommand(void) {
    Grotto_AdvanceMonsterMessageScene();
}
