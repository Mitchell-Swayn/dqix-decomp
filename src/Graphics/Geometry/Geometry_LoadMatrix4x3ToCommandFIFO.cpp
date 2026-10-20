#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void GX_SendFifo48B(const void*,void*);
// Original: arm9/main @ 0x020C5188; symbol: func_020c5188; size: 0x1C.
extern "C" void Geometry_LoadMatrix4x3ToCommandFIFO(const void* source){volatile unsigned* fifo=(volatile unsigned*)0x04000400;*fifo=23;GX_SendFifo48B(source,(void*)fifo);}
