#include <globaldefs.h>
struct Input {unsigned short a,mode;};struct State {char pad[16];unsigned state;};extern "C" State data_021015a0;extern "C" void DisableInterruptsAndHaltForever();
// Original: arm9/main @ 0x0202DAE0; symbol: func_0202dae0; size: 0x28.
extern "C" void SetGlobalStateNineForInputModeEight(Input* input) {if(input->mode!=8)return;data_021015a0.state=9;DisableInterruptsAndHaltForever();}
