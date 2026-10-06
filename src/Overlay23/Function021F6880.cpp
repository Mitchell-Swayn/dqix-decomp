extern "C" unsigned short func_ov023_021f6f08(const void *value);

extern "C" void *func_ov023_021f6880(void **value, unsigned short target)
{
    void *current = *value;
    while (current != 0) {
        if (func_ov023_021f6f08(current) == target)
            return current;
        current = *(void **)((char *)current + 0x18);
    }
    return 0;
}
