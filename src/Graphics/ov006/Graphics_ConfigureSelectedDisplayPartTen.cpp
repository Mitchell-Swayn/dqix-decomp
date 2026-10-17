#include <globaldefs.h>
ARM
extern "C" void Object_SetSelectedPartInitialWord(char* p, int i, int v);
extern "C" int Object_CreateAndConfigureSelectedDisplayPart(char* self, int index);

// Original: arm9/ov006 @ 0x0215F9E8; symbol: func_ov006_0215f9e8; size: 0x34.
// Copies the selection byte to part 61, creates part 10, and records index 10.
extern "C" void Graphics_ConfigureSelectedDisplayPartTen(unsigned char* object)
{
    Object_SetSelectedPartInitialWord(*(char**)(object + 0x14), 0x3d, object[0x38b]);
    Object_CreateAndConfigureSelectedDisplayPart(*(char**)(object + 0x14), 10);
    *(unsigned short*)(object + 0x36e) = 10;
}
