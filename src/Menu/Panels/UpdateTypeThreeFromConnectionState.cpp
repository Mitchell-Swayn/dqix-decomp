#include <globaldefs.h>
ARM
extern "C" void *Network_GetConnectionManager(void);
extern "C" bool Network_IsClientSession(unsigned int *);
extern "C" void Script_WriteIntegerReferenceOutput(void *, int);
// Original: arm9/ov023 @ 0x021EA920; symbol: func_ov023_021ea920; size: 0x38.
extern "C" int UpdateTypeThreeFromConnectionState(void *object) {
    unsigned int *state = (unsigned int *)Network_GetConnectionManager();
    if (Network_IsClientSession(state)) {
        Script_WriteIntegerReferenceOutput(object, 1);
    } else {
        Script_WriteIntegerReferenceOutput(object, 0);
    }
    return 1;
}
