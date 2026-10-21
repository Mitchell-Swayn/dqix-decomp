#include <globaldefs.h>
ARM

struct State;

extern "C" {
int StatusMenu_HasAvailablePartyMember(int unused, int key);
int StatusMenu_SelectNextPartyMember(...);
int StatusMenu_BuildLearnedAbilityAndTraitBanks(void* self);
void Menu_QueueScriptEntry(State* self, unsigned value);
void InvokeEntryHandlerForStateKey(void* self, unsigned key, unsigned value);
void SoundSfx_StartCurrentSequenceArchiveEntry(char* p, int a, void* b);
// Original data: arm9/ov004 @ 0x21707e8; symbol: StatusMenuSelectNextSubpage_UnknownRoleZeroInitializedStorage.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 44 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern char StatusMenuSelectNextSubpage_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov004 @ 0x2170b90; symbol: StatusMenuSelectNextPartyMember_UnknownRoleZeroInitializedStorage_Variant4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 576 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern char StatusMenuSelectNextPartyMember_UnknownRoleZeroInitializedStorage_Variant4[];
// Original data: arm9/main @ 0x2108760; symbol: Main_UnknownRoleZeroInitializedStorage.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern char Main_UnknownRoleZeroInitializedStorage[];
}

#define B(p, o) (*(unsigned char*)((char*)(p) + (o)))
#define VB(p, o) (*(volatile unsigned char*)((char*)(p) + (o)))
#define SB(p, o) (*(signed char*)((char*)(p) + (o)))
#define W(p, o) (*(int*)((char*)(p) + (o)))

// Original: arm9/ov004 @ 0x02162C30; symbol: func_ov004_02162c30; size: 0x148.
// Advances the status-menu page category: when a party member is available it
// queues the matching script for kind 0x64-0x68 and resets listing flags.
extern "C" int StatusMenu_SelectNextPageCategory(void* self)
{
    if (B(StatusMenuSelectNextSubpage_UnknownRoleZeroInitializedStorage, 0) == 1)
        return 0;
    if (!StatusMenu_HasAvailablePartyMember((int)self, W(StatusMenuSelectNextSubpage_UnknownRoleZeroInitializedStorage, 0x1c))) {
        StatusMenu_SelectNextPartyMember(self);
        return 0;
    }

    B(StatusMenuSelectNextSubpage_UnknownRoleZeroInitializedStorage, 0) = 1;
    unsigned page = B(StatusMenuSelectNextSubpage_UnknownRoleZeroInitializedStorage, 7) - 0x64;
    switch (page) {
    case 0:
        B(StatusMenuSelectNextSubpage_UnknownRoleZeroInitializedStorage, 6) =
            SB(StatusMenuSelectNextSubpage_UnknownRoleZeroInitializedStorage, 5);
        Menu_QueueScriptEntry((State*)self, 0x65);
        break;
    case 1:
        B(StatusMenuSelectNextSubpage_UnknownRoleZeroInitializedStorage, 6) =
            B(StatusMenuSelectNextPartyMember_UnknownRoleZeroInitializedStorage_Variant4, 0x23f);
        Menu_QueueScriptEntry((State*)self, 0x66);
        break;
    case 2:
        B(StatusMenuSelectNextSubpage_UnknownRoleZeroInitializedStorage, 6) =
            B(StatusMenuSelectNextPartyMember_UnknownRoleZeroInitializedStorage_Variant4, 0x47f);
        StatusMenu_BuildLearnedAbilityAndTraitBanks(self);
        Menu_QueueScriptEntry((State*)self, 0x67);
        break;
    case 3:
        B(StatusMenuSelectNextSubpage_UnknownRoleZeroInitializedStorage, 6) = 1;
        Menu_QueueScriptEntry((State*)self, 0x68);
        break;
    case 4:
        B(StatusMenuSelectNextSubpage_UnknownRoleZeroInitializedStorage, 6) =
            SB(StatusMenuSelectNextSubpage_UnknownRoleZeroInitializedStorage, 9);
        B(StatusMenuSelectNextSubpage_UnknownRoleZeroInitializedStorage, 8) =
            B(StatusMenuSelectNextSubpage_UnknownRoleZeroInitializedStorage, 3);
        Menu_QueueScriptEntry((State*)self, 0x64);
        break;
    }

    VB(StatusMenuSelectNextPartyMember_UnknownRoleZeroInitializedStorage_Variant4, 0x23c) = 0;
    VB(StatusMenuSelectNextPartyMember_UnknownRoleZeroInitializedStorage_Variant4, 0x47c) = 0;
    VB(StatusMenuSelectNextSubpage_UnknownRoleZeroInitializedStorage, 0xb) = 0;
    VB(StatusMenuSelectNextSubpage_UnknownRoleZeroInitializedStorage, 0) = 0;
    InvokeEntryHandlerForStateKey(self, 0x84, 1);
    SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage, 1, (void*)0);
    return 0;
}
