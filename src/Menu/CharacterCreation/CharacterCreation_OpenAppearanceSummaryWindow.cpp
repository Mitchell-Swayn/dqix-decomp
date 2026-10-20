#include <globaldefs.h>
ARM
#include <std_library_functions.h>
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
extern "C" unsigned GameState_ReadSupportedFirmwareLanguage(...);
extern "C" unsigned ResourceStringTable_GetTextByKey(...);
extern "C" unsigned _ZN9GameState11GetInstanceEv(...);
extern "C" unsigned Window_PushTextCanvas(...);
// Original: arm9/ov023 @ 0x021d99a4; symbol: InitializeLanguageDependentTextPanel.
extern "C" void CharacterCreation_OpenAppearanceSummaryWindow(char* p){unsigned game=_ZN9GameState11GetInstanceEv();int value=24;unsigned lang=GameState_ReadSupportedFirmwareLanguage(game);char* panel=p+0x1f8;if(lang==4)value=25;lang=7;H(panel,0xa0)=lang;lang=17;H(panel,0xa2)=lang;H(panel,0xa4)=value;H(panel,0xa6)=5;H(panel,0xa8)=6;H(panel,0xaa)=6;H(panel,0xac)=10;H(panel,0xae)=16;B(panel,0xb1)=0;B(panel,0xb5)=1;B(panel,0xb6)=1;char* buffer=(char*)U(p,0xf8);memset(buffer,0,0x960);sprintf(buffer,(const char*)ResourceStringTable_GetTextByKey(p+0xe0,0x4274));Window_PushTextCanvas(panel,buffer,0,0,0,0,0,0);}
