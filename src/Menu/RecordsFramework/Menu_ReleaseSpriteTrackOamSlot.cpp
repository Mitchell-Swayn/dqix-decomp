#include <globaldefs.h>
ARM
extern "C" void* MenuRecordList_LocateByKey(void**, unsigned short);
extern "C" void* Menu_GetRecordSpriteResource(void*);
extern "C" void MenuRecordList_ReleaseSpriteSlotRange(void*, unsigned, unsigned, unsigned);
extern "C" void* SpriteAnimation_FindTrackByKey(void*, unsigned);
// Original: arm9/ov023 @ 0x021FB364; symbol: func_ov023_021fb364; size: 0x64.
extern "C" void Menu_ReleaseSpriteTrackOamSlot(void* state, void* list) {
    void* node = MenuRecordList_LocateByKey((void**)list, *(unsigned short*)((char*)state + 0x20));
    if (node == 0) return;
    unsigned char* embedded = (unsigned char*)Menu_GetRecordSpriteResource(node);
    MenuRecordList_ReleaseSpriteSlotRange(list, embedded[0x50], *(unsigned short*)((char*)state + 0x24), 1);
    void* records = *(void**)(embedded + 0x3c);
    if (records == 0) return;
    void* record = SpriteAnimation_FindTrackByKey(records, *(unsigned short*)((char*)state + 0x22));
    if (record != 0) *(unsigned char*)((char*)record + 0x15) &= ~8;
}
