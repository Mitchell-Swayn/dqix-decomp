#include <globaldefs.h>
ARM
struct Entry{void(*fn)(void*);void* data;unsigned char generation;unsigned char pad[3];};extern "C" Entry data_02114260[];
// Original: arm9/main @ 0x020D29B0; symbol: func_020d29b0; size: 0x44.
extern "C" void InvokeGenerationMatchedHandleCallback(int handle){Entry* p=data_02114260+(handle&255);unsigned generation=(handle>>8)&255;if(generation!=p->generation)return;if(p->fn)p->fn(p->data);}
