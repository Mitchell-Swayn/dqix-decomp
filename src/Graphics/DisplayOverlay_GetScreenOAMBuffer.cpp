#include <globaldefs.h>
ARM
extern "C" void* Graphics_GetGlobalOamTransferState();extern "C" void Graphics_GetSubOamStagingBuffer(void*);extern "C" void Graphics_GetMainOamStagingBuffer(void*);
// Original: arm9/main @ 0x020DB2DC; symbol: func_020db2dc; size: 0x28.
extern "C" void DisplayOverlay_GetScreenOAMBuffer(void*,int retain){void* q=Graphics_GetGlobalOamTransferState();Graphics_GetSubOamStagingBuffer(q);if(retain)return;Graphics_GetMainOamStagingBuffer(q);}
