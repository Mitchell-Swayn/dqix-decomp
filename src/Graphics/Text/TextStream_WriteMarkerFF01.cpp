#pragma optimization_level 4
#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
// Original: arm9/main @ 0x02069F74; symbol: func_02069f74; size: 0x28.
    int TextStream_WriteMarkerFF01(void **p){
        void *dest=*p;
unsigned short value=0xff01;
        memcpy(dest,&value,2);
        return 2;
    }
}
