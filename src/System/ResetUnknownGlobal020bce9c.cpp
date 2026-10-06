// Only the two accessed fields of this otherwise unknown global record are known.
struct UnknownGlobal020bce9c
{
    int unknown_00;
    unsigned char padding_04[0x44];
    int unknown_48;
};

extern UnknownGlobal020bce9c data_0210fd74;

extern "C" void func_020bce9c()
{
    data_0210fd74.unknown_00 = 0;
    data_0210fd74.unknown_48 = 0;
}
