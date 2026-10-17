#include <globaldefs.h>
ARM
extern "C" void func_ov031_0223c078(int, int, int, int);
extern "C" void SetMainLoopCallback(void*);
extern "C" void func_ov031_02231aec();
// Original: arm9/ov031 @ 0x02231AB0; symbol: func_ov031_02231ab0; size: 0x3C.
extern "C" void ConfigureThirdContextEffects() {
    func_ov031_0223c078(3, 1, 1, 8);
    func_ov031_0223c078(3, 0, 0x15, 8);
    SetMainLoopCallback((void*)func_ov031_02231aec);
}
