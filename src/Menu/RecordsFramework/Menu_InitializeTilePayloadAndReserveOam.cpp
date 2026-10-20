#include <globaldefs.h>
ARM
extern "C" void MenuRecord_ResetHeader(void*);
extern "C" void* Menu_GetDisplayRecordRegistry(void*);
extern "C" unsigned short MenuRecordList_FindFreeSpriteSlotRange(void*, unsigned, unsigned);
extern "C" void MenuRecordList_ReserveSpriteSlotRange(void*, unsigned, unsigned, unsigned);
extern "C" void Graphics_ResetTilePayloadWithUnitScale(unsigned*);
extern "C" void* Graphics_GetGlobalOamTransferState();
extern "C" void* Graphics_GetMainOamStagingBuffer();
extern "C" void* Graphics_GetSubOamStagingBuffer();
extern "C" unsigned MenuRecordList_FindFreeTransferSlot(void*, unsigned);
extern "C" void Ov023_SetIndexedHalfwordBit(void*, unsigned, unsigned);
extern "C" void* memset(void*, int, unsigned);
extern "C" void MenuSprite_InitializeFromCompletedNamedResource(char*, void*);
// Original: arm9/ov023 @ 0x021FB534; symbol: Unclassified_InitializeTypeTwelveRecordWithMode; size: 0x10C.
// Initializes a type-12 record, selects a mode-dependent base, stores a derived indexed value, and initializes its embedded payload.
extern "C" int Menu_InitializeTilePayloadAndReserveOam(char* record, void* owner, unsigned valueA, unsigned valueB, unsigned first, unsigned mode) {
    MenuRecord_ResetHeader(record);
    *(unsigned short*)(record + 4) = 12;
    *(unsigned short*)(record + 6) = valueA;
    *(unsigned short*)(record + 8) = valueB;
    *(unsigned short*)(record + 0xa) = 0;
    *(unsigned*)(record + 0x10) = first;
    void* state = Menu_GetDisplayRecordRegistry(owner);
    unsigned short value = MenuRecordList_FindFreeSpriteSlotRange(state, mode, 1);
    MenuRecordList_ReserveSpriteSlotRange(state, mode, value, 1);
    Graphics_ResetTilePayloadWithUnitScale((unsigned*)(record + 0x20));
    void* base;
    if (mode == 0) {
        Graphics_GetGlobalOamTransferState();
        base = Graphics_GetMainOamStagingBuffer();
    } else {
        Graphics_GetGlobalOamTransferState();
        base = Graphics_GetSubOamStagingBuffer();
    }
    *(void**)(record + 0x34) = (char*)base + value * 8;
    *(unsigned*)(record + 0x58) = 0;
    unsigned bit = MenuRecordList_FindFreeTransferSlot(state, mode);
    Ov023_SetIndexedHalfwordBit(state, mode, bit);
    *(unsigned*)(record + 0x5c) = bit & 0xf;
    *(unsigned*)(record + 0x60) = 0;
    *(unsigned char*)(record + 0x7e) = (unsigned char)mode;
    *(unsigned short*)(record + 0xa4) = 0;
    memset(record + 0x94, 0, 0x10);
    *(unsigned*)(record + 0xa8) = 0;
    *(unsigned*)(record + 0xac) = 0;
    record[0xb0] = 0;
    record[0xb1] = 0;
    MenuSprite_InitializeFromCompletedNamedResource(record, owner);
    return 1;
}
