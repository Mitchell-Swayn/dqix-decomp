#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned char* _ZN9GameState14GetProtagonistEv(void*);
extern "C" void *Network_GetConnectionManager();
extern "C" void* Network_GetCommandRecordPool();
extern "C" int Network_GetLocalMemberId(char* p);
extern "C" unsigned char* GameObject_EncodeNameAsGlyphIds(unsigned char* object);
struct Object;
extern "C" void Network_QueueOutgoingRecord(Object* object,const void* source,short value);
extern "C" char* strncpy(char*,const char*,unsigned int);
// Original: arm9/ov017 @ 0x021CC0CC; symbol: func_ov017_021cc0cc; size: 0x7C.
extern "C" void Network_QueueProtagonistNameRecord() {
 void* state = _ZN9GameState11GetInstanceEv();
 void* connection = Network_GetConnectionManager();
 void* queue = Network_GetCommandRecordPool();
 unsigned char* protagonist = _ZN9GameState14GetProtagonistEv(state);
 if (protagonist) {
 struct Record { unsigned char type; unsigned char pad[3]; unsigned char index; unsigned char flag; char name[12]; } record;
 record.type = 0x2b;
 record.index = Network_GetLocalMemberId((char*)connection);
 record.flag = 1;
 strncpy(record.name,(const char*)GameObject_EncodeNameAsGlyphIds(protagonist),12);
 Network_QueueOutgoingRecord((Object*)queue,&record,0);
 }
}
