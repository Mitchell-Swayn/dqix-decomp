#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov025_021ef988[];
extern "C" void *GetIndexedEntryPointerOrNull(void *, int);
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" void GameState_ClearObjectByIndex(void *, unsigned);
extern "C" void *Object_GetGlobalSixteenEntryDisplayState(void);
extern "C" unsigned char *GetRecordForObjectIndex208Through223(unsigned char *, int);
extern "C" void Object_ClearD4ByteDisplayEntryAndSetDefaults(unsigned char *);
// Original: arm9/ov025 @ 0x021E4FC8; symbol: func_ov025_021e4fc8; size: 0x4C.
extern "C" int ClearIndexedDisplayObjectAndEntry(unsigned char *object) {
    void *entry = GetIndexedEntryPointerOrNull(*(void **)(data_ov025_021ef988 + 0xc), object[8]);
    if (entry != 0) {
        GameState_ClearObjectByIndex(_ZN9GameState11GetInstanceEv(), *(unsigned *)entry);
        unsigned char *state = (unsigned char *)Object_GetGlobalSixteenEntryDisplayState();
        unsigned char *record = GetRecordForObjectIndex208Through223(state, *(unsigned *)entry);
        if (record != 0) Object_ClearD4ByteDisplayEntryAndSetDefaults(record);
    }
    return 1;
}
