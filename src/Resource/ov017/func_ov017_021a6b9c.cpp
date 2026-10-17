#include <globaldefs.h>
ARM
extern "C" void* GameResources_GetInstance(void);
extern "C" void func_ov017_021a6be4(void*);
extern "C" void AppendLinkedNodeAndMarkActive(unsigned int*, unsigned int);
// Original: arm9/ov017 @ 0x021A6B9C; symbol: func_ov017_021a6b9c; size: 0x48.
extern "C" void func_ov017_021a6b9c(void* unused, unsigned char type) {
    char* resources = (char*)GameResources_GetInstance();
    unsigned int* head = *(unsigned int**)(resources + 0x36fc);
    char* node = *(char**)(resources + 0x3b90);
    func_ov017_021a6be4(node);
    node[0x10] = type;
    AppendLinkedNodeAndMarkActive(head, (unsigned int)node);
    *(unsigned short*)(resources + 0x44ae) = 0;
    *(unsigned short*)(resources + 0x44b0) = 0;
}
