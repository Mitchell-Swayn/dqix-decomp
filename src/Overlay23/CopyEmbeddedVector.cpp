struct EmbeddedVector
{
    unsigned int components[3];
};

extern "C" void func_ov023_021f7174(EmbeddedVector* destination, const void* source)
{
    *destination = *(const EmbeddedVector*)((const char*)source + 0x3c);
}
