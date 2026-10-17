#include <globaldefs.h>
#include <std_library_functions.h>
#include <GameState/GameState.h>
#include <Memory/SafeAllocator.h>
#include <Resource/Script.h>
extern "C" {
// Original: arm9/main @ 0x020AC020; symbol: func_020ac020; size: 0x6C.
int GameState_CopyBoundedIdWordRecords(int unused,short *ids,char *out,int count){char *data=(char *)GameState::GetInstance()+0x75f0;for(int i=0;i<count;i++){int id=ids[i];if(id>=1&&id<=0x134)memcpy(out+i*4,data+(short)(id-1)*4,4);}return 1;}
}
