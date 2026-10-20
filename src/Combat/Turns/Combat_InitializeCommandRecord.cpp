#include <globaldefs.h>
extern "C" void* memset(void*,int,unsigned int);
// Original: arm9/ov000 @ 0x02160030; symbol: func_ov000_02160030; size: 0x38.
// Layout projection only; broader object ownership remains unclassified.
extern "C" ARM void Combat_InitializeCommandRecord(unsigned char* p) {
 memset(p,0,40); *(short*)(p+6)=-1; memset(p+24,0,14); *(unsigned short*)(p+36)=0;
}
