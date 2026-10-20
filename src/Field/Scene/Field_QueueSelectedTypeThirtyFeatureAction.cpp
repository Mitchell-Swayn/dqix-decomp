#include <globaldefs.h>
ARM
extern "C" void FieldBookshelf_InitializeReadCommand(unsigned char*);
extern "C" void FieldBookshelf_SetFeatureDescriptor(void*,unsigned int);
extern "C" void LinkedQueue_AppendAndMarkActive(unsigned int*,unsigned int);
// Original: arm9/ov017 @ 0x0219931C; symbol: func_ov017_0219931c; size: 0x44.
extern "C" void Field_QueueSelectedTypeThirtyFeatureAction(unsigned char* state) {
 if (!state[0x36b8]) return;
 FieldBookshelf_InitializeReadCommand(*(unsigned char**)(state+0x3b18));
 FieldBookshelf_SetFeatureDescriptor(*(void**)(state+0x3b18),*(unsigned int*)(state+0x36bc));
 LinkedQueue_AppendAndMarkActive(*(unsigned int**)(state+0x36fc),*(unsigned int*)(state+0x3b18));
}
