#include <globaldefs.h>
ARM
#include <GameState/GameState.h>
#include <Memory/SafeAllocator.h>

// Original: arm9/main @ 0x020A39D8; symbol: func_020a39d8; size: 0x5C.
extern "C" void TreasureMap_FreeLanguageDataAndOffsets(SafeAllocator* alloc){GameState* state=GameState::GetInstance();GameResources* context=GameResources_GetInstance();unsigned char* data=state->GetTreasureMapLanguageData();alloc->Free(context->pTMapLanguageOffsets);alloc->Free(data);state->SetTreasureMapLanguageDataPtr(0);context->pTMapLanguageOffsets=0;}
