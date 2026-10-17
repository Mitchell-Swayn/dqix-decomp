// Original ARM operations and field access widths reviewed.
#include <GameState/GameState.h>
extern "C" void* memcpy(void*,const void*,unsigned int);extern "C" void* memset(void*,int,unsigned int);extern "C" char* data_02110370[];struct ByteCounter{unsigned int low:24;unsigned int count:8;};
// Original: arm9/main @ 0x020AC08C; symbol: func_020ac08c; size: 0x28.
extern "C" int GameState_CopyFourBytesToField7AC0(const void* in){char* p=(char*)GameState::GetInstance();memcpy(p+0x7ac0,in,4);return 1;}
