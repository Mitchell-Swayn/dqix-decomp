#include <globaldefs.h>
ARM
struct State;struct GameResources;
extern "C" void SnapshotSubBackgroundControlRegistersOnce(State*);
extern "C" void GameState_EnableGlobalFlag64();
extern "C" GameResources* GameResources_GetInstance();
// Original: arm9/ov003 @ 0x02173508; symbol: func_ov003_02173508; size: 0xBC.
extern "C" void Graphics_ConfigureSubBackgroundPrioritiesOnce(unsigned char* p){
 GameResources_GetInstance();
 if(p[0xef])return;
 GameState_EnableGlobalFlag64();
 SnapshotSubBackgroundControlRegistersOnce((State*)(p+0x10c));
 volatile unsigned* display=(volatile unsigned*)0x04001000;
 *(unsigned*)(p+0x124)=(*display&0x1f00)>>8;
 *display=(*display&~0x1f00)|0x1300;
 volatile unsigned short* bg=(volatile unsigned short*)0x04001008;
 bg[0]&=~3;
 bg[1]=(bg[1]&~3)|1;
 bg[2]=(bg[2]&~3)|2;
 bg[3]=(bg[3]&~3)|3;
 bg[0]=(bg[0]&0x43)|0xe00;
 bg[1]=(bg[1]&0x43)|0xf00;
 p[0xed]=1;p[0xef]=0;
}
