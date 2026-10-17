#include <globaldefs.h>
struct State {char pad[24];int count;};extern "C" int Input_TestKeyMask(State*,unsigned);extern "C" int Object_TestNewlySetHalfwordMask(State*,unsigned);
// Original: arm9/main @ 0x0201248C; symbol: func_0201248c; size: 0x80.
extern "C" int Input_PollKeyRepeatCountdown(State* self,unsigned key) {if(Input_TestKeyMask(self,key)){if(!self->count){if(Object_TestNewlySetHalfwordMask(self,key)){self->count=8;return 1;}else {self->count=0;return 1;}}--self->count;}else {if(!Input_TestKeyMask(self,0xfff7))self->count=0;}return 0;}
