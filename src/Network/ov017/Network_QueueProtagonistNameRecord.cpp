#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned char* _ZN9GameState14GetProtagonistEv(void*);
extern "C" void *Object_GetGlobalConnectionState();
extern "C" void* ReadGlobalAt02100044();
extern "C" int ReadIndexedSignedField1038(char* p);
extern "C" unsigned char* ClearAndDecodeTwelveByteField141(unsigned char* object);
struct Object;
extern "C" void MoveQueuedRecordAndApplySourceValue(Object* object,const void* source,short value);
extern "C" char* strncpy(char*,const char*,unsigned int);
// Original: arm9/ov017 @ 0x021CC0CC; symbol: func_ov017_021cc0cc; size: 0x7C.
extern "C" void Network_QueueProtagonistNameRecord() {
 void* state = _ZN9GameState11GetInstanceEv();
 void* connection = Object_GetGlobalConnectionState();
 void* queue = ReadGlobalAt02100044();
 unsigned char* protagonist = _ZN9GameState14GetProtagonistEv(state);
 if (protagonist) {
 struct Record { unsigned char type; unsigned char pad[3]; unsigned char index; unsigned char flag; char name[12]; } record;
 record.type = 0x2b;
 record.index = ReadIndexedSignedField1038((char*)connection);
 record.flag = 1;
 strncpy(record.name,(const char*)ClearAndDecodeTwelveByteField141(protagonist),12);
 MoveQueuedRecordAndApplySourceValue((Object*)queue,&record,0);
 }
}
