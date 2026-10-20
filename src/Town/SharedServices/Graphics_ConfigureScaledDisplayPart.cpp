#include <globaldefs.h>
ARM
struct Entry;
extern "C" Entry* ZoneState2754_FindPrimaryRecordByKey(void*,int);
extern "C" unsigned Shop_GetAdjustedItemPrice(char*,unsigned short*);
extern "C" void TextCanvas_ShowDisplayPart(unsigned char*,int);
extern "C" void TextCanvas_SetGroupPalette(char*,int,unsigned char);
extern "C" void TextCanvas_SetEntryNumericValue(char*,int,int);
extern "C" int TextCanvas_CreateAndConfigureDisplayPart(char*,int);
// Original: arm9/ov003 @ 0x0217726C; symbol: func_ov003_0217726c; size: 0x94.
extern "C" void Graphics_ConfigureScaledDisplayPart(char* self) {
char* object=*(char**)(self+0x89c);
char* entry=(char*)ZoneState2754_FindPrimaryRecordByKey(self+0x874,*(short*)(self+0x103a));
unsigned value=0;
switch(*(short*)(self+0x1004)) {
case 4: value=Shop_GetAdjustedItemPrice(self,(unsigned short*)entry);break;
case 5: value=*(unsigned short*)(entry+0x1a);break;
}
unsigned scaled=value**(unsigned char*)(self+0x103c);
TextCanvas_ShowDisplayPart((unsigned char*)object,10);
TextCanvas_SetGroupPalette(object,10,0);
TextCanvas_SetEntryNumericValue(object,0x5b,scaled);
TextCanvas_CreateAndConfigureDisplayPart(object,10);
}
