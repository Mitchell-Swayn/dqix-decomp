#include <globaldefs.h>
#pragma opt_common_subs off
struct Stack { int* volatile items; unsigned char count; unsigned char capacity; };
// Original: arm9/main @ 0x0209CCC8; symbol: func_0209ccc8; size: 0x24.
extern "C" ARM void Bgm_AppendPackedZoneOverride(Stack* s, const int* value)
{
    unsigned char n = s->count;
    if (n < s->capacity)
    {
        s->count = n + 1;
        int* items = s->items;
        int entry = *value;
        items[n] = entry;
    }
}
