#include <globaldefs.h>

extern "C" void GameObject_InitializePartyFollowAndLadderState(unsigned short*);

// Original: arm9/main @ 0x02048104; symbol: func_02048104; size: 0x1C.
extern "C" ARM void GameObject_InitializeWithFlag200(unsigned short* object) {
    GameObject_InitializePartyFollowAndLadderState(object);
    *object |= 0x200;
}
