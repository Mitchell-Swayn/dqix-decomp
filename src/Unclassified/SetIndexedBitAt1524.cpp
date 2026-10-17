#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
// Original: arm9/main @ 0x0205E7DC; symbol: func_0205e7dc; size: 0x28.
void SetIndexedBitAt1524(unsigned char *p,unsigned int i){p+=0x1524;p[i>>3]|=1<<((int)i%8);}
}
