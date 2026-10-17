#include <globaldefs.h>
ARM
extern "C" void* data_ov000_02184264[3];
extern "C" char* _ZN13SafeAllocator8AllocateEj(void*, unsigned);
extern "C" const char* _ZNK6Script9Parameter8ToStringEv(const void*);
extern "C" unsigned strlen(const char*);
extern "C" char* strcpy(char*, const char*);
extern "C" void Overlay_EnqueueLinkedNode(void*);
// Original: arm9/ov000 @ 0x0216B394; symbol: func_ov000_0216b394; size: 0x74.
extern "C" int CreateAllocatedStringParameterRecord(const void* parameter) {
    char* record = _ZN13SafeAllocator8AllocateEj(data_ov000_02184264[2], 12);
    *(unsigned*)record = 0;
    *(unsigned*)(record + 4) = 0;
    *(unsigned*)record = 0x33;
    const char* value = _ZNK6Script9Parameter8ToStringEv(parameter);
    if (value) {
        unsigned length = strlen(value) + 1;
        char* copy = _ZN13SafeAllocator8AllocateEj(data_ov000_02184264[2], length);
        *(char**)(record + 8) = copy;
        strcpy(copy, value);
    }
    Overlay_EnqueueLinkedNode(record);
    return 1;
}
