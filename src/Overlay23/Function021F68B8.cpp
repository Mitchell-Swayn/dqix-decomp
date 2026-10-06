extern "C" void *func_ov023_021f68b8(void **value, int depth)
{
    void *current = *value;
    while (current != 0 && depth > 0) {
        current = *(void **)((char *)current + 0x18);
        --depth;
    }
    return current;
}
