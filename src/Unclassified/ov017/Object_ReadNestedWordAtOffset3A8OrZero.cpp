#include <globaldefs.h>
// Original: arm9/ov017 @ 0x021B1FD4; symbol: func_ov017_021b1fd4; size: 0x14.
extern "C" ARM unsigned int Object_ReadNestedWordAtOffset3A8OrZero(void* object) { unsigned int* value = *(unsigned int**)((char*)object + 0x24); return value ? value[0xe1] : 0; }
