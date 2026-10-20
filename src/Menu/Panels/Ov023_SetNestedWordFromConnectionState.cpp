#include <globaldefs.h>
extern "C" void* Network_GetConnectionManager();
extern "C" int Network_IsSessionActive(void*);
extern "C" void Script_WriteIntegerReferenceOutput(void*, int);
// Original: arm9/ov023 @ 0x021EA8E8; symbol: func_ov023_021ea8e8; size: 0x38.
extern "C" ARM int Ov023_SetNestedWordFromConnectionState(void* owner) {
    int active = Network_IsSessionActive(Network_GetConnectionManager());
    if (active) {
        Script_WriteIntegerReferenceOutput(owner, 1);
        return 1;
    }
    Script_WriteIntegerReferenceOutput(owner, 0);
    return 1;
}
