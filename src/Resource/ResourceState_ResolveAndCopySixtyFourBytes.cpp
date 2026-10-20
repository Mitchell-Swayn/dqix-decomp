#include <globaldefs.h>
#include <System/Memory.h>
struct State { char pad[0xa4]; void* source; char data[0x40]; };
extern "C" void* NNS_SndArcGetFileAddress(void*);
// Original: arm9/main @ 0x020C0110; symbol: func_020c0110; size: 0x28.
extern "C" int ResourceState_ResolveAndCopySixtyFourBytes(State* state,void* input) { void* source=NNS_SndArcGetFileAddress(input); state->source=source; MI_CpuCopy8(source,state->data,0x40); return 1; }
