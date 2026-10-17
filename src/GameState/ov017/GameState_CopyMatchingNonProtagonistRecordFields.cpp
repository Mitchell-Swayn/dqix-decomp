#include <globaldefs.h>
ARM
struct GameState;
extern "C" int GameState_ReadProtagonistObjectIndex(GameState*);
extern "C" void* OV017_GetEmbeddedField1C(void*);
struct Entry {unsigned short a,b;unsigned char pad[16];int x,y;unsigned char rest[0xa4-0x1c];};
struct Target {unsigned char pad[8];unsigned short id;unsigned char pad2[0x20];signed char object;unsigned char pad3[0x12d];Entry entries[8];};
struct Source {int unused;unsigned short id,index,a,b;int x,y;};
// Original: arm9/ov017 @ 0x021CA4A8; symbol: func_ov017_021ca4a8; size: 0x8C.
extern "C" void GameState_CopyMatchingNonProtagonistRecordFields(void*,Source* src,GameState* gs,unsigned char* ctx){
 Target* dst=(Target*)OV017_GetEmbeddedField1C(*(void**)(ctx+0x3718));
 if(!dst)return;
 if(dst->object==GameState_ReadProtagonistObjectIndex(gs))return;
 if(dst->id!=src->id)return;
 int index=src->index-0xc0;
 if(index<0)return;if(index>=8)return;
 Entry* entries=dst->entries;
 Entry* entry=&entries[index];
 entry->a=src->a;
 entry->b=src->b;
 entry->x=src->x;
 entry->y=src->y;
}
