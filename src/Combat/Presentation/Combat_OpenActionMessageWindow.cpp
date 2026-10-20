#include <globaldefs.h>
ARM
extern "C" void* TextContext_GetSharedInstance(void*);
extern "C" void TextWindow_StartFormattedMessage(void*, unsigned, unsigned, unsigned);
extern "C" void TextWindow_SetViewportRectangle(char*, int, int, int, int);
// Original: arm9/ov025 @ 0x021E5E1C; symbol: InitializeObjectRectangleAndFlags; size: 0x68.
// Initializes the object from self +8, clears byte +0x19B1/+0x19B2, sets rectangle coordinates, and writes one at +0x998.
extern "C" void Combat_OpenActionMessageWindow(void* self) {
    void* object = TextContext_GetSharedInstance(self);
    TextWindow_StartFormattedMessage(object, *(unsigned*)((char*)self + 8), 0, 0xE3);
    *(unsigned char*)((char*)object + 0x19B1) = 0;
    TextWindow_SetViewportRectangle((char*)object, 2, 0x92, 0xFC, 0x4A);
    *(unsigned char*)((char*)object + 0x19B2) = 0;
    *(unsigned*)((char*)object + 0x998) = 1;
}
