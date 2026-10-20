#include <globaldefs.h>
ARM
extern "C" char* Pool_AllocateAndLinkNode();
extern "C" char* strcpy(char*, const char*);
// Original: arm9/ov001 @ 0x0215A550; symbol: func_ov001_0215a550; size: 0x44.
extern "C" void Memory_CreateNamedRecord(void* owner, const char* name, unsigned value0, unsigned value1) {
    char* entry = Pool_AllocateAndLinkNode();
    if (entry == 0) return;
    *(unsigned*)entry = 10;
    strcpy(entry + 0x1C, name);
    *(unsigned*)(entry + 0x10) = value0;
    *(unsigned*)(entry + 0x14) = value1;
    *(unsigned*)(entry + 0x18) = 0;
}
