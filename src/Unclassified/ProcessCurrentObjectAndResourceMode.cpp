#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Script.h"
#include "Resource/Brightness.h"
extern "C" GameResources* GameResources_GetInstance();
extern "C" void* ReadGlobalValueAt020FB3F0();
extern "C" void* Object_ReadWordAtOffset330(GameState*);
extern "C" int ReadIndirectByteOrMinusOne(void*);
extern "C" unsigned char* Record_ReadInitialWord(void*);
extern "C" void func_020ad61c(void*);
extern "C" void func_ov017_02193dc4(void*);
// Original: arm9/main @ 0x020AC9AC; symbol: func_020ac9ac; size: 0x84.
extern "C" ARM void ProcessCurrentObjectAndResourceMode(GameResources* resources) {
void* object;
int mode;
void* controller;
GameState* state;
unsigned char* info;


 state=GameState::GetInstance();
 controller=*(void**)((unsigned char*)resources+0x36fc);
 ReadGlobalValueAt020FB3F0();
 object=Object_ReadWordAtOffset330(state);
 mode=ReadIndirectByteOrMinusOne(controller);
 info=Record_ReadInitialWord(controller);
 if(!object) return;
 if(mode==10 && info[3]) return;
 if(mode==3 && !IsBrightnessTransitionActive(resources)) return;
 func_020ad61c(object); func_ov017_02193dc4(object);
}
