#include <globaldefs.h>
extern "C" char data_020f1730[],data_ov032_02200180[];extern "C" void ResourceHandle_AllocateLoadAndReadValue(void*,void*,void*,unsigned,int);
// Original: arm9/main @ 0x0209C290; symbol: func_0209c290; size: 0x28.
extern "C" void ResourceHandle_InitializeFromOverlayDataAnd57000Buffer(void* self) {ResourceHandle_AllocateLoadAndReadValue(self,data_020f1730,data_ov032_02200180,0x57000,1);}
