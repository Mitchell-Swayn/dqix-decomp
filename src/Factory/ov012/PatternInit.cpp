#include "PatternState.h"

// Fixed-width strings passed to the game's character-code lookup. The final
// zero byte is the original alignment before the next overlay table.
struct PatternDelimiterTable {
    char text[15][5];
    char alignment;
};
extern "C" const PatternDelimiterTable data_ov012_0218afbc = {{
    ":", "[", "]", "{", "}", "^", "-", ".", "$", "/", "@", "&", ",", "<c/>", "'"
}, 0};

extern "C" void func_ov012_021845f8(PatternState* state)
{
    memset(&state->resource, 0, sizeof(PatternResource));
    state->selectedPattern = 0;
    state->selectedOffset = 0;
    unsigned char* output = state->delimiters;
    for (int i = 0; i < 15; ++i) {
        *output++ = func_020424e4(data_ov012_0218afbc.text[i], 1);
    }
}
