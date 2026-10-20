#include <globaldefs.h>
ARM
extern "C" int DisplayOverlay_ConfigureGlobalState(...);
extern "C" int GameResources_GetInstance(...);
extern "C" int GameState_RebuildRecordsForNonprotagonistObjects(...);
extern "C" int SystemState_GetGlobalFlags(...);
extern "C" int TouchMovement_ResetGestureTracking(...);
extern "C" int GameObject_DisableMovementInput(...);
extern "C" int GameResources_SetSecondaryFlags(...);
extern "C" int GameResources_GetTouchMovementController(...);
extern "C" int TextContext_GetSharedInstance(...);
extern "C" int SystemState_SetFlags(...);
extern "C" int TextPanel_InitializeFormattedName(...);
extern "C" int Text_MapInputBytesToVariableLengthOutputSequences(...);
extern "C" int GameResources_SetPartyStatusSnapshotTracking(...);
extern "C" int _ZN9GameState11GetInstanceEv(...);
extern "C" int _ZN9GameState20GetUnknownGameObjectEv(...);
extern "C" int __clear(...);
extern "C" int Field_ClearTouchHudCapture(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);extern "C" char* strcpy(char*,const char*);extern "C" int sprintf(char*,const char*,...);

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov017 @ 0x021AFCEC; symbol: CommitFormattedPartyNameAndResumeResourceDisplay.
extern "C" int Field_PreparePartyJoinNameDisplay(char*self){
int state=_ZN9GameState11GetInstanceEv();char*resources=C(GameResources_GetInstance());char*owner=C(TextContext_GetSharedInstance());int global=SystemState_GetGlobalFlags();if(B(self,9)==2)GameState_RebuildRecordsForNonprotagonistObjects(global);if(B(self,644)){int actor=_ZN9GameState20GetUnknownGameObjectEv(state);if(actor)GameObject_DisableMovementInput(actor,0);}if(B(self,9)!=2){TextPanel_InitializeFormattedName(self,self+14);int offset=(short)B(self,12)*48;struct View{inline int Base(){return (int)this+0x435c;}};int destination=((View*)resources)->Base();char output[48];__clear(output,48);Text_MapInputBytesToVariableLengthOutputSequences(self+14,output,1);strcpy((char*)(destination+offset),output);}GameResources_SetSecondaryFlags(resources,64);GameResources_SetPartyStatusSnapshotTracking(0,-1);DisplayOverlay_ConfigureGlobalState(1,1,0,1);B(owner+0x1000,0x9d0)=1;Field_ClearTouchHudCapture(resources);TouchMovement_ResetGestureTracking(GameResources_GetTouchMovementController(resources));SystemState_SetFlags(global,0x40000);return 1;
}
