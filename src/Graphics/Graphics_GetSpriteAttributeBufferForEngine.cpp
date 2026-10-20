#include <globaldefs.h>
extern "C" {
void *Graphics_GetGlobalOamTransferState();void Graphics_GetSubOamStagingBuffer(void *);void Graphics_GetMainOamStagingBuffer(void *);
// Original: arm9/main @ 0x02093704; symbol: func_02093704; size: 0x28.
void Graphics_GetSpriteAttributeBufferForEngine(int v){void *p=Graphics_GetGlobalOamTransferState();Graphics_GetSubOamStagingBuffer(p);if(!v)Graphics_GetMainOamStagingBuffer(p);}
}
