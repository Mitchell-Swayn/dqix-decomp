#pragma optimization_level 4
#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
// Original: arm9/main @ 0x02069E0C; symbol: func_02069e0c; size: 0x28.
    int TextStream_WriteMarkerFF02(void **p){
        void *dest=*p;
unsigned short value=0xff02;
        memcpy(dest,&value,2);
        return 2;
    }
}
