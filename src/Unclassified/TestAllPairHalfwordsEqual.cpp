#include <globaldefs.h>
ARM
#pragma opt_common_subs off
#pragma opt_propagation off
struct Pair { unsigned short left, right; };
struct State { char pad[0x20]; int equal; unsigned char pad24; unsigned char count; unsigned short pad26; Pair* pairs; };
// Original: arm9/main @ 0x0202811C; symbol: func_0202811c; size: 0x54.
extern "C" void TestAllPairHalfwordsEqual(State* self) {
    self->equal = 1;
    int index;
    Pair* pairs = self->pairs;
    if (pairs == 0) return;
    index = 0;
    while (index < self->count) {
        Pair* pair = pairs + index;
        unsigned short left = pairs[index].left;
        unsigned short right = pair->right;
        if (left != right) { self->equal = 0; return; }
        ++index;
    }
}
