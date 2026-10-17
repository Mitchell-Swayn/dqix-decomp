#pragma optimize_for_size off

extern "C" {

// Original: arm9/main @ 0x02001A40; symbol: memcpy; size: 0x20.
void* memcpy(void* dest, const void* source, unsigned int count)
{
    char* d = (char*)dest;
    const char* s = (const char*)source;
    if (count) {
        do {
            *d++ = *s++;
        } while (--count);
    }
    return dest;
}

// Original: arm9/main @ 0x02001A60; symbol: memmove; size: 0x4C.
void* memmove(void* dest, const void* source, unsigned int count)
{
    const char* s = (const char*)source;
    if (s >= (char*)dest) {
        char* d = (char*)dest;
        if (count) {
            do {
                *d++ = *s++;
            } while (--count);
        }
    } else {
        const char* end = s + count;
        char* d = (char*)dest + count;
        if (count) {
            do {
                *--d = *--end;
            } while (--count);
        }
    }
    return dest;
}

// The optimized fill implementation remains a separate runtime dependency.
void Runtime_FillMemoryBytes(void*, int, unsigned int);

// Original: arm9/main @ 0x02001AAC; symbol: memset; size: 0x14.
void* memset(void* dest, int value, unsigned int count)
{
    Runtime_FillMemoryBytes(dest, value, count);
    return dest;
}

// memchr: compare the low byte and return the first matching address.
// Original: arm9/main @ 0x02001AC0; symbol: func_02001ac0; size: 0x2C.
void* Runtime_FindByteInMemory(const void* source, int value, unsigned int count)
{
    const unsigned char* s = (const unsigned char*)source;
    unsigned char byte = value;
    if (count) {
        do {
            if (*s++ == byte)
                return (void*)(s - 1);
        } while (--count);
    }
    return 0;
}

// memcmp returns -1 or 1 for unequal bytes, rather than their difference.
// Original: arm9/main @ 0x02001AEC; symbol: func_02001aec; size: 0x40.
int RuntimeMemory_CompareByteRanges(const void* lhs, const void* rhs, unsigned int count)
{
    const unsigned char* a = (const unsigned char*)lhs;
    const unsigned char* b = (const unsigned char*)rhs;
    if (count) {
        do {
            if (*a++ != *b++)
                return a[-1] < b[-1] ? -1 : 1;
        } while (--count);
    }
    return 0;
}

}
