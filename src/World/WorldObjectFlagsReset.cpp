struct WorldObjectFlagsResetLayout {
    unsigned char pad_00[0x14];
    unsigned int flags_14;
    unsigned char pad_18[0x40];
    unsigned int flags_58;
    unsigned char pad_5c[0x12];
    unsigned char flag_6e;
    unsigned char pad_6f[0x22];
    unsigned char flag_91;
};

extern "C" void func_02087838(WorldObjectFlagsResetLayout* object)
{
    object->flags_14 &= ~0x400;
    object->flags_58 &= ~7;
    object->flag_6e = 0;
    object->flag_91 = 0;
}
