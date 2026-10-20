#include <globaldefs.h>
ARM
struct Object;
struct Record { unsigned char type; unsigned char pad[3]; unsigned char index; char text[15]; };
extern "C" void* _ZN9GameState11GetInstanceEv(void);
extern "C" void* Network_GetCommandRecordPool(void);
extern "C" void* GameState_GetObjectWithFlag100(void*, int);
extern "C" unsigned char* GameObject_EncodeNameAsGlyphIds(unsigned char*);
extern "C" char* strcpy(char*, const char*);
extern "C" void Network_QueueOutgoingRecord(Object*, const void*, short);
// Original: arm9/ov017 @ 0x021C45B4; symbol: func_ov017_021c45b4; size: 0x64.
extern "C" void GameState_QueueDecodedObjectName(unsigned index) {
    void* state = _ZN9GameState11GetInstanceEv();
    Object* target = (Object*)Network_GetCommandRecordPool();
    void* object = GameState_GetObjectWithFlag100(state, index);
    if (!object) return;
    Record record;
    record.type = 3;
    record.index = (unsigned char)index;
    strcpy(record.text, (char*)GameObject_EncodeNameAsGlyphIds((unsigned char*)object));
    Network_QueueOutgoingRecord(target, &record, 0);
}
