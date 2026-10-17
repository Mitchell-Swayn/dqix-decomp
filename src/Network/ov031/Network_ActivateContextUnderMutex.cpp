#include <globaldefs.h>
ARM
extern "C" { extern int data_ov031_02290fc0; int AllocateCircularListNodeAndReturnId(void*); void System_LockGlobalMutex(); void func_ov031_02240324(); int func_ov031_022403f4(); }
// Original: arm9/ov031 @ 0x02240EE8; symbol: func_ov031_02240ee8; size: 0x8C.
extern "C" int Network_ActivateContextUnderMutex(unsigned char* context) {
 if(*(int*)context) { data_ov031_02290fc0=11; return -1; }
 if(*(int*)(context+0x40)==1 && !*(int*)(context+0x38)) { data_ov031_02290fc0=11; return -1; }
 System_LockGlobalMutex();
 int result=AllocateCircularListNodeAndReturnId(context);
 if(result>=0) { *(int*)context=1; func_ov031_022403f4(); }
 else data_ov031_02290fc0=1;
 func_ov031_02240324();
 return result;
}
