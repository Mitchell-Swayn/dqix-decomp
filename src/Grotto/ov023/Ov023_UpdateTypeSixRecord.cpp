#include <globaldefs.h>
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void**, unsigned short);
extern "C" unsigned OV023_ReadHalfwordField04(void*);
extern "C" void func_ov023_021f809c(void*, void*);
// Original: arm9/ov023 @ 0x021F6630; symbol: func_ov023_021f6630; size: 0x50.
extern "C" ARM void Ov023_UpdateTypeSixRecord(void* owner, unsigned short id, unsigned short valueA, unsigned short valueB) {
    void** head = (void**)func_ov011_021849c8(owner);
    void* record = func_ov023_021f6880(head, id);
    if (!record || OV023_ReadHalfwordField04(record) != 6) return;
    *(unsigned short*)((char*)record + 0x104) = valueA;
    *(unsigned short*)((char*)record + 0x106) = valueB;
    func_ov023_021f809c(record, owner);
}
