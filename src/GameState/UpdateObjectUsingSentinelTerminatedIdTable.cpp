#include <globaldefs.h>
ARM
#include <GameState/GameState.h>
extern "C" short data_020e8846[];extern "C" void func_020730e0(int,int);extern "C" void Resource_ApplyUpdateOnlyWhenValidationPasses(GameResources*,int,unsigned short);
// Original: arm9/main @ 0x02073240; symbol: func_02073240; size: 0x68.
extern "C" void UpdateObjectUsingSentinelTerminatedIdTable(int index){GameObject* obj=GameState::GetInstance()->GetGameObjectByIndex(index);if(!obj)return;for(int i=0;data_020e8846[i]>=0;i++)func_020730e0(index,data_020e8846[i]);if(!*(unsigned short*)((char*)obj+0x9c))return;GameResources* resources=GameResources_GetInstance();Resource_ApplyUpdateOnlyWhenValidationPasses(resources,index,(unsigned short)obj->obj3D_.unknown_9c_);}
