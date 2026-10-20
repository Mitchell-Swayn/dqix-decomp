#include <globaldefs.h>
ARM
// Original: arm9/ov003:02168cc8; Clears a nested state byte for status 3 and maps the adjusted helper result to owner mode 3, 4, or 5.
extern "C" unsigned int TextContext_GetSharedInstance(void*);
extern "C" int Bank_PollTransactionMenuSelection(void*);
extern "C" void Bank_ApplyTransactionMenuChoice(void* self) {
    unsigned char* state = (unsigned char*)TextContext_GetSharedInstance(self);
    if (*(unsigned int*)(state + 0x9a0) == 3) state[0x19ae] = 0;
    int value = Bank_PollTransactionMenuSelection(self) + 2;
    switch (value) {
    case 1: return;
    case 2: ((unsigned char*)self)[0x4ec] = 3; return;
    case 3: ((unsigned char*)self)[0x4ec] = 4; return;
    case 0:
    case 4: ((unsigned char*)self)[0x4ec] = 5; return;
    default: return;
    }
}
