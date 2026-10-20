#include <globaldefs.h>
ARM
extern "C" void* ZonePalette_GetColorTable();
extern "C" void* memcpy(void*,const void*,unsigned);
extern "C" void _Z25CleanInvalidateCacheRangePKvj(const void*,unsigned);
extern "C" void LoadToMainObjStandardPalette(const void*,unsigned,unsigned);
// Original: arm9/ov002 @ 0x0215AF64; symbol: func_ov002_0215af64; size: 0x54.
// Copies the selected palette's last color into the sprite swatch and uploads it.
extern "C" void PartyMenu_LoadSelectedPaletteSwatch(char* self) {
 void* destination=*(void**)(self+0x1bd8);
 unsigned char index=*(short*)(self+0x1c06);
 char* table=(char*)ZonePalette_GetColorTable();
 memcpy(destination,table+index*32+30,2);
 _Z25CleanInvalidateCacheRangePKvj(destination,2);
 LoadToMainObjStandardPalette(destination,0x11e,2);
}
