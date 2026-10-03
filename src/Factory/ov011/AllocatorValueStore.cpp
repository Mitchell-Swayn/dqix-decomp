// Store the 32-bit value in the allocator record's field at offset 0x10c.
extern "C" void func_ov011_021848a0(void* receiver, unsigned int value)
{
    *(unsigned int*)((unsigned char*)receiver + 0x10c) = value;
}
