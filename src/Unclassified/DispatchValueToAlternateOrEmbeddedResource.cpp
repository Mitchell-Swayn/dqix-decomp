#include <globaldefs.h>
ARM
extern "C" void* ResourceManager_ExchangeGlobalValue(void*);extern "C" void DispatchValueThroughFirstPointer(void*,unsigned);
// Original: arm9/main @ 0x0203ACC8; symbol: func_0203acc8; size: 0x4C.
extern "C" void DispatchValueToAlternateOrEmbeddedResource(unsigned char* p,void* target,unsigned amount){if(!*(void**)p)return;ResourceManager_ExchangeGlobalValue(p+4);if(target){DispatchValueThroughFirstPointer(target,amount);return;}DispatchValueThroughFirstPointer(p+152,amount);}
