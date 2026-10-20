#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Resource/GameResources.h>
#include <Resource/Brightness.h>
ARM
struct IntegerParameterView;
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView*);
extern "C" GameResources* GameState_ReadPResources(GameState*);
// Original: arm9/ov001 @ 0x0215B454; symbol: func_ov001_0215b454; size: 0x6C.
// Reads a duration and optional brightness, then marks supported display modes active.
extern "C" int Script_SetSubBrightnessAndEnableDisplay(IntegerParameterView* parameters,int count) {
 int brightness;
 int duration=Script_ReadParameterAsInteger(parameters);
 brightness=-16;
 if(count>=2)brightness=Script_ReadParameterAsInteger((IntegerParameterView*)((char*)parameters+8));
 GameResources* resources=GameState_ReadPResources(GameState::GetInstance());
 if(resources) {
  SetSubBrightness(resources,brightness,duration);
  char* display=(char*)GameResources_GetInstance()->unknown_ptr_array_371c[6];
  if(*(unsigned short*)(display+10)<=3)display[0x102]=1;
 }
 return 1;
}
