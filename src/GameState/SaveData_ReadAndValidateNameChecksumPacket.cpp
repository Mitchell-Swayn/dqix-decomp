#include <globaldefs.h>
#include <GameState/GameState.h>
#include <std_library_functions.h>
extern "C" int func_02075910(unsigned,void*,unsigned,unsigned);extern "C" unsigned FileCache_ComputeCRC32(const void*,unsigned);extern "C" char data_020f1be8[];
// Original: arm9/main @ 0x020A94F8; symbol: func_020a94f8; size: 0xAC.
extern "C" ARM int SaveData_ReadAndValidateNameChecksumPacket(unsigned* data,int alternate){if(!func_02075910(alternate?0x8010:0x10,data,20,0))return 0;unsigned char* state=(unsigned char*)GameState::GetInstance();if(!strcmp((char*)(data+2),data_020f1be8)){state[0x5cc8]=alternate?3:2;return 0;}unsigned checksum=FileCache_ComputeCRC32(data+1,16);if(*data!=checksum){state[0x5cc8]=alternate?3:2;return 0;}return 1;}
