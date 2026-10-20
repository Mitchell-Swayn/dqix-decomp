#include <globaldefs.h>
ARM
extern "C" void TextCanvas_SetEntryMessageKey(char *p,int i,short v);
extern "C" int TextCanvas_CreateAndConfigureDisplayPart(char* self,int index);
// Original: arm9/ov006 @ 0x0215F348; symbol: func_ov006_0215f348; size: 0x90.
extern "C" void Graphics_ConfigureThreeModeSelectedDisplayEntries(char *self) {
    short value = -1;
    switch (*(short*)(self + 0x360)) {
    case 2: value = 4; break;
    case 3: value = 7; break;
    case 4: break;
    }
    short slot = 5;
    for (unsigned char i = 0; i < 3; i++) {
        TextCanvas_SetEntryMessageKey(*(char**)(self + 0x14), slot, value);
        slot++;
        if (value >= 0) value++;
    }
    TextCanvas_CreateAndConfigureDisplayPart(*(char**)(self + 0x14), 3);
}
