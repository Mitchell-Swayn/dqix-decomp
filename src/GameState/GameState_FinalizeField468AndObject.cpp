#include <globaldefs.h>
#pragma optimization_level 4
extern "C" void Record_ClearThreeInitialWords(void*);
extern "C" void func_0200f3a4(void*);
// Original: arm9/main @ 0x02012200; symbol: func_02012200; size: 0x24.
extern "C" int GameState_FinalizeField468AndObject(int object) {
    Record_ClearThreeInitialWords((char*)object + 0x468);
    func_0200f3a4((void*)object);
    return object;
}
