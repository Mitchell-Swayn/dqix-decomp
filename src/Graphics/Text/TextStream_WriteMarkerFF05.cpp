#pragma optimization_level 4
#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
// Original: arm9/main @ 0x02069B0C; symbol: func_02069b0c; size: 0x28.
    int TextStream_WriteMarkerFF05(void **p){
        void *dest=*p;
unsigned short value=0xff05;
        memcpy(dest,&value,2);
        return 2;
    }
}
