#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* _ZN9GameState15GetGrottoStructEv(void*);
// Original: arm9/ov017 @ 0x021CFCB4; symbol: func_ov017_021cfcb4; size: 0x38.
extern "C" void Grotto_UpdateFlagsFromEntryKind(void *unused, unsigned char *entry) {
    char *grotto = _ZN9GameState15GetGrottoStructEv(_ZN9GameState11GetInstanceEv());
    grotto[3] = entry[4] != 0;
    if (entry[4] != 0) grotto[4] = 0;
}
