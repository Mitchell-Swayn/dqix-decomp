#include <globaldefs.h>
ARM
// Original: arm9/ov009 @ 0x02186AEC; symbol: Graphics_AdvanceSelectionPhaseAndApplyChoice; size: 0x114.
// Advances the interaction phase after initializing selection state, then routes
// completed selections to one of the configured phase transitions.
extern "C" void ConfigureGridSelectionForCurrentMode(unsigned char* self);
extern "C" void CharacterCreation_LoadPhaseChoiceGridLayout(unsigned char* self);
extern "C" void CharacterCreation_PositionChoiceCursor(unsigned char* self, int value);
extern "C" int CharacterCreation_ProcessChoiceAndPhaseNavigation(void);
extern "C" void CharacterCreation_EnterPhaseAndMarkScreenDirty(void* state, int phase);
extern "C" void ApplyChoiceToPairedObjectSettings(unsigned char* self, int value);
extern "C" void Graphics_AdvanceSelectionPhaseAndApplyChoice(unsigned char* self) {
    unsigned char *p = self;
    unsigned int step = p[0xc59];
    if (step == 0) {
        ConfigureGridSelectionForCurrentMode(p);
        CharacterCreation_LoadPhaseChoiceGridLayout(p);
        CharacterCreation_PositionChoiceCursor(p, *(p + p[0xda3] + 0xdaa));
        *(unsigned int *)(p + 0xd9c) |= 1;
        p[0xc59]++;
        return;
    }
    if (step == 1) {
        if (*(unsigned int *)(p + 0xd9c) & 0x80) return;
        ApplyChoiceToPairedObjectSettings(p, *(p + p[0xda3] + 0xdaa));
        p[0xc59]++;
        return;
    }
    if (step != 2) return;
    int result = CharacterCreation_ProcessChoiceAndPhaseNavigation();
    if (result == -2) { CharacterCreation_EnterPhaseAndMarkScreenDirty(p, 7); return; }
    if (result == -3) { CharacterCreation_EnterPhaseAndMarkScreenDirty(p, 5); return; }
    if (result < 0x65 || result > 0x6c) return;
    int option = result - 0x64;
    if (option > *(signed char *)(p + p[0xda3] + 0xda0)) return;
    if (option == *(signed char *)(p + 0xc58)) return;
    CharacterCreation_EnterPhaseAndMarkScreenDirty(p, option & 0xff);
}
