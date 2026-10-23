#include <globaldefs.h>
ARM

// This packet layout is shared with Combat_ApplyRemoteMemberActionSelection.
struct Selection {
    unsigned char a, b, c, d;
    signed char e;
    unsigned char pad;
    short action;
    unsigned short target;
};

extern "C" void* BattleMenu_GetEnemyTargetObjectId(void*, int);
extern "C" void BattleMenu_ApplyMemberCommandSelection(
    char*, int, int, signed char, signed char, short, signed char, unsigned short);

// Original: arm9/ov000 @ 0x02162aac; symbol: func_ov000_02162aac; size: 0xc4.
// Applies a received party selection when the scene's synchronization flags allow it.
extern "C" void BattleHud_ApplyRemotePartySelection(
    unsigned char* self, unsigned member, Selection* selection)
{
    unsigned flags = *(unsigned*)(self + 0x55f4);
    if (!(flags & 0x10000) || (flags & 0x800000)) return;

    unsigned char* context = *(unsigned char**)(self + 0x29c);
    if (!*(int*)(context + 0x8e20) && context[0x8e49] == 2) return;

    int target = -1;
    for (int i = 0; i < 12; ++i) {
        // Preserve the existing helper's 32-bit result and out-of-range mapping.
        if (selection->d == (unsigned)BattleMenu_GetEnemyTargetObjectId(self + 0x3760, i)) {
            target = i;
            break;
        }
    }
    BattleMenu_ApplyMemberCommandSelection(
        (char*)self + 0x3760, member, (signed char)selection->a,
        (signed char)selection->b, (signed char)target, selection->action,
        selection->e, selection->target);
}
