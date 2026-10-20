#include <globaldefs.h>
#pragma auto_inline on
#pragma always_inline on
ARM
struct PartyJoinRecord {
    unsigned char member;
    unsigned char kind;
    unsigned char name[12];
    unsigned char flags;
};
#pragma force_active on
// Original: arm9/ov017 @ 0x02195214; symbol: func_ov017_02195214; size: 0x3C.
// Copies the member, kind, twelve name bytes and flags of a packed join record.
extern "C" void Field_CopyPartyJoinRecord(void* destination, const void* source)
{
    *(PartyJoinRecord*)destination = *(const PartyJoinRecord*)source;
}
