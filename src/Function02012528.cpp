// The only known field is the byte stored at offset 0x1c.
struct Function02012528Object
{
    unsigned char unknown_000[0x1c];
    unsigned char value_01c;
};

extern "C" void func_02012528(Function02012528Object* object, unsigned char value)
{
    object->value_01c = value;
}
