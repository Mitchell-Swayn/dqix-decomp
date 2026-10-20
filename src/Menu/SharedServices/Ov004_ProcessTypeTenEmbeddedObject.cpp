#include <globaldefs.h>
extern "C" void* Menu_GetDisplayRecordRegistry(void*);
extern "C" unsigned int TextContext_GetSharedInstance(void*);
extern "C" void* MenuRecordList_LocateByKey(void**, unsigned short);
extern "C" unsigned MenuRecord_GetType(void*);
extern "C" void* Menu_GetRecordSpriteResource(void*);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void GameState_WriteUnknownF70(void*, unsigned char);
// Original: arm9/ov004 @ 0x0216E828; symbol: func_ov004_0216e828; size: 0x6C.
extern "C" ARM int Ov004_ProcessTypeTenEmbeddedObject(void* self) {
    void* object = Menu_GetDisplayRecordRegistry(self);
    unsigned int* destination = (unsigned int*)TextContext_GetSharedInstance(object);
    void* record = MenuRecordList_LocateByKey((void**)object, 10);
    if (!record)
        return 0;
    if (MenuRecord_GetType(record) != 10)
        return 0;
    void* embedded = Menu_GetRecordSpriteResource(record);
    if (embedded) {
        destination[0xb6] = (unsigned int)embedded;
        unsigned int value = *(unsigned int*)((char*)embedded + 0x3c);
        if (value)
            destination[0xb8] = value;
    }
    GameState_WriteUnknownF70(_ZN9GameState11GetInstanceEv(), 0);
    return 0;
}
