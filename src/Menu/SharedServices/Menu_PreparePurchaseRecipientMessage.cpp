#include <globaldefs.h>
#include <GameState/GameState.h>
ARM

struct State;
struct ZoneState2754;
struct Record;
struct Nibble {
    unsigned low : 4;
    unsigned rest : 28;
};
struct Bit18 {
    unsigned pad : 18;
    unsigned flag : 1;
    unsigned rest : 13;
};
struct EntryBits {
    unsigned limit : 7;
    unsigned cost : 25;
};
struct OffsetTable {
    unsigned values[9];
};

extern "C" {
unsigned int TextContext_GetSharedInstance();
void TextLayout_ResetFormattingWorkspace(signed char* object);
int Menu_GetInventoryRecordSourceByKey(...);
int GetTypeSevenRowMajorIndex(void* self, unsigned key);
void* Menu_GetInventorySlotOnCurrentPage(void* self, unsigned column);
void* ZoneState2754_FindPrimaryRecordByKey(ZoneState2754* state, int key);
void GameState_BuildTwelveByteDescriptorForPartyMember(void* out, int index);
void* Text_LookupStandardString(unsigned key);
void Text_InitializeNameDescriptor(Record* p, unsigned x, unsigned y, unsigned a,
    unsigned char b, unsigned char c, unsigned char d, unsigned char e,
    unsigned char f, unsigned char g, unsigned char h, unsigned char i);
void* Text_LookupNameTableEntry(void* p, int id);
int GameObject_GetLinkedStatOrInvalid(char* p, int i);
void TextContext_SetNumericArgument(unsigned int* p, int i, unsigned int v);
// Original data: arm9/ov004 @ 0x21707d8; symbol: MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage.
extern char MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov004 @ 0x216fbb0; symbol: MenuPreparePurchaseRecipientMessage_UnknownRoleInitializedBytes.
extern unsigned MenuPreparePurchaseRecipientMessage_UnknownRoleInitializedBytes[];
}

#define P(p, o) (*(char**)((char*)(p) + (o)))
#define B(p, o) (*(unsigned char*)((char*)(p) + (o)))
#define S(p, o) (*(short*)((char*)(p) + (o)))
#define W(p, o) (*(unsigned*)((char*)(p) + (o)))
#define SB(p, o) (*(signed char*)((char*)(p) + (o)))

// Original: arm9/ov004 @ 0x02159650; symbol: func_ov004_02159650; size: 0x238.
// Builds the purchase-recipient name descriptors and numeric cost/quantity
// arguments for the selected offer.
extern "C" int Menu_PreparePurchaseRecipientMessage(void* self)
{
    unsigned int ctx = TextContext_GetSharedInstance();
    TextLayout_ResetFormattingWorkspace((signed char*)ctx);

    void* source = (void*)Menu_GetInventoryRecordSourceByKey(self, 5);
    char* record = 0;
    char* entry = 0;
    int index = GetTypeSevenRowMajorIndex(self, 0x5b);
    if (index >= 0) {
        entry = (char*)Menu_GetInventorySlotOnCurrentPage(self, (unsigned char)index);
        if (entry && source)
            record = (char*)ZoneState2754_FindPrimaryRecordByKey((ZoneState2754*)source, S(entry, 0));
    }

    signed char memberIndex = SB(P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage, 8), 0x12);
    char* member = (char*)GameState::GetInstance()->GetPartyMemberByIndex(memberIndex);
    if (member) {
        GameState_BuildTwelveByteDescriptorForPartyMember(
            P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage, 8) + 0xa0, memberIndex);
        *(void**)(ctx + 0x10) = P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage, 8) + 0xa0;
        int title = *(int*)(*(char**)(member + 0x150) + 0x950);
        title = title << 16 >> 16;
        void* text = Text_LookupStandardString(title);
        Text_InitializeNameDescriptor(
            (Record*)(P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage, 8) + 0xac),
            (unsigned)text, (unsigned)text, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        *(void**)(ctx + 0x28) = P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage, 8) + 0xac;
    }

    if (record)
        *(void**)(ctx + 0x18) = Text_LookupNameTableEntry(
            P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage, 8) + 0x8c, S(record, 0x18));

    if (member && record && W(record, 0)) {
        unsigned kind = ((Nibble*)(record + 8))->low;
        unsigned inRange;
        if (kind <= 7)
            inRange = 1;
        else
            inRange = 0;
        if (inRange) {
            OffsetTable table = *(OffsetTable*)MenuPreparePurchaseRecipientMessage_UnknownRoleInitializedBytes;
            int stat = GameObject_GetLinkedStatOrInvalid(member, table.values[kind]);
            if (stat > 0) {
                char* equipped = (char*)ZoneState2754_FindPrimaryRecordByKey((ZoneState2754*)source, stat);
                if (equipped && ((Bit18*)(equipped + 8))->flag)
                    *(void**)(ctx + 0x18) = Text_LookupNameTableEntry(
                        P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage, 8) + 0x8c, stat);
            }
        }
    }

    if (entry) {
        unsigned cost = ((EntryBits*)(entry + 4))->cost;
        unsigned quantity = B(P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage, 8), 0x11);
        TextContext_SetNumericArgument((unsigned int*)ctx, 0, quantity * cost);
    }
    TextContext_SetNumericArgument(
        (unsigned int*)ctx, 1, B(P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage, 8), 0x11));
    return 0;
}
