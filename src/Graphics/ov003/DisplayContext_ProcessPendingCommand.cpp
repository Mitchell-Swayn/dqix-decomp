#include <globaldefs.h>
ARM
extern "C" unsigned int Object_ReadGlobalDisplayContextWord();
extern "C" void DisplayContext_IgnoreCommand(void*, int, int, int, int);
extern "C" int ReturnOne_Main02094B4C();
extern "C" void DisplayContext_ProcessPendingCommand(unsigned char* object);
// Original: arm9/ov003 @ 0x021685DC; symbol: func_ov003_021685dc; size: 0x78.
extern "C" void DisplayContext_ProcessPendingCommand(unsigned char* object) {
    if (!object[0x5a4]) return;
    if (!object[0x5a5]) {
        unsigned int context = Object_ReadGlobalDisplayContextWord();
        DisplayContext_IgnoreCommand((void*)context, 0x1f5, 0x66, 0, 0);
        object[0x5a5]++;
        return;
    }
    if (object[0x5a5] == 1) {
        unsigned int context = Object_ReadGlobalDisplayContextWord();
        if (ReturnOne_Main02094B4C()) {
            object[0x5a4] = 0;
            object[0x5a5] = 0;
        }
    }
}
