#include <globaldefs.h>
ARM

extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" unsigned int GameState_TransferAvailableGrottoDescriptorAndTexts(void *, void *, char *, char *);
extern "C" void Menu_QueueScriptEntry(void *, unsigned int);
extern "C" unsigned int ReadGrottoInfoMetadataTransferUnknown(void *);

// Original: arm9/ov004 @ 0x021658B0; symbol: func_ov004_021658b0; size: 0x60.
extern "C" int Grotto_ProcessAvailableMetadataTransfer(void *self) {
    void *state = _ZN9GameState11GetInstanceEv();
    if (GameState_TransferAvailableGrottoDescriptorAndTexts(state, 0, 0, 0)) {
        Menu_QueueScriptEntry(self, 0x64);
        void *currentState = _ZN9GameState11GetInstanceEv();
        *((unsigned char *)currentState + 0x646e) = 1;
        ReadGrottoInfoMetadataTransferUnknown(state);
    } else {
        Menu_QueueScriptEntry(self, 0x65);
    }
    return 0;
}
