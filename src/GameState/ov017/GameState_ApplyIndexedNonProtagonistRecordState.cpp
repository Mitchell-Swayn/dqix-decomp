#include <globaldefs.h>
ARM
struct PackedState { unsigned short a:2,b:4,c:3,kind:3,e:2,other:2; };
struct Packet { unsigned short unused[2]; unsigned short id,index; PackedState bits; unsigned char x,y; unsigned short values[4]; };
struct Record { unsigned char pad0[4]; unsigned short values[4]; unsigned char pad1[0x16]; PackedState bits; unsigned char x,y; unsigned char pad2[0x7e]; };
extern "C" {
void* OV017_GetEmbeddedField1C(void*);
int GameState_ReadProtagonistObjectIndex(void*);
void WriteKindAndSetStateFive(void*,unsigned short);
}
// Original: arm9/ov017 @ 0x021CA6DC; symbol: func_ov017_021ca6dc; size: 0x140.
extern "C" void GameState_ApplyIndexedNonProtagonistRecordState(void*,Packet* packet,void* state,unsigned char* context) {
unsigned char* object=(unsigned char*)OV017_GetEmbeddedField1C(*(void**)(context+0x3718));
if(!object)return;
if(*(signed char*)(object+0x2a)==GameState_ReadProtagonistObjectIndex(state))return;
if(*(unsigned short*)(object+8)!=packet->id)return;
int index=packet->index-0xc0;
if(index<0 || index>=8)return;
Record* record=(Record*)(object+0x158+index*0xa4);
record->bits.a=(unsigned char)packet->bits.a;
record->bits.b=(unsigned char)packet->bits.b;
record->bits.c=(unsigned char)packet->bits.c;
WriteKindAndSetStateFive(record,(unsigned char)packet->bits.kind);
record->bits.e=(unsigned char)packet->bits.e;
record->x=packet->x;
record->y=packet->y;
record->values[0]=packet->values[0];
record->values[1]=packet->values[1];
record->values[2]=packet->values[2];
record->values[3]=packet->values[3];
}
