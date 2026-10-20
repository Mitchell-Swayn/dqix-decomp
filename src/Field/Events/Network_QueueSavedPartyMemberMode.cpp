#include <globaldefs.h>
ARM
extern "C" void* GameResources_GetInstance(void);
extern "C" void* _ZN9GameState11GetInstanceEv(void);
extern "C" void* _ZN9GameState21GetPartyMemberByIndexEi(void*, int);
extern "C" void* _ZN9GameState14GetProtagonistEv(void*);
extern "C" void Network_QueuePartyMemberOverlayToggle(unsigned, int);
// Original: arm9/ov017 @ 0x021C12B0; symbol: GameState_ApplyValueToSavedPartyMemberOrProtagonist; size: 0x4C.
// Resolves the saved party member or falls back to the protagonist, reads the low byte of halfword +4, and passes it with the input value to the ov017 helper.
extern "C" void Network_QueueSavedPartyMemberMode(int value) {
    char* resources = (char*)GameResources_GetInstance();
    short index = *(short*)(*(char**)(resources + 0x371C) + 0x22);
    void* game = _ZN9GameState11GetInstanceEv();
    void* member = _ZN9GameState21GetPartyMemberByIndexEi(game, index);
    if (member == 0) member = _ZN9GameState14GetProtagonistEv(game);
    unsigned id = (unsigned char)*(short*)((char*)member + 4);
    Network_QueuePartyMemberOverlayToggle(id, value);
}
