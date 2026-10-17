#include <globaldefs.h>
ARM
extern "C" void Graphics_CleanConfiguredDestinationCache(void*,void*);extern "C" void func_0204b088(void*,void*);
// Original: arm9/main @ 0x0204B0E8; symbol: func_0204b0e8; size: 0x34.
extern "C" void UpdateProvidedOrStoredChildResource(char* p,void* q){if(!q)q=*(void**)(p+20);if(!q)return;Graphics_CleanConfiguredDestinationCache(p,q);func_0204b088(p,q);}
