extern "C" int func_020d2ff0(const char* str);
extern "C" int sprintf(char* destination, const char* format, ...);
extern "C" const char data_020eff87[];

extern "C" int func_02041ea4(char* destination, const char* source)
{
    int destinationLength = func_020d2ff0(destination);
    char* appendPosition = destination + destinationLength;

    int appendedLength = sprintf(appendPosition, data_020eff87, source);
    return destination + destinationLength + appendedLength - destination;
}
