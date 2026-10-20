#include <globaldefs.h>
extern "C" void BitArray_SetIndexedBoolean(void*,void*,int,int);
// Original: arm9/main @ 0x0206EB64; symbol: func_0206eb64; size: 0x34.
extern "C" ARM void Script_SetRemappedProgressFlag(char* p,int key,int value){if(key>=1024){BitArray_SetIndexedBoolean(p,p+0x8c,key+0x6fa,value);return;}BitArray_SetIndexedBoolean(p,p+0x8c,key,value);}
