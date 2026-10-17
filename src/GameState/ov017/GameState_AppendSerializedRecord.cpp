#include <globaldefs.h>
ARM

struct GameState;
extern "C" int func_ov017_021b6d60(void *, void *);
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" void *GameState_GetIndexList(GameState *);
extern "C" void SlotRecordTable_AssignUnusedSlotIDAndAppendRecord(void *, void *, unsigned, unsigned);

// Original: arm9/ov017 @ 0x021B6C2C; symbol: func_ov017_021b6c2c; size: 0x4C.
extern "C" int GameState_AppendSerializedRecord(void *source, unsigned value) {
    unsigned char record[0x23C];
    if (func_ov017_021b6d60(source, record) == 0) {
        return -1;
    }
    void *indexList = GameState_GetIndexList((GameState *)_ZN9GameState11GetInstanceEv());
    SlotRecordTable_AssignUnusedSlotIDAndAppendRecord(indexList, record, 0, value);
    int id = (signed char)record[0];
    return (id << 26) >> 26;
}
