#include <globaldefs.h>
ARM
#include <std_library_functions.h>
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
struct CountPrice{unsigned count:7,price:25;};
struct FlagBits{unsigned char a:1,b:1,index:6;};
struct Nibbles{unsigned char low:4,high:4;};
struct SixFlags{unsigned char index:6,a:1,b:1;};
extern "C" unsigned GameState_EnableGlobalFlag64(...);
extern "C" unsigned GameState_ReadPResources(...);
extern "C" unsigned _Z28IsBrightnessTransitionActiveP13GameResources(...);
extern "C" unsigned _ZN16BackgroundLoader11GetInstanceEv(...);
extern "C" unsigned _ZN9GameState11GetInstanceEv(...);
// Original: arm9/ov008 @ 0x0218599c; symbol: FinishBrightnessTransitionAndConfigureSubBackgrounds.
extern "C" void RecordsScreen_FinishPanelEntryFade(char* p){void* resources=(void*)GameState_ReadPResources(_ZN9GameState11GetInstanceEv());_ZN16BackgroundLoader11GetInstanceEv();unsigned state=B(p,0xb11);if(state==0){if(!_Z28IsBrightnessTransitionActiveP13GameResources(resources))B(p,0xb11)++;}if(state!=1)return;GameState_EnableGlobalFlag64();volatile unsigned short* bg=(volatile unsigned short*)0x4001008;bg[0]=(bg[0]&0x43)|0x600;bg[1]=(bg[1]&0x43)|0x704;bg[0]=(bg[0]&~3)|2;bg[1]=(bg[1]&~3)|3;bg[2]=(bg[2]&~3)|1;bg[3]=bg[3]&~3;volatile unsigned* control=(volatile unsigned*)0x4001000;*control=(*control&~0x1f00)|0x1300;B(p,0xb10)=0;B(p,0xb11)=0;}
