#include <globaldefs.h>
extern "C" char data_020f1730[],data_ov032_02200180[];extern "C" void ResourceHandle_AllocateLoadAndReadValue(void*,void*,void*,unsigned,int);
// Original: arm9/main @ 0x0209C2B8; symbol: func_0209c2b8; size: 0x28.
extern "C" void LoadFixedOverlayResourceBuffer(void* self) {ResourceHandle_AllocateLoadAndReadValue(self,data_020f1730,data_ov032_02200180,0xa2000,1);}
