#include <globaldefs.h>
ARM
extern "C" char* GetLinkedNodeByBoundedIndex(char*, int);
extern "C" int Object_GetSubrecordAtOffset4(int);
extern "C" void* func_ov015_0218f39c(void*, void*);
// Original: arm9/ov015 @ 0x0219011C; symbol: func_ov015_0219011c; size: 0x40.
extern "C" void Object_SetValueOnResolvedLinkedSubrecord(void* object, int value) {
    char* bytes = (char*)object;
    int requestedValue = value;
    char* node = GetLinkedNodeByBoundedIndex(*(char**)bytes + 0x2c4, *(short*)(bytes + 0x38));
    if (!node) return;
    void* subrecord = (void*)Object_GetSubrecordAtOffset4((int)node);
    int* target = (int*)func_ov015_0218f39c(object, subrecord);
    if (target) target[6] = requestedValue;
}
