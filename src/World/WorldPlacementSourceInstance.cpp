#include "World/WorldPlacementSource.h"

extern "C" WorldPlacementSource data_02108fe4;

// Original: arm9/main @ 0x0208E0A8; symbol: _ZN20WorldPlacementSource11GetInstanceEv; size: 0xC.
WorldPlacementSource* WorldPlacementSource::GetInstance()
{
    return &data_02108fe4;
}
