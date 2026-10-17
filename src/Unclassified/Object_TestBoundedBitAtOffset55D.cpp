#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
// Original: arm9/main @ 0x02020084; symbol: func_02020084; size: 0x3C.
bool Object_TestBoundedBitAtOffset55D(unsigned char *p,int i){bool valid;if(i>=0&&i<=3)valid=true;else valid=false;if(valid)return (p[0x55d]&(1<<i))!=0;return false;}
}
