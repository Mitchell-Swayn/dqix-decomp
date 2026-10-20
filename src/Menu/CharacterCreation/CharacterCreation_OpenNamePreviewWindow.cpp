#include <globaldefs.h>
ARM
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
extern "C" unsigned ResourceStringTable_GetTextByKey(...);
extern "C" unsigned Window_PushTextCanvas(...);
extern "C" unsigned memset(...);
extern "C" unsigned sprintf(...);
// Original: arm9/ov023 @ 0x021D9DA4; symbol: ConfigureAndSubmitResolvedText4274; size: 0xbc.
// Configures text view geometry, resolves format4274 and submits cleared formatted buffer.
extern "C" void CharacterCreation_OpenNamePreviewWindow(char* p){
 char* view=p+0x2b4;H(view,0xa0)=10;H(view,0xa2)=2;H(view,0xa4)=11;H(view,0xa6)=4;H(view,0xa8)=0;H(view,0xaa)=2;H(view,0xac)=17;H(view,0xae)=16;
 B(view,0xb1)=3;B(view,0xb7)=10;B(view,0xb5)=1;B(view,0xb6)=1;unsigned text=U(p,0xf8);memset(text,0,0x960);unsigned format=ResourceStringTable_GetTextByKey(p+0xe0,0x4274);sprintf(text,format);Window_PushTextCanvas(view,text,0,0,0,0,0,0);
}
