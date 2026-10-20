#include <globaldefs.h>
ARM
#pragma force_active on
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* GameState_GetIndexList(void*);
extern "C" void* GameState_GetValidObjectByIndex(void*,int);
extern "C" unsigned char* ZoneState2754_FindPrimaryRecordByKey(void*,int);
extern "C" int Equipment_GetPartyRestrictionMask(int,void*);
struct PartyValuePairRecord {
 int partyIndex; unsigned state; void* currentValues[12];
 unsigned char flag, padding[3]; unsigned short halfwordPairs0[4];
 unsigned wordPairs[8]; unsigned short halfwordPairs1[12];
};
extern "C" void Party_InitializeTwelveValuePairRecord(PartyValuePairRecord*);
extern "C" void Party_BuildStatComparison(unsigned char*,int,int,unsigned char);
extern "C" void Party_ReadStatComparisonPair(const char*,unsigned,void*,void*);
// Original data: arm9/ov003 @ 0x0217FAC8; symbol: data_ov003_0217fac8.
// Initialized bytes: 00 00 03 01 06 04 07 08 09 0a 0b 00.
// Maps the four-bit item selector to a stat comparison field; full span is documented in docs/data-symbols/ov003.md.
extern "C" const unsigned char ShopReadEquipmentStatComparison_UnknownRoleInitializedBytes[];
// Original: arm9/ov003 @ 0x021753A0; symbol: func_ov003_021753a0; size: 0xBC.
// Builds a member's selected-item stat comparison and returns whether the mapped stat is outside fields 3 and 4.
extern "C" bool Shop_ReadEquipmentStatComparison(char* self,int member,void* first,void* second)
{
    bool result = true;
    if (!GameState_GetValidObjectByIndex(_ZN9GameState11GetInstanceEv(), member)) {
        return true;
    }
    unsigned char* item = ZoneState2754_FindPrimaryRecordByKey(
        self + 0x874, *(short*)(self + 0x103a));
    if (!item) {
        return true;
    }
    Equipment_GetPartyRestrictionMask(member, item);
    PartyValuePairRecord comparison;
    Party_InitializeTwelveValuePairRecord(&comparison);
    Party_BuildStatComparison((unsigned char*)&comparison, member, (int)item, 0);
    unsigned selector = (*(unsigned*)(item + 12) << 21) >> 28;
    unsigned field = ShopReadEquipmentStatComparison_UnknownRoleInitializedBytes[selector];
    Party_ReadStatComparisonPair((char*)&comparison, field, first, second);
    switch (field) {
    case 3:
    case 4:
        result = false;
        break;
    }
    return result;
}
