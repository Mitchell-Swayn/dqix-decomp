#pragma once

// Overlay 11 uses eight-byte arguments, distinct from Script::Parameter.
// Numeric tags are 0 for integer and 1 for float. The local converter passes
// other tags through as raw words; pointer-valued handlers use tags 2 and 3.
struct Ov011ScriptArgument
{
    int type;
    union
    {
        int integer;
        float real;
        void* pointer;
    } value;
};

typedef char Ov011ScriptArgumentSizeCheck[sizeof(Ov011ScriptArgument) == 8 ? 1 : -1];

extern "C" {
    int func_ov011_02184c30(Ov011ScriptArgument* argument);
    float func_ov011_02184c4c(Ov011ScriptArgument* argument);
}
