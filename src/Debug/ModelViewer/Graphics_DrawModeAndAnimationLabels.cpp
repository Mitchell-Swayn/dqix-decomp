#include <globaldefs.h>
ARM
extern "C" {
void Text_FormatAndSubmitBoundedString(unsigned,unsigned,const char*,...);
int UI_IsOwnerModeInResourceRange(unsigned char*);
extern char CharacterViewer_RebuildMenu_TextOperation[],Graphics_DrawModeAndAnimationLabels_TextSelectUD[],Graphics_DrawModeAndAnimationLabels_TextStepRRL[],Graphics_DrawModeAndAnimationLabels_TextNoLoopLA[],Graphics_DrawModeAndAnimationLabels_TextLoopLA[],Graphics_DrawModeAndAnimationLabels_TextPlayRA[],Graphics_DrawModeAndAnimationLabels_TextSceneR[],Graphics_DrawModeAndAnimationLabels_TextStopRA[],Graphics_DrawModeAndAnimationLabels_TextBattleR[],Graphics_DrawModeAndAnimationLabels_TextNoBattleR[],Graphics_DrawModeAndAnimationLabels_TextBattleL[],Graphics_DrawModeAndAnimationLabels_TextFieldL[];
}
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define W(p,o) (*(int*)((p)+(o)))
#define TEXT(y,s) Text_FormatAndSubmitBoundedString(0x91,y,s)
// Original: arm9/ov015 @ 0x02190ACC; symbol: func_ov015_02190acc; size: 0x160.
// Draws labels selected by owner mode, animation flags and a mode predicate.
extern "C" void Graphics_DrawModeAndAnimationLabels(unsigned char* self) {
 Text_FormatAndSubmitBoundedString(0x87,0xa,CharacterViewer_RebuildMenu_TextOperation);
 TEXT(0x18,Graphics_DrawModeAndAnimationLabels_TextSelectUD);
 if(W(self,0x194)==1) {
 TEXT(0x26,Graphics_DrawModeAndAnimationLabels_TextStepRRL);
 if(W(P(self,0x30),0x44)==0)TEXT(0x34,Graphics_DrawModeAndAnimationLabels_TextNoLoopLA);
 else TEXT(0x34,Graphics_DrawModeAndAnimationLabels_TextLoopLA);
 if(P(self,0x30)[0x3a]) {TEXT(0x42,Graphics_DrawModeAndAnimationLabels_TextPlayRA);TEXT(0x50,Graphics_DrawModeAndAnimationLabels_TextSceneR);}
 else TEXT(0x42,Graphics_DrawModeAndAnimationLabels_TextStopRA);
 }else {
 if(W(self,0x1a4)==0x22 || UI_IsOwnerModeInResourceRange(self)) {
 if(W(P(self,0x30),0x48)==0)TEXT(0x26,Graphics_DrawModeAndAnimationLabels_TextBattleR);
 else TEXT(0x26,Graphics_DrawModeAndAnimationLabels_TextNoBattleR);
 }
 if(W(self,0x1a4)==6) {
 if(self[0x1a1])TEXT(0x26,Graphics_DrawModeAndAnimationLabels_TextBattleL);
 else TEXT(0x26,Graphics_DrawModeAndAnimationLabels_TextFieldL);
 }
 }
}
