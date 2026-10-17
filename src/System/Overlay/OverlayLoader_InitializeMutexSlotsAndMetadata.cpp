#include <globaldefs.h>
extern "C" void _Z19ZeroInitializeMutexP5Mutex(void*);extern "C" void FillSixWordsWithMinusOne(void*);extern "C" void _Z19LoadOverlayMetadataP15OverlayMetadatabj(void*,bool,unsigned);extern "C" char data_01ffd34c[],data_01ffd364[],data_01ffd394[];extern "C" char data_01ffd344,data_01ffd340;extern "C" int data_01ffd348;
// Original: arm9/main @ 0x020A1838; symbol: func_020a1838; size: 0x9C.
extern "C" ARM void OverlayLoader_InitializeMutexSlotsAndMetadata(){_Z19ZeroInitializeMutexP5Mutex(data_01ffd34c);data_01ffd344=1;data_01ffd340=0;for(unsigned i=0;i<8;++i)FillSixWordsWithMinusOne(data_01ffd364+6*i);for(unsigned i=0;i<35;++i)_Z19LoadOverlayMetadataP15OverlayMetadatabj(data_01ffd394+44*i,false,i);data_01ffd348=0;}
