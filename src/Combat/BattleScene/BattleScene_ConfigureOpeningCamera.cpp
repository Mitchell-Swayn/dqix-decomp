#include <globaldefs.h>
ARM
class GameState {public:static GameState* GetInstance();};
struct Vec {int x,y,z;};
extern "C" {void* GameResources_GetInstance();void Combat_UpdateSelectedObjectVisibility(void*,int,int);void BattleCamera_FrameFormation(void*,int,int,int,int,int,int,int);void Camera_SetOrbitParameters(void*,Vec*);void BattleCamera_SetOrbitInterpolation(void*,Vec*,int,int);}
// Original: arm9/ov000 @ 0x0216118C; symbol: func_ov000_0216118c; size: 0xd8.
// Frames the opening scene and offsets its initial orbit when no remote turn data is present.
extern "C" void BattleScene_ConfigureOpeningCamera(unsigned char* scene,int offset) {
 GameState::GetInstance();GameResources_GetInstance();
 Combat_UpdateSelectedObjectVisibility(scene,0x26,0);
 BattleCamera_FrameFormation(scene+0xc18,1,1,0,0,0,0,1);
 if(offset && !*(int*)(*(unsigned char**)(scene+0x29c)+0x8e20)) {
  Vec target=*(Vec*)(scene+0xc88);
  Vec orbit=target;
  orbit.y+=0x800;orbit.z+=0x3000;
  Camera_SetOrbitParameters(scene+0xc18,&orbit);
  BattleCamera_SetOrbitInterpolation(scene+0xc18,&target,0xf33,0);
 }
}
