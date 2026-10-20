// Reviewed original ARM field widths and branch behavior. Hardware addresses are original MMIO literals.
#include <World/Zone3DContainers.h>struct HalfCounter{unsigned low:16;unsigned high:16;};struct LowCounter{unsigned low:24;unsigned high:8;};
// Original: arm9/main @ 0x020966A0; symbol: func_020966a0; size: 0x2C.
extern "C" void ZoneContainer_ResetFourRenderParts(char* p){for(int i=0;i<4;++i)((ZoneContainerRenderPart*)(p+i*0x88))->ResetIfFlag0();}
