#pragma optimize_for_size off
extern "C" int func_02003c80(char*, unsigned int, const char*, void*);
extern "C" int sprintf(char* buffer, const char* format, ...)
{
    // MWCC ARM variadic arguments follow the last named parameter home slot.
    // The compiler saves r0-r3 contiguously with the stack arguments.
    char* args = (char*)(((unsigned int)&format) & ~3) + 4;
    return func_02003c80(buffer, -1, format, args);
}



