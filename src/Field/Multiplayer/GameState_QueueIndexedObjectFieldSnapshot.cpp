#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* Network_GetConnectionManager();
extern "C" void* Network_GetCommandRecordPool();
extern "C" bool Network_IsParentOrOffline(unsigned*);
extern "C" void* GameState_FindIndexedObjectWithFlag1000(void*, int);
extern "C" unsigned char* GameObject_GetLinkedIndexedState(void*);
extern "C" void* GameState_GetIndexList(void*);
extern "C" void* GameState_GetObjectWithFlag100(void*, int);
extern "C" void Network_QueueOutgoingRecord(void*, const void*, short);
struct QueuedIndexSnapshot { unsigned char kind; unsigned char padding[3]; signed char fields[8]; unsigned char trailing[8]; };
// Original: arm9/ov017 @ 0x021C847C; symbol: GameState_QueueIndexedObjectFieldSnapshot; size: 0x10C.
// Builds a 0x76 request from four indexed object fields and four derived flag bits, then queues it for a source object.
extern "C" void GameState_QueueIndexedObjectFieldSnapshot() {
    void* gameState = _ZN9GameState11GetInstanceEv();
    unsigned* connection = (unsigned*)Network_GetConnectionManager();
    void* source = Network_GetCommandRecordPool();
    QueuedIndexSnapshot request;
    request.kind = 0x76;
    signed char* fields = request.fields;
    for (int i = 0; i < 4; ++i) {
        fields[i] = -1;
        (fields + i)[4] = -1;
    }
    if (Network_IsParentOrOffline(connection)) {
        for (int i = 0; i < 4; ++i) {
            void* object = GameState_FindIndexedObjectWithFlag1000(gameState, i);
            if (object) {
                unsigned char* objectFields = GameObject_GetLinkedIndexedState(object);
                if (objectFields) fields[i] = (signed char)*(unsigned*)(objectFields + 0x94c);
            }
        }
    }
    unsigned char* indexList = (unsigned char*)GameState_GetIndexList(gameState);
    for (int i = 0; i < indexList[0xf7c]; ++i) {
        unsigned char index = (indexList + i)[0xf78];
        void* object = GameState_GetObjectWithFlag100(gameState, index);
        if (object) {
            unsigned char* objectFields = GameObject_GetLinkedIndexedState(object);
            if (objectFields) (fields + index)[4] = (signed char)((*(unsigned*)(objectFields + 0x78) << 1) >> 31);
        }
    }
    Network_QueueOutgoingRecord(source, &request, 0);
}
