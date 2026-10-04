#pragma optimize_for_size off

// Stream callbacks retain the existing single-character semihosting helpers.
extern "C" int func_0200d8a8();
extern "C" void func_0200d894(const char*);
extern "C" int func_0200d8cc(unsigned int handle, char* buffer, unsigned int* count, void* context)
{
    unsigned int i = 0;
    unsigned int limit = *count;
    if (i < limit) do {
        int character = func_0200d8a8();
        buffer[i] = character;
        if ((unsigned char)character == '\r' || (unsigned char)character == '\n') {
            *count = i + 1;
            break;
        }
    } while (++i < limit);
    return 0;
}
extern "C" int func_0200d91c(unsigned int handle, char* buffer, unsigned int* count, void* context)
{
    unsigned int i = 0;
    unsigned int limit = *count;
    if (i < limit) do {
        func_0200d894(buffer + i);
    } while (++i < limit);
    return 0;
}
extern "C" int func_0200d950(unsigned int handle)
{
    return 0;
}
