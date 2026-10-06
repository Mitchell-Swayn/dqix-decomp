extern "C" int func_020d2ff0(const char* str)
{
    int length = 0;

    if (*str != '\0') {
        do {
            ++length;
        } while (str[length] != '\0');
    }

    return length;
}
