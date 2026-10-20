#include <globaldefs.h>
ARM
struct BestiaryDetail;
extern "C" void BestiaryDetail_BeginMonsterLoad(BestiaryDetail*, void*, unsigned*, unsigned char);
// Original: arm9/ov014 @ 0x02184DCC; symbol: func_ov014_02184dcc; size: 0x70.
// Reloads the selected unlocked monster, toggles the two trivia pages, and marks detail refresh pending.
extern "C" void BestiaryDetail_ToggleTriviaPage(BestiaryDetail* self) {
    unsigned char* p = (unsigned char*)self;
    if (p[0x81] & 1) return;
    if (p[0x81] & 8) return;
    unsigned* record = *(unsigned**)(p+0x50);
    if (!record) return;
    if (!((*record << 21) >> 31)) return;
    unsigned char page = p[0x80];
    BestiaryDetail_BeginMonsterLoad(self, *(void**)(p+0x48), record, 0);
    p[0x80] = (unsigned char)(page + 1);
    p[0x80] &= 1;
    p[0x92] = 1;
    p[0x81] |= 8;
}
