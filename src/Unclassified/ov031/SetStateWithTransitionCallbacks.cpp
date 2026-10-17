#include <globaldefs.h>
ARM
struct State { char pad[64]; int value; };
struct Globals { void (*callback)(int,const char*,int); State* state; };
extern "C" Globals data_ov031_02290d18;
extern "C" int data_ov031_0224c318[];
extern "C" char data_ov031_0224c340[];
extern "C" char data_ov031_0224c348[];
// Original: arm9/ov031 @ 0x02239368; symbol: func_ov031_02239368; size: 0x7C.
extern "C" void SetStateWithTransitionCallbacks(int value) {
 if (data_ov031_02290d18.callback) data_ov031_02290d18.callback(0x8000000,data_ov031_0224c340,data_ov031_0224c318[data_ov031_02290d18.state->value]);
 data_ov031_02290d18.state->value=value;
 if (data_ov031_02290d18.callback) data_ov031_02290d18.callback(0x8000000,data_ov031_0224c348,data_ov031_0224c318[data_ov031_02290d18.state->value]);
}
