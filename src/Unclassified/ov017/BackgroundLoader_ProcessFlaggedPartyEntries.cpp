#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" void *_ZN9GameState21GetPartyMemberByIndexEi(void *state, int index);
extern "C" void *ReadGlobalAt020FDD44(void);
extern "C" unsigned char *GetBoundedEntryAtStride318(void *table, int index);
extern "C" void *_ZN16BackgroundLoader11GetInstanceEv(void);
extern "C" void func_020733d8(void *entry, int value);
struct EntryFlags { unsigned short id; unsigned short low : 3; unsigned short skip : 1; unsigned short high : 12; };
// Original: arm9/ov017 @ 0x021A205C; symbol: func_ov017_021a205c; size: 0x64.
extern "C" void BackgroundLoader_ProcessFlaggedPartyEntries(void) {
    void *state = _ZN9GameState11GetInstanceEv();
    void *table = ReadGlobalAt020FDD44();
    _ZN16BackgroundLoader11GetInstanceEv();
    for (int i = 0; i < 4; ++i) {
        (void)_ZN9GameState21GetPartyMemberByIndexEi(state, i);
        unsigned char *entry = GetBoundedEntryAtStride318(table, i);
        if (((EntryFlags *)entry)->skip) func_020733d8(entry, 0);
    }
}
