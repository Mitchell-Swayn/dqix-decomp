#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" void GameState_ResetGrottoAndTreasureMapInitialFlags(void *);
extern "C" void _ZN19TreasureMapMetadata26ClearInitialByteUnknownBitEv(void *);
extern "C" void Menu_QueueScriptEntry(void *, unsigned int);
// Original data: arm9/ov004 @ 0x2171010; symbol: data_ov004_02171010.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" unsigned char PopulateSelectedRecordTextPanel_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov004 @ 0x02165B60; symbol: func_ov004_02165b60; size: 0x58.
extern "C" int Grotto_ResetInitialFlagsAndTreasureMapRecords(void *state) {
    GameState_ResetGrottoAndTreasureMapInitialFlags(_ZN9GameState11GetInstanceEv());
    int i = 0;
    while (i < *(unsigned char *)((unsigned char *)*(void **)&PopulateSelectedRecordTextPanel_UnknownRoleZeroInitializedStorage + 0x18F4)) {
        _ZN19TreasureMapMetadata26ClearInitialByteUnknownBitEv((unsigned char *)*(void **)&PopulateSelectedRecordTextPanel_UnknownRoleZeroInitializedStorage + i * 0x1C);
        i++;
    }
    Menu_QueueScriptEntry(state, 0x65);
    return 0;
}
