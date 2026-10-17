#pragma optimize_for_size off
extern "C" int Runtime_FormatIntoBoundedString(char*, unsigned int, const char*, void*);
// Original: arm9/main @ 0x02003CE8; symbol: sprintf; size: 0x2C.
extern "C" int sprintf(char* buffer, const char* format, ...)
{
    // MWCC ARM variadic arguments follow the last named parameter home slot.
    // The compiler saves r0-r3 contiguously with the stack arguments.
    char* args = (char*)(((unsigned int)&format) & ~3) + 4;
    return Runtime_FormatIntoBoundedString(buffer, -1, format, args);
}



