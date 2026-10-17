#include <globaldefs.h>
ARM
extern "C" void* GameResources_GetInstance();
// Original: arm9/ov002 @ 0x0215A878; symbol: func_ov002_0215a878; size: 0x54.
extern "C" void Resource_CopySignedHalfwordsToSharedObject(void* object) {
    *(int*)((char*)object + 0x2540) = *(short*)((char*)object + 0x1be0);
    *(int*)((char*)object + 0x2544) = *(short*)((char*)object + 0x1bfe);
    *(unsigned char*)((char*)object + 0x253c) = 1;
    char* shared = *(char**)((char*)GameResources_GetInstance() + 0x371c);
    shared[0x24] = *(unsigned char*)((char*)object + 0x253c);
    *(int*)(shared + 0x28) = *(int*)((char*)object + 0x2540);
    *(int*)(shared + 0x2c) = *(int*)((char*)object + 0x2544);
}
