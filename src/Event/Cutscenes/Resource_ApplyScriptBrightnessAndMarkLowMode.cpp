#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Resource/Brightness.h>
ARM
struct IntegerParameterView { unsigned type; union { int integer; float real; } value; };
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView*);
extern "C" GameResources* GameState_ReadPResources(GameState*);
extern "C" GameResources* GameResources_GetInstance();
// Original: arm9/ov001 @ 0x0215B318; symbol: func_ov001_0215b318; size: 0x6C.
extern "C" int Resource_ApplyScriptBrightnessAndMarkLowMode(IntegerParameterView* parameters,int count) {
 int brightness;
 int duration=Script_ReadParameterAsInteger(parameters);
 brightness=-16;
 if(count>=2) brightness=Script_ReadParameterAsInteger(parameters+1);
 GameResources* resources=GameState_ReadPResources(GameState::GetInstance());
 if(resources) {
  SetBrightness(resources,brightness,duration);
  unsigned char* state=*(unsigned char**)((unsigned char*)GameResources_GetInstance()+0x3734);
  if(*(unsigned short*)(state+0xa)<=3) state[0x102]=1;
 }
 return 1;
}
