#include <globaldefs.h>
#pragma optimization_level 1
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
extern "C" void GameObject_RequestMovementInputEnable();extern "C" unsigned SystemState_GetGlobalFlags();extern "C" void SystemState_ClearFlags(unsigned,int);
// Original: arm9/main @ 0x020D9FC8; symbol: func_020d9fc8; size: 0x6C.
extern "C" ARM void Resource_RemoveSingleBackgroundTaskAndMarkComplete(char* p){BackgroundLoader* loader=BackgroundLoader::GetInstance();for(int i=0;i<1;++i){if(*(int*)(p+i*4+12)!=-1){loader->RemoveTask(*(int*)(p+i*4+12));*(int*)(p+i*4+12)=-1;}}GameState::GetInstance()->GetUnknownGameObject();GameObject_RequestMovementInputEnable();SystemState_ClearFlags(SystemState_GetGlobalFlags(),30);p[1]=1;}
