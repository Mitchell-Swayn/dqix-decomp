#include <globaldefs.h>
ARM
extern "C" void* MenuRecordList_LocateByKey(void**, unsigned short);
extern "C" void* Menu_GetRecordSpriteResource(void*);
extern "C" void* Menu_GetSpriteCellByIndexOrNull(void*, unsigned int);
extern "C" void MenuRecordList_ReleaseSpriteSlotRange(void*, unsigned int, unsigned int, unsigned int);
// Original: arm9/ov023 @ 0x021FAE88; symbol: Unclassified_DispatchIndexedEntryFieldsToTarget; size: 0x48.
// Uses object halfwords +0x20, +0x22, and +0x24 to find a node and embedded record, then forwards the selected fields to the ov023 helper.
extern "C" void Menu_ReleaseSpriteCellOamSlots(unsigned char* self, void* head) {
    void* node = MenuRecordList_LocateByKey((void**)head, *(unsigned short*)(self + 0x20));
    if (!node) return;
    unsigned char* embedded = (unsigned char*)Menu_GetRecordSpriteResource(node);
    unsigned int recordIndex = *(unsigned short*)(self + 0x22);
    unsigned int value = embedded[0x50];
    unsigned char* record = (unsigned char*)Menu_GetSpriteCellByIndexOrNull(embedded, recordIndex);
    unsigned int word = *(unsigned short*)record;
    MenuRecordList_ReleaseSpriteSlotRange(head, value, *(unsigned short*)(self + 0x24), word);
}
