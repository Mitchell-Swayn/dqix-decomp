#include <globaldefs.h>
ARM
extern "C" void* GameResources_GetInstance(void);
extern "C" void VectorizedMemset(void*, int, unsigned int);
// Original: arm9/ov004 @ 0x0216342C; symbol: func_ov004_0216342c; size: 0x4C.
extern "C" void func_ov004_0216342c(char* p) {
    char* resources = (char*)GameResources_GetInstance();
    VectorizedMemset(p, 0, 0x1914);
    p[0x18fa] = *(unsigned char*)(resources + 0x4000 + 0x2e0);
    p[0x18fb] = 0;
    p[0x18fc] = 0;
    p[0x18fd] = 0;
    p[0x18fe] = 0;
}
