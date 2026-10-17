#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov031_02290cd8;
extern "C" void ReadOptionalSharedWords18And1C(unsigned*, unsigned*);
extern "C" unsigned func_ov031_02227558(void);
extern "C" void SetMainLoopCallback(void*);
extern "C" void System_ConfigureDisplayPlanesAndCallback(void);
extern "C" void func_ov031_02233f54(void);
// Original: arm9/ov031 @ 0x02234050; symbol: func_ov031_02234050; size: 0x70.
extern "C" void PollAndSelectMainLoopCallback(void) {
    data_ov031_02290cd8++;
    if (data_ov031_02290cd8 < 0xb4)
        return;
    unsigned sharedWord;
    ReadOptionalSharedWords18And1C(0, &sharedWord);
    unsigned state = func_ov031_02227558();
    if (state != 0 && state == 1 && sharedWord)
        SetMainLoopCallback((void*)System_ConfigureDisplayPlanesAndCallback);
    else
        SetMainLoopCallback((void*)func_ov031_02233f54);
}
