#include <globaldefs.h>
ARM
struct GameState;struct GameResources;struct PhaseState;
extern "C" {
void* _ZN9GameState11GetInstanceEv();GameResources* GameState_ReadPResources(GameState*);
void _Z13SetBrightnessP13GameResourcesii(void*,int,int);int _Z28IsBrightnessTransitionActiveP13GameResources(void*);
int GameResources_GetSelectedScreenBrightness(char*,int);void ConfigureGridSelectionForCurrentMode(unsigned char*);
void CharacterCreation_LoadPhaseChoiceGridLayout(void*);void CharacterCreation_PositionChoiceCursor(void*,int);void ApplyChoiceToPairedObjectSettings(unsigned char*,int);int CharacterCreation_ProcessChoiceAndPhaseNavigation(void*);void CharacterCreation_EnterPhaseAndMarkScreenDirty(PhaseState*,int);
void CharacterPreview_InvalidateComponentId(char*,unsigned);
}
// Original: arm9/ov009 @ 0x021863D0; symbol: func_ov009_021863d0; size: 0x20C.
// Stages choice selection through brightness readiness and paired-object synchronization.
extern "C" void AdvanceBrightnessGatedChoicePhase(unsigned char* p) {
 GameState* game=(GameState*)_ZN9GameState11GetInstanceEv();
 GameResources* resources=GameState_ReadPResources(game);
 if(p[0xc59]==0) {
  if(GameResources_GetSelectedScreenBrightness((char*)resources,0)==-16 && GameResources_GetSelectedScreenBrightness((char*)resources,1)==-16) {
   if(*(unsigned*)(p+0xd9c)&0x80)return;
   _Z13SetBrightnessP13GameResourcesii(resources,0,15);
  }
  ConfigureGridSelectionForCurrentMode(p);CharacterCreation_LoadPhaseChoiceGridLayout(p);CharacterCreation_PositionChoiceCursor(p,p[0xda3]);++p[0xc59];
 }
 if(p[0xc59]==1) {
  if(_Z28IsBrightnessTransitionActiveP13GameResources(resources))return;
  *(unsigned*)(p+0xd9c)|=1;++p[0xc59];
 }else if(p[0xc59]==2) {
  if(*(unsigned*)(p+0xd9c)&0x80)return;
  ApplyChoiceToPairedObjectSettings(p,p[0xda3]);++p[0xc59];
 }else if(p[0xc59]==3) {
  int selected=CharacterCreation_ProcessChoiceAndPhaseNavigation(p);
  if(selected!=*(signed char*)(p+0xc58)) {
   char* target=*(char**)(p+0x7fc);
   if(!*(unsigned char*)(target+0xc12)) {
    CharacterPreview_InvalidateComponentId(target,0);CharacterPreview_InvalidateComponentId(target,2);CharacterPreview_InvalidateComponentId(target,3);CharacterPreview_InvalidateComponentId(target,4);
   }
  }
  if(selected==-2)CharacterCreation_EnterPhaseAndMarkScreenDirty((PhaseState*)p,2);
  else if(selected==-3) {
   if(p[0xd95]==1)*(unsigned*)(p+0xd9c)&=~0x400;
   else if(p[0xd95]==0)*((unsigned char*)game+0x63d4)=0;
   CharacterCreation_EnterPhaseAndMarkScreenDirty((PhaseState*)p,11);
  }else if(selected>=0x65 && selected<=0x6c) {
   int phase=selected-0x64;
   if(phase<=*(signed char*)(p+0xda0+p[0xda3]) && phase!=*(signed char*)(p+0xc58))CharacterCreation_EnterPhaseAndMarkScreenDirty((PhaseState*)p,(unsigned char)phase);
  }
 }
}
