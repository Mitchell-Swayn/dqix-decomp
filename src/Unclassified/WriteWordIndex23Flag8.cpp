#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
// Original: arm9/main @ 0x0203CEC4; symbol: func_0203cec4; size: 0x18.
void WriteWordIndex23Flag8(unsigned int *p,int v){unsigned int f;if(v)f=p[23]|8;else f=p[23]&~8;p[23]=f;}
}
