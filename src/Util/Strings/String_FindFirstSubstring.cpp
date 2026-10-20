#include <globaldefs.h>
// Original: arm9/main @ 0x020D2F88; symbol: func_020d2f88; size: 0x68.
// Finds the first matching substring; an empty haystack returns null.
extern "C" char* String_FindFirstSubstring(char* text, const char* pattern)
{
    int index;
    char* cursor;
    char value;
    int start = 0;
    if (*text) do {
        cursor = text + start;
        index = 0;
        while ((value = pattern[index]) && *cursor == value) {
            ++cursor;
            ++index;
        }
        if (!value) return text + start;
        ++start;
    } while (text[start]);
    return 0;
}
