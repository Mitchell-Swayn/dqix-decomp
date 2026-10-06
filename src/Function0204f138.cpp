// Initialize four pointers into a 0x24-byte-stride record.
extern "C" void func_0204f138(void* record, unsigned int* first,
                              unsigned int* second, unsigned int* third,
                              unsigned int* fourth)
{
    unsigned char* bytes = static_cast<unsigned char*>(record);
    *first = reinterpret_cast<unsigned int>(bytes + 0x0c);
    *second = reinterpret_cast<unsigned int>(bytes + 0x30);
    *third = reinterpret_cast<unsigned int>(bytes + 0x54);
    *fourth = reinterpret_cast<unsigned int>(bytes + 0x78);
}
