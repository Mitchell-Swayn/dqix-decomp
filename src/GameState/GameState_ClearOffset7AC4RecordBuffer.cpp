// Original ARM operations and field access widths reviewed.
#include <GameState/GameState.h>
extern "C" void* memcpy(void*,const void*,unsigned int);extern "C" void* memset(void*,int,unsigned int);extern "C" char* data_02110370[];struct ByteCounter{unsigned int low:24;unsigned int count:8;};
// Original: arm9/main @ 0x020AC0DC; symbol: func_020ac0dc; size: 0x28.
extern "C" int GameState_ClearOffset7AC4RecordBuffer(){char* p=(char*)GameState::GetInstance();memset(p+0x7ac4,0,0x3ae);return 1;}
