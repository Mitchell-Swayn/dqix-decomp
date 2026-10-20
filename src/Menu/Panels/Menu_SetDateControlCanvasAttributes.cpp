#include <globaldefs.h>
ARM
extern "C" void Window_SetCanvasDisplayAttribute(char*, int, int);
// Original: arm9/ov023 @ 0x021E6378; symbol: func_ov023_021e6378; size: 0x44.
extern "C" void Menu_SetDateControlCanvasAttributes(char* p, unsigned char value, int unused, int attr8, unsigned char attr9) {
    *(unsigned char*)(p + 0x1371) = value;
    Window_SetCanvasDisplayAttribute(p + 0xac, 7, unused);
    Window_SetCanvasDisplayAttribute(p + 0xac, 8, attr8);
    Window_SetCanvasDisplayAttribute(p + 0xac, 9, attr9);
}
