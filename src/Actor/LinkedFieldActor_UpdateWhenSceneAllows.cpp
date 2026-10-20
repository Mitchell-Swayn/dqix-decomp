#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Script.h"
#include "Resource/Brightness.h"
extern "C" GameResources* GameResources_GetInstance();
extern "C" void* Zone3D_GetMainInstance();
extern "C" void* GameState_GetAuxiliaryFieldObject(GameState*);
extern "C" int LinkedQueue_GetFrontKindOrInvalid(void*);
extern "C" unsigned char* LinkedQueue_GetFrontNode(void*);
extern "C" void LinkedFieldActor_UpdateMotionAndInteraction(void*);
extern "C" void Field_RefreshObjectFloorContactDescriptor(void*);
// Original: arm9/main @ 0x020AC9AC; symbol: func_020ac9ac; size: 0x84.
extern "C" ARM void LinkedFieldActor_UpdateWhenSceneAllows(GameResources* resources) {
void* object;
int mode;
void* controller;
GameState* state;
unsigned char* info;


 state=GameState::GetInstance();
 controller=*(void**)((unsigned char*)resources+0x36fc);
 Zone3D_GetMainInstance();
 object=GameState_GetAuxiliaryFieldObject(state);
 mode=LinkedQueue_GetFrontKindOrInvalid(controller);
 info=LinkedQueue_GetFrontNode(controller);
 if(!object) return;
 if(mode==10 && info[3]) return;
 if(mode==3 && !IsBrightnessTransitionActive(resources)) return;
 LinkedFieldActor_UpdateMotionAndInteraction(object); Field_RefreshObjectFloorContactDescriptor(object);
}
