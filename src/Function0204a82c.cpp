// Clears the leading scalar and five trailing byte/halfword fields in a record.
extern "C" void func_0204a82c(unsigned int* record)
{
    unsigned char* bytes = reinterpret_cast<unsigned char*>(record);
    record[0] = 0;
    *reinterpret_cast<unsigned short*>(bytes + 4) = 0;
    *reinterpret_cast<unsigned short*>(bytes + 6) = 0;
    *reinterpret_cast<unsigned short*>(bytes + 8) = 0;
    bytes[0x0a] = 0;
}
