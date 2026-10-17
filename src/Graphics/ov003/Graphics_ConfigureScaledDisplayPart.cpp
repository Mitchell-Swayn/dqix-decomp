#include <globaldefs.h>
ARM
struct Entry;
extern "C" Entry* FindSerializedPrimaryRecordByKey(void*,int);
extern "C" unsigned ScaleResolvedHalfwordByObjectPercentage(char*,unsigned short*);
extern "C" void ClearResolvedEntryByteC5Bit20(unsigned char*,int);
extern "C" void Object_SetGroupNibbleAndTextureLowFourBits(char*,int,unsigned char);
extern "C" void Object_SetSelectedPartInitialWord(char*,int,int);
extern "C" int Object_CreateAndConfigureSelectedDisplayPart(char*,int);
// Original: arm9/ov003 @ 0x0217726C; symbol: func_ov003_0217726c; size: 0x94.
extern "C" void Graphics_ConfigureScaledDisplayPart(char* self) {
char* object=*(char**)(self+0x89c);
char* entry=(char*)FindSerializedPrimaryRecordByKey(self+0x874,*(short*)(self+0x103a));
unsigned value=0;
switch(*(short*)(self+0x1004)) {
case 4: value=ScaleResolvedHalfwordByObjectPercentage(self,(unsigned short*)entry);break;
case 5: value=*(unsigned short*)(entry+0x1a);break;
}
unsigned scaled=value**(unsigned char*)(self+0x103c);
ClearResolvedEntryByteC5Bit20((unsigned char*)object,10);
Object_SetGroupNibbleAndTextureLowFourBits(object,10,0);
Object_SetSelectedPartInitialWord(object,0x5b,scaled);
Object_CreateAndConfigureSelectedDisplayPart(object,10);
}
