#include <globaldefs.h>
extern "C" void* ReadGlobalAt02100044();
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* _ZN9GameState21GetPartyMemberByIndexEi(void*, int);
extern "C" unsigned char* ReadWordFieldAtOffset150(void*);
extern "C" void MoveQueuedRecordAndApplySourceValue(void*, const void*, short);
// Original: arm9/ov017 @ 0x021D0E00; symbol: func_ov017_021d0e00; size: 0x64.
extern "C" void GameState_QueuePartyMemberFieldUpdate(int index) {
    char record[0x14];
    void* object = ReadGlobalAt02100044();
    *(unsigned char*)record = 0x18;
    char* fields = record + 4;
    void* member = _ZN9GameState21GetPartyMemberByIndexEi(_ZN9GameState11GetInstanceEv(), index);
    if (member == 0) return;
    unsigned char* field = ReadWordFieldAtOffset150(member);
    if (field == 0) return;
    fields[0] = (char)index;
    fields[1] = (char)field[0x56a];
    MoveQueuedRecordAndApplySourceValue(object, record, 0);
}
