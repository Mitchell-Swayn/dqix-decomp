#include <globaldefs.h>
ARM
struct GameState;
extern "C" void* GameState_GetObjectWithFlag100(void*,int);
extern "C" void* GameState_GetIndexList(GameState*);
extern "C" unsigned char* ReadWordFieldAtOffset150(void*);
// Original: arm9/ov017 @ 0x021D00C8; symbol: func_ov017_021d00c8; size: 0x9C.
extern "C" void GameState_CopyHalfwordRangeToUnlistedObject(void*,unsigned char* source,GameState* gs){
 int id=*(int*)(source+4);
 unsigned char* record=source+4;
 unsigned char* list=(unsigned char*)GameState_GetIndexList(gs);
 for(int i=0;i<list[0xf7c];i++)if(id==*(unsigned char*)(list+i+0xf78))return;
 void* obj=GameState_GetObjectWithFlag100(gs,id);
 if(!obj)return;
 unsigned char* payload=ReadWordFieldAtOffset150(obj);
 if(!payload)return;
 short* dest=(short*)(payload+0x454);
 int start=record[4];int count=record[5];
 for(int j=0;j<count;j++)dest[start+j]=*(short*)(record+6+j*2);
}
