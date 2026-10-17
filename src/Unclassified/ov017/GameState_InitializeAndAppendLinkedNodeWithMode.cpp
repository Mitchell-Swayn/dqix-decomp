#include <globaldefs.h>
ARM
extern "C" void func_ov017_021b6790(void *node);
extern "C" void AppendLinkedNodeAndMarkActive(unsigned *list, unsigned node);
// Original: arm9/ov017 @ 0x021B6728; symbol: func_ov017_021b6728; size: 0x68.
extern "C" void GameState_InitializeAndAppendLinkedNodeWithMode(void *state, int mode, unsigned char value) {
    unsigned char *bytes = (unsigned char *)state;
    func_ov017_021b6790(*(void **)(bytes + 0x3b00));
    AppendLinkedNodeAndMarkActive(*(unsigned **)(bytes + 0x36fc), (unsigned)*(void **)(bytes + 0x3b00));
    if (mode == 1) {
        unsigned char *node = *(unsigned char **)(bytes + 0x3b00);
        node[0x1f] = 4;
        (*(volatile unsigned char **)(bytes + 0x3b00))[0x20] = value;
    } else if (mode == 0) {
        unsigned char *node = *(unsigned char **)(bytes + 0x3b00);
        node[0x1f] = 3;
    }
}
