#include <globaldefs.h>
// func_02039d68: 0x02039d68–0x02039d7c, arm; 20 bytes
// Original: arm9/main @ 0x02039D68; symbol: func_02039d68; size: 0x14.
extern "C" bool GameObject_IsPartyRenderingSuppressed(int self) {
    return (*(unsigned char*)(self + 0x1ce) & 4) != 0;
}
