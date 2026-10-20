#pragma optimization_level 4
#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
// Original: arm9/main @ 0x02069790; symbol: func_02069790; size: 0x28.
    int TextStream_WriteMarkerFF0D(void **p){
        void *dest=*p;
unsigned short value=0xff0d;
        memcpy(dest,&value,2);
        return 2;
    }
}
