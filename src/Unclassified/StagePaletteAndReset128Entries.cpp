#include <globaldefs.h>
extern "C" unsigned data_021077fc;extern "C" char data_020e7af8[];extern "C" void _Z17StageMemoryToVRAM13VRAMSubregionPKvjjbb(unsigned,const void*,unsigned,unsigned,bool,bool);extern "C" void Object3D_InitializeExtendedAnimationWrapper(void*);extern "C" void func_020439b0(void*,int);
// Original: arm9/main @ 0x020432C4; symbol: func_020432c4; size: 0xA4.
extern "C" ARM void StagePaletteAndReset128Entries(char* object){char* descriptor=*(char**)(object+0x1e28);if(descriptor)data_021077fc=(*(unsigned*)(descriptor+0x68)<<16)>>13;_Z17StageMemoryToVRAM13VRAMSubregionPKvjjbb(0,data_020e7af8,data_021077fc,32,true,true);for(int i=0;i<128;++i){Object3D_InitializeExtendedAnimationWrapper(object+0x9b8+i*28);(object+i)[0x17b8]=0;}func_020439b0(object,0);}
