#include <globaldefs.h>
extern "C" void* func_ov011_021849c8(void*);
extern "C" unsigned int ReadWordFieldAtOffset1C(void*);
extern "C" void* func_ov023_021f6880(void**, unsigned short);
extern "C" unsigned OV023_ReadHalfwordField04(void*);
extern "C" void* OV023_GetEmbeddedField24(void*);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void GameState_WriteUnknownF70(void*, unsigned char);
// Original: arm9/ov004 @ 0x0216E828; symbol: func_ov004_0216e828; size: 0x6C.
extern "C" ARM int Ov004_ProcessTypeTenEmbeddedObject(void* self) {
    void* object = func_ov011_021849c8(self);
    unsigned int* destination = (unsigned int*)ReadWordFieldAtOffset1C(object);
    void* record = func_ov023_021f6880((void**)object, 10);
    if (!record)
        return 0;
    if (OV023_ReadHalfwordField04(record) != 10)
        return 0;
    void* embedded = OV023_GetEmbeddedField24(record);
    if (embedded) {
        destination[0xb6] = (unsigned int)embedded;
        unsigned int value = *(unsigned int*)((char*)embedded + 0x3c);
        if (value)
            destination[0xb8] = value;
    }
    GameState_WriteUnknownF70(_ZN9GameState11GetInstanceEv(), 0);
    return 0;
}
