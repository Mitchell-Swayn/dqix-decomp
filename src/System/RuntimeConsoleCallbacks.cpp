#pragma optimize_for_size off

// Stream callbacks retain the existing single-character semihosting helpers.
extern "C" int func_0200d8a8();
extern "C" void func_0200d894(const char*);
// Original: arm9/main @ 0x0200D8CC; symbol: func_0200d8cc; size: 0x50.
extern "C" int Runtime_ReadConsoleCharacters(unsigned int handle, char* buffer, unsigned int* count, void* context)
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
// Original: arm9/main @ 0x0200D91C; symbol: func_0200d91c; size: 0x34.
extern "C" int RuntimeConsoleCallbacks_WriteConsoleBuffer(unsigned int handle, char* buffer, unsigned int* count, void* context)
{
    unsigned int i = 0;
    unsigned int limit = *count;
    if (i < limit) do {
        func_0200d894(buffer + i);
    } while (++i < limit);
    return 0;
}
// Original: arm9/main @ 0x0200D950; symbol: func_0200d950; size: 0x8.
extern "C" int Runtime_ReturnZero(unsigned int handle)
{
    return 0;
}
