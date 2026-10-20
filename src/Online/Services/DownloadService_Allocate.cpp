#include <globaldefs.h>
ARM
extern "C" void OnlineMemory_AllocateTagged(unsigned int, void *, void *);
// Original: arm9/ov031 @ 0x02212790; symbol: func_ov031_02212790; size: 0x18.
extern "C" void DownloadService_Allocate(void *first, void *second) { OnlineMemory_AllocateTagged(6, first, second); }
