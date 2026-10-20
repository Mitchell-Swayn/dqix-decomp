#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned char* GameState_GetIndexList(void*);
extern "C" void* GameState_GetObjectWithFlag100(void*, int);
extern "C" unsigned char* GameObject_GetLinkedIndexedState(void*);
extern "C" void* Network_GetCommandRecordPool();
extern "C" int Network_IsOutgoingRecordQueueDrained(void*);
extern "C" void* Field_QueueJoiningMemberFullState(int, int);
extern "C" void Field_QueueNameAndCacheMemberText(int, int, const char*);
extern "C" void Field_QueueMemberProfileFragments(int, int, int, int);
extern "C" void Field_QueueMemberProfileRequest(int, int, int);
// Original: arm9/ov017 @ 0x021B04E0; symbol: Resource_ProcessNextIndexedRecord; size: 0xDC.
// Advances a record-list cursor, initializes its selected object once, then waits for the queue to drain.
extern "C" int Resource_ProcessNextIndexedRecord(void* self) {
    unsigned char* bytes = (unsigned char*)self;
    void* state = _ZN9GameState11GetInstanceEv();
    if (bytes[0x21] == 0) {
        unsigned char* list = GameState_GetIndexList(state);
        unsigned int index = bytes[0x22];
        if (list[0xf7c] == index) {
            Field_QueueNameAndCacheMemberText(4, 0, (const char*)0);
            return 11;
        }
        unsigned char* entries = list + 0xf78;
        unsigned char item = entries[index];
        bytes[0x22] = (unsigned char)(index + 1);
        void* object = GameState_GetObjectWithFlag100(state, item);
        if (!object) return bytes[0xa];
        unsigned char* record = GameObject_GetLinkedIndexedState(object);
        Field_QueueJoiningMemberFullState(item, *(unsigned int*)(record + 0x950) & 0xff);
        Field_QueueMemberProfileFragments(-1, 5, 1, 1);
        Field_QueueMemberProfileRequest(-1, 1, 1);
        ++bytes[0x21];
    } else if (bytes[0x21] == 1 && Network_IsOutgoingRecordQueueDrained(Network_GetCommandRecordPool())) {
        bytes[0x21] = 0;
    }
    return bytes[0xa];
}
