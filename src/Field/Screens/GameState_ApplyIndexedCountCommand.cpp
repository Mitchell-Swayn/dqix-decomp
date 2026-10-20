#include <globaldefs.h>
ARM
extern "C" int Network_GetLocalMemberId(char*);
extern "C" bool Network_IsParentOrOffline(unsigned*);
extern "C" void System_QueueFourByteTypedRecord(unsigned,unsigned,unsigned,void*);
struct CountEntry { unsigned pad[2]; unsigned count:7,other:25; char rest[28]; };
struct CountField { unsigned count:7,other:25; char rest[36]; };
struct Status { unsigned short other:13,value:3; };
// Original: arm9/ov017 @ 0x021D3C08; symbol: func_ov017_021d3c08; size: 0x138.
extern "C" void GameState_ApplyIndexedCountCommand(void* self,unsigned char* command,char* game,int unused,char* network) {
 CountEntry* entries=(CountEntry*)(game+0x5e6c);
 if(command[4]==3 && Network_IsParentOrOffline((unsigned*)network)) {
 if(command[6]<=entries[command[7]].count) {
 System_QueueFourByteTypedRecord(command[7],command[6],1,self);
 ((CountField*)((char*)entries+8))[(short)command[7]].count -= command[6];
 } else System_QueueFourByteTypedRecord(command[7],command[6],2,self);
 } else if(command[4]==1) {
 if((signed char)command[5]==Network_GetLocalMemberId(network)) ((Status*)((char*)entries+0x10c))->value=1;
 else ((CountField*)((char*)entries+8))[(short)command[7]].count -= command[6];
 } else if(command[4]==2) {
 if((signed char)command[5]==Network_GetLocalMemberId(network)) ((Status*)((char*)entries+0x10c))->value=2;
 }
}
