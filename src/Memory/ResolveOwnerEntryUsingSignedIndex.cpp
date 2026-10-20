// Field widths/callee contracts reviewed against original ARM; hardware MMIO addresses retained.
#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
ARM
extern "C" { int BackgroundLoader_CancelTaskAndResetCountAndValue(void*);void ResourceStringLoader_Reset(void*);void** ResourceTracks_GetLargePayloadSection(void*);void GameState_InitializeActorLevelChangeTask(void*);void* Resource_GetActiveGraphicCacheEntry(void*,int); }
struct Bits{unsigned char a:1,b:1,c:1,d:5;};struct Block{unsigned words[12];};
// Original: arm9/main @ 0x0203F008; symbol: func_0203f008; size: 0x24.
extern "C" void* ResolveOwnerEntryUsingSignedIndex(char* p){void* q=*(void**)p;if(!q)return 0;return Resource_GetActiveGraphicCacheEntry(q,*(short*)(p+40));}
