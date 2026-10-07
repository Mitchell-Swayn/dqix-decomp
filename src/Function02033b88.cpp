extern "C" void func_02033ce8(unsigned char* object, unsigned char value);

extern "C" void func_02033b88(unsigned char* object, unsigned char value)
{
    object[0xbf] = object[0xbe];
    object[0xbe] = value;
    func_02033ce8(object, value);
}
