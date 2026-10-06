extern "C" int func_ov001_0215941c(const void *source, void *destination)
{
    const unsigned int value = *(const unsigned int *)((const unsigned char *)source + 0x10);
    *(unsigned int *)((unsigned char *)destination + 0x1dc) = value;
    return 0;
}
