#include <globaldefs.h>
ARM
extern "C" void* GameResources_GetInstance(void);
extern "C" void* GetPrimaryLinkedRecordByIndex(unsigned, unsigned);
extern "C" void func_ov017_0219230c(void*, unsigned, int);
// Original: arm9/ov025 @ 0x021E8638; symbol: func_ov025_021e8638; size: 0x38.
extern "C" int Resource_ApplyLinkedRecordParameter(char* self, unsigned index) {
    void* resources = GameResources_GetInstance();
    void* record = GetPrimaryLinkedRecordByIndex(index, 0);
    func_ov017_0219230c(resources, *(unsigned short*)((char*)record + 0x20), *(signed char*)(self + 8));
    return 1;
}
