extern "C" int func_020d2ff0(const char* str);
extern "C" int sprintf(char* buffer, const char* format, ...);
extern "C" const char data_020efeb3[];

extern "C" int func_02041b70(char* base, int value2, int value3)
{
    char* destination = base + func_020d2ff0(base);
    int formattedLength = sprintf(destination, data_020efeb3, value2, value3);
    return destination + formattedLength - base;
}
