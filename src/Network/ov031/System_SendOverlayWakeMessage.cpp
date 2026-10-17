#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov031_02291f80[];
extern "C" unsigned char data_ov031_02291f24[];
extern "C" unsigned char data_ov031_02291f60[];
extern "C" int _Z17IsContextInactiveP16ProcessorContext(void* context);
extern "C" int OS_SendMessage(void* queue, void* message, int flags);
// Original: arm9/ov031 @ 0x02245938; symbol: func_ov031_02245938; size: 0x54.
extern "C" void System_SendOverlayWakeMessage(void) {
    if (*(void**)(data_ov031_02291f80 + 0x6C) == 0) return;
    if (_Z17IsContextInactiveP16ProcessorContext(data_ov031_02291f80) != 0) return;
    if (*(void**)(data_ov031_02291f24 + 4) != 0) return;
    *(unsigned*)(data_ov031_02291f24 + 4) = 1;
    OS_SendMessage(data_ov031_02291f60, 0, 0);
}
