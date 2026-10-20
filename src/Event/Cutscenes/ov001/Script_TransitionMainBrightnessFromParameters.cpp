#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Resource/Brightness.h>
ARM
struct IntegerParameterView { unsigned type; union { int integer; float real; } value; };
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView*);
extern "C" GameResources* GameState_ReadPResources(GameState*);
// Original: arm9/ov001 @ 0x0215B50C; symbol: Script_TransitionMainBrightnessFromParameters; size: 0x54.
// Reads duration and optional brightness (default -16), applies the main display transition if resources exist, and returns1.
extern "C" int Script_TransitionMainBrightnessFromParameters(IntegerParameterView* parameters,int count)
{
 int brightness;
 int duration=Script_ReadParameterAsInteger(parameters);
 brightness=-16;
 if(count>=2)brightness=Script_ReadParameterAsInteger(parameters+1);
 GameResources* resources=GameState_ReadPResources(GameState::GetInstance());
 if(resources){SetMainBrightness(resources,brightness,duration);GameResources_GetInstance();}
 return 1;
}
