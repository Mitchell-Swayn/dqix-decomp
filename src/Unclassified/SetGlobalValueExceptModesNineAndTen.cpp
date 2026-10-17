#include <globaldefs.h>
struct A{char pad[0x10];unsigned int mode;char pad2[0x34];unsigned int value;};extern "C" {extern A data_021015a0;
// Original: arm9/main @ 0x0202C848; symbol: func_0202c848; size: 0x1C.
void SetGlobalValueExceptModesNineAndTen(unsigned int v){if(data_021015a0.mode-9u>1u)data_021015a0.value=v;} }
