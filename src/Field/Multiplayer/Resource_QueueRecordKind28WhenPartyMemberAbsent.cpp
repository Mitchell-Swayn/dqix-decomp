#include <globaldefs.h>
ARM
extern "C" void* Network_GetConnectionManager();
extern "C" bool Network_IsParentOrOffline(unsigned*);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* _ZN9GameState21GetPartyMemberByIndexEi(void*, int);
extern "C" void* Network_GetCommandRecordPool();
extern "C" void Network_QueueOutgoingRecord(void*, const void*, short);
// Original: arm9/ov017 @ 0x021CE494; symbol: func_ov017_021ce494; size: 0x4C.
extern "C" void Resource_QueueRecordKind28WhenPartyMemberAbsent(void) {
    if (Network_IsParentOrOffline((unsigned*)Network_GetConnectionManager())) return;
    void* state = _ZN9GameState11GetInstanceEv();
    if (_ZN9GameState21GetPartyMemberByIndexEi(state, 0xce) != 0) return;
    unsigned char record[0x14];
    void* object = Network_GetCommandRecordPool();
    record[0] = 0x28;
    Network_QueueOutgoingRecord(object, record, 0);
}
