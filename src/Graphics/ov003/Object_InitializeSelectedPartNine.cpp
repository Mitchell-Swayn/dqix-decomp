#include <globaldefs.h>
ARM
extern "C" void ClearResolvedEntryByteC5Bit20(unsigned char*, int);
extern "C" void Object_SetGroupNibbleAndTextureLowFourBits(char*, int, unsigned char);
extern "C" void Object_SetSelectedPartInitialWord(char*, int, int);
extern "C" void SetKeyedRecordFlagMaskOne(unsigned char*, int);
extern "C" int Object_CreateAndConfigureSelectedDisplayPart(char*, int);
// Original: arm9/ov003 @ 0x02177208; symbol: func_ov003_02177208; size: 0x64.
extern "C" void Object_InitializeSelectedPartNine(void* object) {
    char* part = *(char**)((char*)object + 0x89c);
    ClearResolvedEntryByteC5Bit20((unsigned char*)part, 9);
    Object_SetGroupNibbleAndTextureLowFourBits(part, 9, 0);
    int value = *(unsigned char*)((char*)object + 0x103c);
    Object_SetSelectedPartInitialWord(part, 0x57, value);
    SetKeyedRecordFlagMaskOne((unsigned char*)part, 0x58);
    SetKeyedRecordFlagMaskOne((unsigned char*)part, 0x59);
    Object_CreateAndConfigureSelectedDisplayPart(part, 9);
}
