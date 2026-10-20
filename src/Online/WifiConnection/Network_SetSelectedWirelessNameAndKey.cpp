#include <globaldefs.h>
ARM
extern "C" void VectorizedMemset(void* dst, int value, unsigned int length);
extern "C" void MI_CpuCopy8(const void* src, void* dst, unsigned int length);
extern "C" unsigned char* Network_GetConnectionWorkspace(unsigned);
struct Status { unsigned char value : 4; unsigned char high : 4; };
struct Security { unsigned char mode : 2; unsigned char high : 6; };
struct Profile { unsigned char pad[0x40]; unsigned char name[32]; };
// Original: arm9/ov031 @ 0x0221314C; symbol: func_ov031_0221314c; size: 0xB8.
extern "C" void Network_SetSelectedWirelessNameAndKey(const unsigned char *name, const void *key, int mode) {
    Profile *profile = (Profile*)Network_GetConnectionWorkspace(16);
    ((Status*)((unsigned char*)profile + 0xd0c))->value = 1;
    VectorizedMemset(profile, 0, 0xf0);
    int i = 0;
    do {
        unsigned char value = name[i];
        if (!value) break;
        profile->name[i] = value;
        i++;
    } while (i < 32);
    if (!key || !mode) {
        ((Security*)((unsigned char*)profile + 0xe6))->mode = 0;
        return;
    }
    unsigned length;
    if (mode == 1) length = 5;
    else if (mode == 2) length = 13;
    else length = 16;
    MI_CpuCopy8(key,(unsigned char*)profile + 0x80,length);
    ((Security*)((unsigned char*)profile + 0xe6))->mode = (unsigned char)mode;
}
