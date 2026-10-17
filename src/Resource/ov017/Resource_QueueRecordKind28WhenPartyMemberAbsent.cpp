#include <globaldefs.h>
ARM
extern "C" void* Object_GetGlobalConnectionState();
extern "C" bool TestInactiveOrPrimaryIndexState(unsigned*);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* _ZN9GameState21GetPartyMemberByIndexEi(void*, int);
extern "C" void* ReadGlobalAt02100044();
extern "C" void MoveQueuedRecordAndApplySourceValue(void*, const void*, short);
// Original: arm9/ov017 @ 0x021CE494; symbol: func_ov017_021ce494; size: 0x4C.
extern "C" void Resource_QueueRecordKind28WhenPartyMemberAbsent(void) {
    if (TestInactiveOrPrimaryIndexState((unsigned*)Object_GetGlobalConnectionState())) return;
    void* state = _ZN9GameState11GetInstanceEv();
    if (_ZN9GameState21GetPartyMemberByIndexEi(state, 0xce) != 0) return;
    unsigned char record[0x14];
    void* object = ReadGlobalAt02100044();
    record[0] = 0x28;
    MoveQueuedRecordAndApplySourceValue(object, record, 0);
}
