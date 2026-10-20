#include <globaldefs.h>
ARM
struct UpdateState { char unknown0[0xc58]; signed char phase; char unknown1[0x143]; unsigned flags; };
extern "C" void CharacterCreation_InstallLoadedPhaseBackgrounds(UpdateState*);
extern "C" void Window_ResetResourceTransfers(void*),Graphics_TransferScreenBuffer(void*,int);
extern "C" void CharacterCreation_RefreshAppearanceSummary(void*),RefreshFlaggedDescriptionRecord(void*),Text_RebuildSelectedEightGlyphCanvas(void*),CharacterCreation_RefreshConfirmationChoices(void*);
// Original: arm9/ov009 @ 0x02184CA4; symbol: func_ov009_02184ca4; size: 0xCC.
extern "C" void CharacterCreation_RefreshScreenTransfersAndText(UpdateState* state) {
 CharacterCreation_InstallLoadedPhaseBackgrounds(state);signed char phase=state->phase;
 if(phase==0 || phase==12) return;if(state->flags&0x80) return;
 Window_ResetResourceTransfers((char*)state+0x1f8);Window_ResetResourceTransfers((char*)state+0x2b4);
 if(state->flags&0x1000) {Graphics_TransferScreenBuffer((char*)state+0x158,0);state->flags&=~0x1000;}
 if(state->flags&0x2000) {Graphics_TransferScreenBuffer((char*)state+0x1b8,0);if((unsigned char)(signed char)(phase-8)<=1)Graphics_TransferScreenBuffer((char*)state+0x198,0);state->flags&=~0x2000;}
 CharacterCreation_RefreshAppearanceSummary(state);RefreshFlaggedDescriptionRecord(state);Text_RebuildSelectedEightGlyphCanvas(state);CharacterCreation_RefreshConfirmationChoices(state);
}
