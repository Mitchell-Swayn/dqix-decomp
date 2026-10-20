#include <globaldefs.h>
extern "C" void* Network_GetCommandRecordPool();
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* _ZN9GameState21GetPartyMemberByIndexEi(void*, int);
extern "C" unsigned char* GameObject_GetLinkedIndexedState(void*);
extern "C" void Network_QueueOutgoingRecord(void*, const void*, short);
// Original: arm9/ov017 @ 0x021D0E00; symbol: func_ov017_021d0e00; size: 0x64.
extern "C" void GameState_QueuePartyMemberFieldUpdate(int index) {
    char record[0x14];
    void* object = Network_GetCommandRecordPool();
    *(unsigned char*)record = 0x18;
    char* fields = record + 4;
    void* member = _ZN9GameState21GetPartyMemberByIndexEi(_ZN9GameState11GetInstanceEv(), index);
    if (member == 0) return;
    unsigned char* field = GameObject_GetLinkedIndexedState(member);
    if (field == 0) return;
    fields[0] = (char)index;
    fields[1] = (char)field[0x56a];
    Network_QueueOutgoingRecord(object, record, 0);
}
