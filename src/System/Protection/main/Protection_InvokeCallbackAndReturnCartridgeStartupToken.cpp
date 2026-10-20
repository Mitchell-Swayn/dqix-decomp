// Field widths/callee contracts reviewed against original ARM; hardware MMIO addresses retained.
#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
ARM
extern "C" { int BackgroundLoader_CancelTaskAndResetCountAndValue(void*);void ResourceStringLoader_Reset(void*);void** ResourceTracks_GetLargePayloadSection(void*);void GameState_InitializeActorLevelChangeTask(void*);void* Resource_GetActiveGraphicCacheEntry(void*,int); }
struct Bits{unsigned char a:1,b:1,c:1,d:5;};struct Block{unsigned words[12];};
// Original: arm9/main @ 0x020D6BAC; symbol: func_020d6bac; size: 0x1C.
extern "C" unsigned Protection_InvokeCallbackAndReturnCartridgeStartupToken(void(*f)()){if(f)f();return 0xffe41136;}
