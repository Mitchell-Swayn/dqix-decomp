#include <globaldefs.h>
#include <GameState/GameState.h>

extern "C" ARM void* memset(void*, int, unsigned);
// Original: arm9/ov003 @ 0x02174408; symbol: func_ov003_02174408; size: 0x4C.
extern "C" ARM void Shop_ResetStockAndPricingConfiguration(void* entry) {
    *((unsigned char*)entry)=0x63; *((unsigned char*)entry+1)=0;
    memset((char*)entry+2,0,0x12); memset((char*)entry+0x14,-1,0x24);
    *(unsigned short*)((char*)entry+0x38)=0x64; *(unsigned short*)((char*)entry+0x3a)=0;
    *((unsigned char*)entry+0x3c)=0;
}
