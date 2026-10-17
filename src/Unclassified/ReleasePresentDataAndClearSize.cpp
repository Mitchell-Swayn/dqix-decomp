#include <globaldefs.h>
struct State {char pad[0x44];void* data;unsigned size;};extern "C" void DispatchMaskAndClearGlobalMaskBits(void*);
// Original: arm9/main @ 0x020BC9A8; symbol: func_020bc9a8; size: 0x28.
extern "C" void ReleasePresentDataAndClearSize(State* self) {if(!self->data)return;DispatchMaskAndClearGlobalMaskBits(self->data);self->data=0;self->size=0;}
