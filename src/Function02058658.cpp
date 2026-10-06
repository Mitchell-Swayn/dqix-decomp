// Return the record for one of the sixteen entries in the indexed record table.
extern "C" void* func_02058658(void* table, int index)
{
    int recordIndex = index - 0xd0;
    if (recordIndex < 0 || recordIndex >= 0x10)
        return 0;

    return static_cast<unsigned char*>(table) + 8 + recordIndex * 0xd4;
}
