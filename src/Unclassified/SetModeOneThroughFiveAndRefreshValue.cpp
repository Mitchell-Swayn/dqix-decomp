#include <globaldefs.h>
struct State {char pad[0xcc];unsigned char mode,value;};extern "C" void UpdateByteLevelTransitionAndThreeChannels(State*,unsigned,int);
// Original: arm9/main @ 0x0209CA70; symbol: func_0209ca70; size: 0x28.
extern "C" void SetModeOneThroughFiveAndRefreshValue(State* self,int mode) {if(mode<1)return;if(mode>5)return;self->mode=mode;UpdateByteLevelTransitionAndThreeChannels(self,self->value,0);}
