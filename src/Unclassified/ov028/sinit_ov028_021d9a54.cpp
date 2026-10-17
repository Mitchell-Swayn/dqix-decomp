#include <globaldefs.h>
extern "C" { extern unsigned char data_ov028_021d9b14[],data_ov028_021d9ae0[];void* func_ov028_021d977c(void*);void* func_ov028_021d979c(void*);void __register_global_object(void*,void (*)(void*,int),void*); }
#pragma define_section init ".init" RX
// Original: arm9/ov028 @ 0x021D9A54; symbol: __sinit_ov028_021d9a54; size: 0x2C.
extern "C" __declspec(section "init") void __sinit_ov028_021d9a54(){func_ov028_021d977c(data_ov028_021d9b14);__register_global_object(data_ov028_021d9b14,(void(*)(void*,int))func_ov028_021d979c,data_ov028_021d9ae0);}
