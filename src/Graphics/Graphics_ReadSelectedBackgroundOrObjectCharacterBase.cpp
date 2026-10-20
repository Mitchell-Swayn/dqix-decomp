#include <globaldefs.h>
#include <System/BGBases.h>
// Original: arm9/main @ 0x020E12C0; symbol: func_020e12c0; size: 0x94.
extern "C" ARM unsigned Graphics_ReadSelectedBackgroundOrObjectCharacterBase(const unsigned char *p){unsigned value=0;switch(p[8]){case 0:break;case 1:value=GetMainBG0CharacterBase();break;case 2:value=GetMainBG1CharacterBase();break;case 3:value=GetMainBG2CharacterBase();break;case 4:value=GetMainBG3CharacterBase();break;case 5:value=0x06400000;break;case 6:value=GetSubBG0CharacterBase();break;case 7:value=GetSubBG1CharacterBase();break;case 8:value=GetSubBG2CharacterBase();break;case 9:value=GetSubBG3CharacterBase();break;case 10:value=0x06600000;break;}return value;}
