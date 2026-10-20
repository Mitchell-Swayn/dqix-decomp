#include <globaldefs.h>
ARM
extern "C" void Menu_InitializeCatalogue(void *object);
// Original: arm9/ov023 @ 0x021FC228; symbol: func_ov023_021fc228; size: 0x10.
extern "C" void MenuScript_ResetExecutionContext(void *object) {
    Menu_InitializeCatalogue((char *)object + 0x20);
}
