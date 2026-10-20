#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState21GetPartyMemberByIndexEi(void*, int);
// Original: arm9/ov017 @ 0x021D25B8; symbol: func_ov017_021d25b8; size: 0x3C.
extern "C" void GameState_SetPartyMemberFlagFromRecord(void *unused, unsigned char *record, void *game) {
    void *member = _ZN9GameState21GetPartyMemberByIndexEi(game, record[4]);
    if (!member) return;
    unsigned int *flags = (unsigned int *)((char *)member + 0x18c);
    if (*(unsigned int *)(record + 8)) *flags |= 8;
    else *flags &= ~8;
}
