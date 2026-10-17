#include <globaldefs.h>
extern "C" unsigned data_ov000_02184264[];
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned, unsigned);
extern "C" const char* _ZNK6Script9Parameter8ToStringEv(const void*);
extern "C" unsigned strlen(const char*);
extern "C" char* strcpy(char*, const char*);
extern "C" void Overlay_EnqueueLinkedNode(void*);
// Original: arm9/ov000 @ 0x0216AD0C; symbol: func_ov000_0216ad0c; size: 0x70.
extern "C" int Script_CreateTag22RecordFromStringParameter(const void* parameter) {
    char* record = _ZN13SafeAllocator8AllocateEj(data_ov000_02184264[2], 0xc);
    *(unsigned*)record = 0;
    *(unsigned*)(record + 4) = 0;
    *(unsigned*)record = 0x22;
    const char* text = _ZNK6Script9Parameter8ToStringEv(parameter);
    char* copy = _ZN13SafeAllocator8AllocateEj(data_ov000_02184264[2], strlen(text) + 1);
    *(char**)(record + 8) = copy;
    strcpy(copy, text);
    Overlay_EnqueueLinkedNode(record);
    return 1;
}
