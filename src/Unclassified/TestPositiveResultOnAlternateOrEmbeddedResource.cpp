#include <globaldefs.h>
ARM
extern "C" void ResourceManager_ExchangeGlobalValue(void*);extern "C" int ResourceHandle_ComputeScaledCounter(void*);
// Original: arm9/main @ 0x0203ADFC; symbol: func_0203adfc; size: 0x50.
extern "C" bool TestPositiveResultOnAlternateOrEmbeddedResource(char* p,void* q){if(!*(int*)p)return false;ResourceManager_ExchangeGlobalValue(p+4);int n;if(q)n=ResourceHandle_ComputeScaledCounter(q);else n=ResourceHandle_ComputeScaledCounter(p+156);return n>0;}
