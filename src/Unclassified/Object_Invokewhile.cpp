#include <globaldefs.h>
ARM
extern "C" int func_020d22f4(int);extern "C" void Sound_UpdateJobCompletionAndCombinedVolume();extern "C" void ResourceTimer_UpdateChangedScaledTime();extern "C" void func_020bed10();extern "C" void func_020d24c4(int);
// Original: arm9/main @ 0x020BBD9C; symbol: func_020bbd9c; size: 0x30.
extern "C" void Object_Invokewhile(){while(func_020d22f4(0)){}Sound_UpdateJobCompletionAndCombinedVolume();ResourceTimer_UpdateChangedScaledTime();func_020bed10();func_020d24c4(0);}
