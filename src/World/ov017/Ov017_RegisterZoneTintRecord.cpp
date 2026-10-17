#include <globaldefs.h>
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameResources_GetInstance();
extern "C" void Ov017_InitializeZoneTintRecord(unsigned char);
extern "C" void* GameState_ReadUnkF8(void*);
extern "C" void* Object_GetGlobalDisplayManager();
extern "C" int InsertRecordByDescendingClassification(unsigned char*, short, int, signed char);
// Original: arm9/ov017 @ 0x0219BF04; symbol: func_ov017_0219bf04; size: 0x70.
extern "C" ARM void Ov017_RegisterZoneTintRecord(unsigned char enabled, int insert) {
    void* state = _ZN9GameState11GetInstanceEv();
    unsigned char* resources = (unsigned char*)GameResources_GetInstance();
    Ov017_InitializeZoneTintRecord(enabled);
    unsigned char* record = (unsigned char*)GameState_ReadUnkF8(state);
    record[0x6e] = 1;
    record[0xa] = 0;
    record[0x67] = 1;
    if (!insert) {
        *(unsigned short*)(resources + 0x44b2) = 0x4e23;
        return;
    }
    InsertRecordByDescendingClassification((unsigned char*)Object_GetGlobalDisplayManager(), 0x4e23, -1, 0);
}
