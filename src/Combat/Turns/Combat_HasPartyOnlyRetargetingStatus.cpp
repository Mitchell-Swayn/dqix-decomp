extern "C"
{
    struct Record
    {
        char pad[0x14];
        unsigned flags;
    };
    struct Object
    {
        char pad[0x138];
        Record *record;
    };
}
// Layout projections describe observed offsets; higher-level ownership is unresolved.
// Original: arm9/ov000 @ 0x021543F4; symbol: func_ov000_021543f4; size: 0x18.
extern "C" bool Combat_HasPartyOnlyRetargetingStatus(Object *p)
{
    return (p->record->flags & 0x20)!=0;
}
