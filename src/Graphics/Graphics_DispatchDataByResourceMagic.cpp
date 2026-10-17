#include <globaldefs.h>
ARM
#include <std_library_functions.h>
extern "C" {extern char data_020f0504[],data_020f0509[],data_020f050e[],data_020f0513[];void __clear(void*,int);int RuntimeMemory_CompareByteRanges(const void*,const void*,unsigned int);int Graphics_LoadKBECResource(int,void*,int,int);int func_0205a984(int,void*,int,int);int CreateResourceByModeAndKind(int,void*,int);int LoadOptionalResourcePaletteWithMappingAndBankSelection(int,void*,int);
// Original: arm9/main @ 0x0205A528; symbol: func_0205a528; size: 0x130.
int Graphics_DispatchDataByResourceMagic(int a,void* data,int b,int c){char tag[8];__clear(tag,5);memcpy(tag,data,4);if(!RuntimeMemory_CompareByteRanges(tag,data_020f0504,4)&&Graphics_LoadKBECResource(a,data,b,c))return 1;if(!RuntimeMemory_CompareByteRanges(tag,data_020f0509,4)){if(func_0205a984(a,data,b,c))return 1;}else if(!RuntimeMemory_CompareByteRanges(tag,data_020f050e,4)){if(CreateResourceByModeAndKind(a,data,b))return 1;}else if(!RuntimeMemory_CompareByteRanges(tag,data_020f0513,4)&&LoadOptionalResourcePaletteWithMappingAndBankSelection(a,data,b))return 1;return 0;}}
