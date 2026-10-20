#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x0205E804; symbol: func_0205e804; size: 0x2C.
extern "C" void Network_DisableIncomingRecordType(unsigned char* p,unsigned index){(p+0x1524)[index>>3]&=~(1<<(int(index)%8));}
