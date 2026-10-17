// Original instruction control flow and relocations reviewed.
extern "C" char* data_02110370[];extern "C" unsigned short data_02108d70[];extern "C" unsigned int data_0210f3c0[];struct Flag{unsigned char enabled:1;unsigned char rest:7;};
// Original: arm9/main @ 0x020BBE94; symbol: func_020bbe94; size: 0x1C.
extern "C" void ResourceManager_ClearGlobalFlagMask(unsigned int mask){data_0210f3c0[0]&=~mask;}
