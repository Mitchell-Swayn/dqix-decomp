#include <globaldefs.h>
struct State {unsigned value,first,zero,last;};extern "C" unsigned Timer_InterpolateIntegerValue(State*,unsigned,unsigned);
// Original: arm9/main @ 0x020C0204; symbol: func_020c0204; size: 0x28.
extern "C" void InitializeRangeStateAndDerivedValue(State* self,unsigned first,unsigned last) {self->value=Timer_InterpolateIntegerValue(self,first,last);self->first=first;self->last=last;self->zero=0;}
