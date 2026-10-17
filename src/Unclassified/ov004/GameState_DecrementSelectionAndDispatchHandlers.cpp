#include <globaldefs.h>
ARM
extern "C" char data_ov004_021707d8;
extern "C" void *FindType15EntryForState(void *self, unsigned key);
extern "C" void *Unclassified_FindTypeSixObject(void *self, unsigned id);
extern "C" void func_ov023_021f809c(void *entry, void *state);
// Original: arm9/ov004 @ 0x0215B0A8; symbol: func_ov004_0215b0a8; size: 0x78.
extern "C" int GameState_DecrementSelectionAndDispatchHandlers(void *self) {
    char *state = *(char **)(&data_ov004_021707d8 + 8);
    unsigned char selection = (unsigned char)state[0x6e];
    if (selection > 1) {
        state[0x6e] = selection - 1;
        void *entry = FindType15EntryForState(self, 0x25a);
        if (entry) {
            void *object = *(void **)entry;
            void (*callback)(void *, unsigned) = *(void (**)(void *, unsigned))((char *)object + 0xe0);
            (*callback)(entry, (unsigned char)(*(char **)(&data_ov004_021707d8 + 8))[0x6e]);
        }
        void *found = Unclassified_FindTypeSixObject(self, 0x19);
        if (found) func_ov023_021f809c(found, self);
    }
    return 0;
}
