#include <World/WorldPlacementSource.h>
extern "C" WorldPlacementSource data_02108fe4;
extern "C" WorldPlacementSource *_ZN20WorldPlacementSourceC1Ev(WorldPlacementSource *);
// Original: arm9/main @ 0x020E62A0; symbol: __sinit_020e62a0; size: 0x14.
// Initializes the placement-source singleton by calling its existing constructor.
#pragma define_section init ".init" RX
extern "C" __declspec(section "init") void WorldPlacementSource_InitializeSingleton() { _ZN20WorldPlacementSourceC1Ev(&data_02108fe4); }
