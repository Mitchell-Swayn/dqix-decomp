#include <globaldefs.h>
#include <std_library_functions.h>
ARM
#pragma optimization_level 4
extern "C" {
    typedef void (*Callback)(const void *,unsigned int,unsigned int);
// Original: arm9/main @ 0x0204ADB4; symbol: func_0204adb4; size: 0x34.
    void Graphics_CopyPayloadLengthAndInvokeTransferCallback(unsigned char *p,Callback callback,unsigned char *data){
        memcpy(p+8,data+12,4);
        callback(data+16,0,*(unsigned int *)(p+8));
    }
}
