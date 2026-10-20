#include <globaldefs.h>
ARM
extern "C" int Network_GetLocalMemberId(void*);
extern "C" char* GameState_GetSerializedProgressState();
extern "C" void* memcpy(void*,const void*,unsigned);
struct ChunkHeader {unsigned short length:4,member:2,index:10;};
// Original: arm9/ov017 @ 0x021D2278; symbol: func_ov017_021d2278; size: 0x5C.
// Copies the addressed fourteen-byte progress fragment only when the packed target member matches the local member.
extern "C" void Network_ApplySerializedProgressChunk(void*,char* packet,void*,void*,void* connection) {
 if(Network_GetLocalMemberId(connection)!=((ChunkHeader*)(packet+18))->member)return;
 unsigned offset=((ChunkHeader*)(packet+18))->index*14;
 unsigned char length=((ChunkHeader*)(packet+18))->length;
 char* state=GameState_GetSerializedProgressState();
 memcpy(state+0x2cc+(unsigned char)offset,packet+4,length);
}
