#include <globaldefs.h>
extern "C" {
    void ResourceStringLoader_Reset(void *);
// Original: arm9/main @ 0x020DFC2C; symbol: func_020dfc2c; size: 0x14.
    void *ResourceStringLoader_Initialize(void *p){
        ResourceStringLoader_Reset(p);
        return p;
    }
}
