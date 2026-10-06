extern "C" void* func_ov003_0215e824(void* object, int value)
{
    unsigned char* entry = *(unsigned char**)object;
    int count = *(short*)((unsigned char*)object + 6);

    for (int i = 0; i < count; ++i, entry += 0x14) {
        if (*(short*)(entry + 0x10) == value)
            return entry;
    }

    return 0;
}
