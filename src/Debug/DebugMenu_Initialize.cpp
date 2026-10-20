#include <globaldefs.h>
struct State {
    unsigned active; char unknown04[0x3c];
    unsigned value40,value44,value48,value4c;
    unsigned short a50,a52,a54,a56,a58,a5a;
    short a5c,a5e,a60;
    unsigned short a62,a64,a66,a68,a6a;
    unsigned char a6c,a6d,a6e,a6f,a70,a71,a72,a73,a74,unknown75[3];
    unsigned values[2];
};
extern "C" void DebugMenu_ClearEntry();
// Original data: arm9/main @ 0x20ef74c; symbol: data_020ef74c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 407d00000800000008000000ffffffff.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned short DebugMenuInitialize_UnknownRoleInitializedBytes;
// Original: arm9/main @ 0x02029568; symbol: func_02029568; size: 0xCC.
extern "C" ARM void DebugMenu_Initialize(State* state) {
    DebugMenu_ClearEntry();
    state->active = 1;
    state->a50 = 0; state->a52 = 0; state->a54 = 0; state->a56 = 0; state->a58 = 0;
    state->a6c = 1;
    state->a5a = 0;
    state->a5c = -1; state->a5e = -1; state->a60 = -1;
    state->a6d = 0; state->a6e = 0;
    state->value44 = 0; state->value48 = 0;
    state->a62 = 10; state->a64 = 0; state->a66 = state->a62 + state->a64;
    state->a6f = 0; state->a6a = 0; state->a68 = 0;
    DebugMenuInitialize_UnknownRoleInitializedBytes = 32064;
    state->a71 = 0; state->a72 = 0; state->a73 = 0; state->a74 = 0;
    state->value40 = 0; state->a70 = 0; state->value4c = 8;
    for (int i = 0; i < 2; ++i) state->values[i] = 0;
}
