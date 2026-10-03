struct Struct_02087a20
{
    unsigned char pad00[0x14];
    unsigned int flags14;
    unsigned char pad18[0x40];
    unsigned int flags58;
    unsigned char pad5c[0x14];
    unsigned char flag70;
    unsigned char pad71[0x22];
    unsigned char flag93;
};

extern "C" void func_02087a20(Struct_02087a20* object)
{
    object->flags14 &= ~0x1000;
    object->flags58 &= ~0x1c0;
    object->flag70 = 0;
    object->flag93 = 0;
}
