#include <globaldefs.h>
ARM
#include <GameState/GameState.h>
#include <World/Zone3D.h>
extern "C" int LinkedList_ContainsTag(unsigned,int),GameState_GetProgressChapter(GameState*);
// Original: arm9/main @ 0x020AD4C4; symbol: func_020ad4c4; size: 0xD8.
extern "C" unsigned World_TestSelectedZoneInstanceFlagWithStateInversion(unsigned char* zone){GameState* state=GameState::GetInstance();unsigned char* service=(unsigned char*)GameResources_GetInstance();if(LinkedList_ContainsTag(*(unsigned*)(service+0x36fc),4))return 0;unsigned id=*(unsigned short*)zone;unsigned short expected=0;int instance=0;if(id==0x1198){expected=1;instance=7;}else if(id==0x1198-0xcb){expected=3;instance=2;}else if(id==0x1198-0x68){if(GameState_GetProgressChapter(state)>=19)return 0;expected=5;instance=23;}if(expected&&instance){if(*(unsigned short*)(zone+0x27b4)==expected)return !((Zone3D*)zone)->IsInstanceFlag4Clear(instance,0);return ((Zone3D*)zone)->IsInstanceFlag4Clear(instance,0);}return 0;}
