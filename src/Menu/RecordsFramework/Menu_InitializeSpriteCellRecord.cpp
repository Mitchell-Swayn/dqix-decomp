#include <globaldefs.h>
ARM
extern "C" void MenuRecord_ResetHeader(void*);
extern "C" void* Menu_GetDisplayRecordRegistry(void*);
extern "C" void* MenuRecordList_LocateByKey(void**, unsigned short);
extern "C" void* Menu_GetRecordSpriteResource(void*);
extern "C" void* Menu_GetSpriteCellByIndexOrNull(void*, unsigned short);
extern "C" unsigned short MenuRecordList_FindFreeSpriteSlotRange(void*, unsigned char, unsigned short);
extern "C" void MenuRecordList_ReserveSpriteSlotRange(void*, unsigned char, unsigned short, unsigned short);
// Original: arm9/ov023 @ 0x021FAD84; symbol: Unclassified_InitializeTypeOneRecordAndResolveIndexedValue; size: 0x104.
// Initializes a type-1 record, resolves an indexed value from its owner state, and clears transient fields.
extern "C" int Menu_InitializeSpriteCellRecord(char* record, void* owner, unsigned short valueA, unsigned short valueB, unsigned first, unsigned second) {
    MenuRecord_ResetHeader(record);
    *(unsigned short*)(record + 4) = 1;
    *(unsigned short*)(record + 6) = valueA;
    *(unsigned short*)(record + 8) = valueB;
    *(unsigned short*)(record + 0xa) = 0;
    *(unsigned*)(record + 0x10) = 0;
    *(unsigned*)(record + 0x1c) = 2;
    *(unsigned short*)(record + 0x20) = (unsigned short)first;
    *(unsigned char*)(record + 0x3a) = 1;
    *(unsigned short*)(record + 0x44) = 0;
    *(unsigned short*)(record + 0x46) = 0;
    void* state = Menu_GetDisplayRecordRegistry(owner);
    void* found = MenuRecordList_LocateByKey((void**)state, *(unsigned short*)(record + 0x20));
    if (found) {
    unsigned char* embedded = (unsigned char*)Menu_GetRecordSpriteResource(found);
    unsigned char selector = embedded[0x50];
    *(unsigned short*)(record + 0x22) = (unsigned short)second;
    void* indexed = Menu_GetSpriteCellByIndexOrNull(embedded, *(unsigned short*)(record + 0x22));
    unsigned short item = *(unsigned short*)indexed;
    volatile unsigned short* resolved = (volatile unsigned short*)(record + 0x24);
    *resolved = MenuRecordList_FindFreeSpriteSlotRange(state, selector, item);
    MenuRecordList_ReserveSpriteSlotRange(state, selector, *resolved, item);
    *(unsigned short*)(record + 0x26) = 0;
    *(unsigned*)(record + 0x28) = 0;
    *(unsigned*)(record + 0x2c) = 0;
    *(unsigned short*)(record + 0x36) = 0;
    *(unsigned short*)(record + 0x34) = 0;
    *(unsigned short*)(record + 0x32) = 0;
    *(unsigned short*)(record + 0x30) = 0;
    int cleared = 0;
    *(signed char*)(record + 0x38) = (signed char)(cleared - 1);
    *(signed char*)(record + 0x39) = (signed char)(cleared - 1);
    *(unsigned short*)(record + 0x3c) = 0;
    *(unsigned short*)(record + 0x3e) = 0;
    *(unsigned short*)(record + 0x40) = 0;
    *(unsigned short*)(record + 0x42) = 0;
    *(unsigned short*)(record + 0x48) = 0;
    *(unsigned char*)(record + 0x4a) = 0;
    *(unsigned char*)(record + 0x4b) = 0;
        return 1;
    }
    return 0;
}
