#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void Network_InitializeRecordPoolAndPeerBuffers(void*);
// Original: arm9/main @ 0x0205E324; symbol: func_0205e324; size: 0xC.
extern "C" void LinkedQueue_InitializeWrapper(void* object){Network_InitializeRecordPoolAndPeerBuffers(object);}
