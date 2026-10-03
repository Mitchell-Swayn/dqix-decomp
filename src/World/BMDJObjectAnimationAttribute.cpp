#include <globaldefs.h>

extern "C" unsigned short func_0202053c(void *object) {
    unsigned char *instance = *reinterpret_cast<unsigned char **>(static_cast<unsigned char *>(object) + 0x150);
    unsigned int index = *reinterpret_cast<unsigned int *>(instance + 0x950);
    return *reinterpret_cast<unsigned short *>(instance + 0x16c + index * 2);
}
