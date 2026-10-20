#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
struct GameResources;struct Buffer;
extern "C" {
GameResources* GameResources_GetInstance();unsigned TextContext_GetSharedInstance();
int _Z28IsBrightnessTransitionActiveP13GameResources(void*);int GameResources_GetSelectedScreenBrightness(char*,int);void _Z17SetMainBrightnessP13GameResourcesii(void*,int,int);
void* _ZN9GameState11GetInstanceEv();unsigned char GameState_ReadFirstObjectIndex(GameState*);GameObject* GameState_GetObjectWithFlag100(GameState*,int);
void TextLayout_ResetFormattingWorkspace(signed char*);void TextContext_SetStringArgument(Buffer*,int,const char*);
void* ResourceStringTable_GetTextByKey(void*,void*);void Church_StartConfiguredMessage(void*,void*);
}
// Original: arm9/ov003 @ 0x0215AF9C; symbol: func_ov003_0215af9c; size: 0x14C.
// Waits for brightness completion, prepares the selected owner's name, and opens its indexed message.
extern "C" void AdvanceBrightnessAndOwnerMessageState(unsigned char* p){
 GameResources* game=GameResources_GetInstance();char* owner=(char*)TextContext_GetSharedInstance();unsigned char phase=p[0x580];
 if(phase==0){if(!_Z28IsBrightnessTransitionActiveP13GameResources(game)&&GameResources_GetSelectedScreenBrightness((char*)game,0)&&GameResources_GetSelectedScreenBrightness((char*)game,1))_Z17SetMainBrightnessP13GameResourcesii(game,0,15);++p[0x580];}
 if(phase==1){
  if(p[0x59d])return;if(_Z28IsBrightnessTransitionActiveP13GameResources(game))return;if(GameResources_GetSelectedScreenBrightness((char*)game,0))return;
  if(p[0x587]==1){GameState* state=(GameState*)_ZN9GameState11GetInstanceEv();GameObject* member=GameState_GetObjectWithFlag100(state,GameState_ReadFirstObjectIndex(state));TextLayout_ResetFormattingWorkspace((signed char*)owner);TextContext_SetStringArgument((Buffer*)owner,0,*(const char**)((char*)member+0x134));}
  *(int*)(owner+0x998)=1;
  // Lookup forwards the signed halfword index as an integer in r1.
  void* message=((void*(*)(void*,short))ResourceStringTable_GetTextByKey)(p+0x64,(short)(p[0x587]+0x438));Church_StartConfiguredMessage(p,message);++p[0x580];
 }
 if(phase==2&&*(int*)(owner+0x998)==0){p[0x588]=11;p[0x580]=0;}
}
