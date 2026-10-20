#include <globaldefs.h>
ARM
struct ChoiceSettings {
 unsigned char pad[4]; unsigned short choice5,choice3; unsigned char rest[12];
 unsigned char flag:1; unsigned char mode6:3; unsigned char mode7:4;
 unsigned char mode4:4; unsigned char unused:4;
 short unused16,x,y;
};
extern "C" {
void CharacterPreview_InvalidateComponentId(char*,unsigned);
void CharacterCreation_ReadBodyScalePreset(void*,int,short*,short*);
void CharacterPreview_ApplyBodyProportions(void*,int,int);
int CharacterCreation_MapGenderDependentAppearanceChoice(unsigned char*,int,int);
void CharacterPreview_StageAppearancePalettes(void*);
}
// Original: arm9/ov009 @ 0x02188944; symbol: func_ov009_02188944; size: 0x1D0.
// Applies a mode-dependent choice to shared settings and invalidates affected paired-object records.
extern "C" void ApplyChoiceToPairedObjectSettings(unsigned char* p,int choice) {
 ChoiceSettings* settings=(ChoiceSettings*)(*(char**)(p+0xd88)+0x488);
 int mode=*(signed char*)(p+0xc58);
 char* target=*(char**)(p+0x7fc);
 char* source=*(char**)(p+0x7f8);
 if(mode==1) {
  settings->flag=(unsigned char)choice;
  CharacterPreview_InvalidateComponentId(target,0);CharacterPreview_InvalidateComponentId(target,2);CharacterPreview_InvalidateComponentId(target,3);CharacterPreview_InvalidateComponentId(target,4);
  *(unsigned*)(p+0xd9c)|=2;
 }else if(mode==2) {
  CharacterCreation_ReadBodyScalePreset(p,choice,&settings->x,&settings->y);
  CharacterPreview_ApplyBodyProportions(source,settings->x,settings->y);
  CharacterPreview_ApplyBodyProportions(target,settings->x,settings->y);
 }else if(mode==5) {
  settings->choice5=CharacterCreation_MapGenderDependentAppearanceChoice(p,5,choice)+0x233c;
  CharacterPreview_InvalidateComponentId(target,2);
  *(unsigned*)(p+0xd9c)|=2;
 }else if(mode==3) {
  settings->choice3=CharacterCreation_MapGenderDependentAppearanceChoice(p,3,choice)+0x2328;
  CharacterPreview_InvalidateComponentId(target,3);CharacterPreview_InvalidateComponentId(target,4);
  *(unsigned*)(p+0xd9c)|=2;
 }else if(mode==4) {
  settings->mode4=(unsigned char)choice;
  CharacterPreview_InvalidateComponentId(target,4);
  *(unsigned*)(p+0xd9c)|=2;
 }else if(mode==6) {
  settings->mode6=(unsigned char)choice;
  CharacterPreview_StageAppearancePalettes(source);
 }else if(mode==7) {
  settings->mode7=(unsigned char)choice;
  CharacterPreview_StageAppearancePalettes(source);
 }
}
