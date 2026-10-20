#include <globaldefs.h>
#include <Resource/GameResources.h>
#include <Resource/Brightness.h>
extern "C" void *SystemState_GetGlobalFlags(),*NavigationMessage_GetGlobalInstance();
extern "C" int SystemState_TestAnyFlags(void*,int),NavigationMessage_ContainsActiveMessage(void*,int),NavigationMessage_ContainsSuspendedMessage(void*,int);
extern "C" void NavigationMessage_SuspendActiveQueue(void*),NavigationMessage_RestoreSuspendedQueue(void*),GameState_UpdateFourPartyMemberEntryFlagsAndTimers(void*),WorldMap_DrawActiveDisplayMode(void*),Graphics_BuildFormattedTextAndUploadSubObject(void*),Graphics_DrawConditionalSubDisplaySprites(void*),Graphics_UpdateSubBackgroundScrollByDisplayMode(void*);
extern "C" int GameResources_IsSelectedScreenBrightnessWithinExtremes(GameResources*,int),GameResources_IsSelectedScreenBrightnessAtOrBeyondExtreme(GameResources*,int),GameResources_IsSelectedScreenBrightnessNeutral(GameResources*,int);
// Original: arm9/main @ 0x0202343C; symbol: func_0202343c; size: 0x18C.
extern "C" void Object_UpdateGraphicsReadinessAndBrightness(unsigned char *self){
if(SystemState_TestAnyFlags(SystemState_GetGlobalFlags(),65))return;
GameResources *resources=GameResources_GetInstance();void *manager=NavigationMessage_GetGlobalInstance();
if(self[0x9c3]||*(signed char*)(self+0x9c2)<=0){if(NavigationMessage_ContainsActiveMessage(manager,4))NavigationMessage_SuspendActiveQueue(manager);return;}
if(NavigationMessage_ContainsSuspendedMessage(manager,4))NavigationMessage_RestoreSuspendedQueue(manager);
if(self[0x764]){if(self[0x778]){Graphics_BuildFormattedTextAndUploadSubObject(self);self[0x778]=0;}Graphics_DrawConditionalSubDisplaySprites(self);}else{GameState_UpdateFourPartyMemberEntryFlagsAndTimers(self);WorldMap_DrawActiveDisplayMode(self);}
if(NavigationMessage_ContainsActiveMessage(manager,4)){self[0x9c6]=0;self[0x9c7]=0;self[0x9c4]=1;self[0x9c8]=0;}
if(GameResources_IsSelectedScreenBrightnessWithinExtremes(resources,0)&&GameResources_IsSelectedScreenBrightnessAtOrBeyondExtreme(resources,1)){
if(self[0x9c6]||self[0x9c7])return;if(!self[0x9c4])return;
if(self[0x9c8]){--self[0x9c8];return;}Graphics_UpdateSubBackgroundScrollByDisplayMode(self);SetSubBrightness(resources,0,25);self[0x9c4]=0;
}else if(GameResources_IsSelectedScreenBrightnessNeutral(resources,1))self[0x9c4]=0;
}
