// Field widths/callee contracts reviewed against original ARM; hardware MMIO addresses retained.
#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
ARM
extern "C" { int BackgroundLoader_CancelTaskAndResetCountAndValue(void*);void ResourceStringLoader_Reset(void*);void** ResourceTracks_GetLargePayloadSection(void*);void GameState_InitializeActorLevelChangeTask(void*);void* Resource_GetActiveGraphicCacheEntry(void*,int); }
struct Bits{unsigned char a:1,b:1,c:1,d:5;};struct Block{unsigned words[12];};
// Original: arm9/main @ 0x0202ECC8; symbol: func_0202ecc8; size: 0x24.
extern "C" void Camera_SetParentTransform(char* p,Block* out){*(Block*)(p+240)=*out;}
