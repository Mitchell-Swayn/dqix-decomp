#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
    extern unsigned char data_021117ec[];
// Original: arm9/main @ 0x020CE240; symbol: func_020ce240; size: 0x30.
    void IPC_ClearPendingAndInvokeCompletionCallback(void *arg){
        void (*callback)(void *,int)=*(void (**)(void *,int))(data_021117ec+32);
        int value=*(int *)(data_021117ec+36);
        *(int *)(data_021117ec+28)=0;
        if(!callback)return;
        *(int *)(data_021117ec+32)=0;
        callback(arg,value);
    }
}
