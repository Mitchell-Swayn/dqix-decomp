#include <globaldefs.h>
ARM
#include <GameState/GameState.h>
extern "C" unsigned char* Zone3D_GetMainInstance();extern "C" void Network_GetCommandRecordPool();extern "C" int Network_CountFreeMessages();extern "C" void GameState_QueueThirteenByteChunk(void*,unsigned,int,unsigned,int);
// Original: arm9/main @ 0x020DBCC4; symbol: func_020dbcc4; size: 0xCC.
extern "C" void Object_ProcessThirteenByteChunksUntilEnd(unsigned char* object){bool done;int i;unsigned char* data;GameState::GetInstance();data=Zone3D_GetMainInstance()+0x840;if(!*(int*)(object+16)){Network_GetCommandRecordPool();if(Network_CountFreeMessages()>=0x76){done=false;for(i=0;i<4;i++){int offset=*(int*)(object+12);if(offset+13>0x1b30){done=true;GameState_QueueThirteenByteChunk(data+offset,(0x1b30-offset)&0xff,1,object[8],offset);break;}GameState_QueueThirteenByteChunk(data+offset,13,0,object[8],offset);*(int*)(object+12)+=13;}if(done)object[1]=1;}}}
