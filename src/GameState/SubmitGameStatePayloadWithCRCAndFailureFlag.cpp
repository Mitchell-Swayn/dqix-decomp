#include <globaldefs.h>
#include <GameState/GameState.h>
#include <std_library_functions.h>
extern "C" int SaveData_ReadCardSaveBytes(unsigned,void*,unsigned,unsigned);extern "C" int SaveData_WriteBackupBytes(unsigned,const void*,unsigned,unsigned);extern "C" unsigned FileCache_ComputeCRC32(const void*,unsigned);extern "C" void GameState_RequestSaveErrorExit(GameState*);
struct Data{unsigned checksum;char payload[92];};
// Original: arm9/main @ 0x020AC7B4; symbol: func_020ac7b4; size: 0xB0.
extern "C" ARM int SubmitGameStatePayloadWithCRCAndFailureFlag(int alternate){unsigned char check;Data data;GameState* game=GameState::GetInstance();unsigned char* state=(unsigned char*)game;int result;if(!SaveData_ReadCardSaveBytes(0,&check,1,0)){state[0x5cc8]=1;GameState_RequestSaveErrorExit(game);result=0;}else{memset(&data,0,96);memcpy(&data,state+0x6380,84);data.checksum=FileCache_ComputeCRC32((char*)&data+4,92);SaveData_WriteBackupBytes(alternate?0x8024:0x24,&data,96,0);result=1;}return result;}
