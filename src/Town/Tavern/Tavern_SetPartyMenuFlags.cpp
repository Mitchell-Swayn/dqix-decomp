struct ObjectFlagWord { unsigned char pad[0x464]; unsigned int flags; };
// Original: arm9/ov003 @ 0x02166164; symbol: func_ov003_02166164; size: 0x20
extern "C" void Tavern_SetPartyMenuFlags(ObjectFlagWord* object, int set, unsigned int mask)
{
    if (set)
        object->flags |= mask;
    else
        object->flags &= ~mask;
}
