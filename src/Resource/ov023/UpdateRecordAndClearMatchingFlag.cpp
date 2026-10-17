#include <globaldefs.h>
ARM
extern "C" void* func_ov023_021f6880(void**, unsigned short);
extern "C" void* OV023_GetEmbeddedField24(void*);
extern "C" void func_ov023_021f6c3c(void*, unsigned, unsigned, unsigned);
extern "C" void* FindRecordPointerByKey(void*, unsigned);
// Original: arm9/ov023 @ 0x021FB364; symbol: func_ov023_021fb364; size: 0x64.
extern "C" void UpdateRecordAndClearMatchingFlag(void* state, void* list) {
    void* node = func_ov023_021f6880((void**)list, *(unsigned short*)((char*)state + 0x20));
    if (node == 0) return;
    unsigned char* embedded = (unsigned char*)OV023_GetEmbeddedField24(node);
    func_ov023_021f6c3c(list, embedded[0x50], *(unsigned short*)((char*)state + 0x24), 1);
    void* records = *(void**)(embedded + 0x3c);
    if (records == 0) return;
    void* record = FindRecordPointerByKey(records, *(unsigned short*)((char*)state + 0x22));
    if (record != 0) *(unsigned char*)((char*)record + 0x15) &= ~8;
}
