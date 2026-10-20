#include <globaldefs.h>
ARM
extern "C" void* GameResources_GetInstance(void);
extern "C" void Field_SetPartyMemberMessageFlag(void*, unsigned int);
extern "C" void Field_ClearPartyMemberMessageFlag(void*, unsigned int);
// Original: arm9/ov017 @ 0x021D2774; symbol: func_ov017_021d2774; size: 0x2C.
extern "C" void Resource_SetOverlayBitFromDescriptor(void* unused, unsigned char* descriptor) { void* resources = GameResources_GetInstance(); if (descriptor[5] != 0) Field_SetPartyMemberMessageFlag(resources, descriptor[4]); else Field_ClearPartyMemberMessageFlag(resources, descriptor[4]); }
