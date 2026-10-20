#include <globaldefs.h>
extern "C" void* Network_GetCommandRecordPool();
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_FindIndexedObjectWithFlag1000(void*, int);
extern "C" unsigned char GameObject_GetAssociatedPartyMemberIndex(void*);
extern "C" unsigned char GameObject_GetSecondaryPartyMemberIndex(void*);
extern "C" unsigned char GameObject_GetFollowPredecessorMember(void*);
extern "C" unsigned char GameObject_GetPartyFormationOrder(void*);
extern "C" void Network_QueueOutgoingRecord(void*, const void*, short);
struct Code26Message { unsigned char tag; unsigned char pad[3]; unsigned short index; unsigned char fields[5]; unsigned char tail[9]; };
// The five payload bytes are described by their source offsets; their meaning is unresolved.
// Original: arm9/ov017 @ 0x021ce32c; symbol: func_ov017_021ce32c; size: 0x80.
extern "C" void Field_QueueObjectPartyFormation(unsigned short index) {
    void* queue = Network_GetCommandRecordPool();
    void* state = _ZN9GameState11GetInstanceEv();
    unsigned char* object = (unsigned char*)GameState_FindIndexedObjectWithFlag1000(state, index);
    if (!object) return;
    Code26Message message;
    message.tag = 0x26;
    message.index = index;
    message.fields[0] = GameObject_GetAssociatedPartyMemberIndex(object);
    message.fields[1] = GameObject_GetSecondaryPartyMemberIndex(object);
    message.fields[2] = GameObject_GetFollowPredecessorMember(object);
    message.fields[3] = GameObject_GetPartyFormationOrder(object);
    message.fields[4] = object[0x2d2];
    Network_QueueOutgoingRecord(queue, &message, 0);
}
