#pragma optimize_for_size off

extern "C" {

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
void func_02001b2c(void*, int, unsigned int);

void* memset(void* dest, int value, unsigned int count)
{
    func_02001b2c(dest, value, count);
    return dest;
}

// memchr: compare the low byte and return the first matching address.
void* func_02001ac0(const void* source, int value, unsigned int count)
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
int func_02001aec(const void* lhs, const void* rhs, unsigned int count)
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
