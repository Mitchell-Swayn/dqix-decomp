#include <globaldefs.h>
ARM
extern "C" void SceneCommand_InitializeDisplayOverlay(void*);extern "C" void LinkedQueue_AppendAndMarkActive(void*,void*);
// Original: arm9/main @ 0x020DAC40; symbol: func_020dac40; size: 0x28.
extern "C" void SceneCommand_QueueDisplayOverlay(unsigned char* p){SceneCommand_InitializeDisplayOverlay(*(void**)(p+0x3bc4));LinkedQueue_AppendAndMarkActive(*(void**)(p+0x36fc),*(void**)(p+0x3bc4));}
