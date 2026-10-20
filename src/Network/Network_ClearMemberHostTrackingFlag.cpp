extern "C" int Network_IsClientSession(void*);
extern "C" unsigned int Network_FindWirelessSlotByMemberId(void*, unsigned int);
// Original: arm9/main @ 0x0202C69C; symbol: func_0202c69c; size: 0x40.
extern "C" void Network_ClearMemberHostTrackingFlag(unsigned char* object, unsigned int value)
{
    if (Network_IsClientSession(object) != 0) {
        return;
    }
    int bit = (int)Network_FindWirelessSlotByMemberId(object, value);
    unsigned char* entry = object + 0x100f;
    *entry = *entry & ~(1 << bit);
}
