#include <globaldefs.h>
extern "C" void _Z33VerifyOtherDMATimingCompatibilityij(int,unsigned);extern "C" void _Z15VerifyDMASourceijjj(int,unsigned,unsigned,unsigned);extern "C" void _Z26ConfigureDMATransferAtomicijjj(int,unsigned,unsigned,unsigned);
// Original: arm9/main @ 0x020CA8E8; symbol: func_020ca8e8; size: 0x74.
extern "C" ARM void DMA_StartCartridgeWordTransferAfterIdle(int dma,unsigned src,unsigned dest,unsigned count){_Z33VerifyOtherDMATimingCompatibilityij(dma,-1);_Z15VerifyDMASourceijjj(dma,src,count,0x1000000);if(!count)return;volatile unsigned* control=(volatile unsigned*)(0x40000b0+(dma*3+2)*4);while(*control&0x80000000){} _Z26ConfigureDMATransferAtomicijjj(dma,src,dest,0xaf000001);}
