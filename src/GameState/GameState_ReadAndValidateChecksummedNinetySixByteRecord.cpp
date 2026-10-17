#include <globaldefs.h>
#include <GameState/GameState.h>
#include <std_library_functions.h>
extern "C" int func_02075910(unsigned,void*,unsigned,unsigned);extern "C" unsigned FileCache_ComputeCRC32(const void*,unsigned);
struct Data{unsigned checksum;char payload[92];};
// Original: arm9/main @ 0x020AC864; symbol: func_020ac864; size: 0xAC.
extern "C" ARM bool GameState_ReadAndValidateChecksummedNinetySixByteRecord(int alternate){Data data;unsigned char* state=(unsigned char*)GameState::GetInstance();state[0x5cc8]=0;bool ok=true;if(!func_02075910(alternate?0x8024:0x24,&data,96,0))ok=false;if(ok){if(data.checksum!=FileCache_ComputeCRC32((char*)&data+4,92)){state[0x5cc8]=alternate?3:2;ok=false;}else memcpy(state+0x6380,&data,84);}return ok;}
