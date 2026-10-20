#include <globaldefs.h>
ARM
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define I(p,o) (*(int*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))

#define S(p,o) (*(signed char*)((char*)(p)+(o)))
extern "C" void ConfigureGridSelectionForCurrentMode(unsigned char*);extern "C" void CharacterCreation_LoadPhaseChoiceGridLayout(void*);extern "C" void CharacterCreation_PositionChoiceCursor(void*,int);extern "C" void ApplyChoiceToPairedObjectSettings(void*,int);extern "C" int CharacterCreation_ProcessChoiceAndPhaseNavigation(void*);extern "C" void CharacterCreation_EnterPhaseAndMarkScreenDirty(void*,int);
// Original: arm9/ov009 @ 0x021865DC; symbol: Graphics_AdvanceSelectionPhaseFromMode3492; size: 0x114.
extern "C" void CharacterCreation_UpdateBodyBuildSelection(char* self){if(B(self,0xc59)==0){ConfigureGridSelectionForCurrentMode((unsigned char*)self);CharacterCreation_LoadPhaseChoiceGridLayout(self);CharacterCreation_PositionChoiceCursor(self,B(self+B(self,0xda3),3492));W(self,0xd9c)|=1;B(self,0xc59)++;}else if(B(self,0xc59)==1){if(W(self,0xd9c)&128)return;ApplyChoiceToPairedObjectSettings(self,B(self+B(self,0xda3),3492));B(self,0xc59)++;}else if(B(self,0xc59)==2){int result=CharacterCreation_ProcessChoiceAndPhaseNavigation(self);if(result==-2){CharacterCreation_EnterPhaseAndMarkScreenDirty(self,3);return;}if(result==-3){CharacterCreation_EnterPhaseAndMarkScreenDirty(self,1);return;}if(result>=101&&result<=108){int phase=result-100;if(phase>S(self+B(self,0xda3),0xda0))return;if(phase==S(self,0xc58))return;CharacterCreation_EnterPhaseAndMarkScreenDirty(self,(unsigned char)phase);}}}
