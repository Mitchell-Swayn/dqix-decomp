#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
    extern void *data_02111804;
    void LinkedList_RemoveNodeByIdentityWithIRQGuard(void **,void *);
// Original: arm9/main @ 0x020CEF64; symbol: func_020cef64; size: 0x18.
    void LinkedList_RemoveFromGlobalWord2111804ListAtomically(void *p){
        LinkedList_RemoveNodeByIdentityWithIRQGuard(&data_02111804,p);
    }
}
