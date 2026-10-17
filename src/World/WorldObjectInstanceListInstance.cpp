#include "World/WorldObjectInstanceList.h"

extern "C" {
    extern WorldObjectInstanceList data_02109020;

// Original: arm9/main @ 0x0208E9E8; symbol: func_0208e9e8; size: 0xC.
    WorldObjectInstanceList* WorldObjectInstanceList_GetInstance()
    {
        return &data_02109020;
    }
}
