#include <globaldefs.h>
#include "GameState/GameState.h"
extern "C" int IsBitFieldFlagNonzero();extern "C" void* GameState_GetIndexList();extern "C" int func_020a0a08(void*,int,int);extern "C" void GameState_CopyB0ByteStateBufferToOutput(void*);extern "C" void AddToBitFieldAtOffset18SaturatingAt100(void*,int);extern "C" void GameState_Copy176BytesAtOffset7540(void*);
// Original: arm9/main @ 0x020DDDCC; symbol: func_020dddcc; size: 0x70.
extern "C" ARM int UpdateSelectedRecordAndOptionalCounter(char* p){unsigned work[44];if(!IsBitFieldFlagNonzero())return 0;GameState::GetInstance();if(!func_020a0a08(GameState_GetIndexList(),*(short*)(p+0x18),1))return 0;if(*(unsigned*)(p+8)>>31){GameState_CopyB0ByteStateBufferToOutput(work);AddToBitFieldAtOffset18SaturatingAt100(work,1);GameState_Copy176BytesAtOffset7540(work);}return 1;}
