#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov031_02290cc0[];
extern "C" void OV031_InitializeGlobalCallback();
extern "C" void SetSharedByte18();
extern "C" void System_QueueTimedCallbackForSharedRecord(unsigned);
extern "C" void SetMainLoopCallback(void*);
extern "C" void func_ov031_02232ac0();
// Original: arm9/ov031 @ 0x02232A84; symbol: func_ov031_02232a84; size: 0x3C.
extern "C" void ConfigureSecondContextDisplay() {
    if (*(unsigned char*)(*(unsigned*)(data_ov031_02290cc0 + 4) + 0x1d) == 2) OV031_InitializeGlobalCallback();
    SetSharedByte18();
    System_QueueTimedCallbackForSharedRecord(8);
    SetMainLoopCallback((void*)func_ov031_02232ac0);
}
