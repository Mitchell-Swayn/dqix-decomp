#include <globaldefs.h>
struct Dimensions { char pad[0x17];unsigned char a,b; };
// Original: arm9/main @ 0x020B2A6C; symbol: func_020b2a6c; size: 0x60.
extern "C" unsigned ComputeAlignedResourceSizeByKind(const unsigned char* kind,const Dimensions* data) {if(!kind||!data)return 0;switch(*kind){case 77:return(data->b*2+28)&~3;case 74:case 86:return(data->a*2+28)&~3;default:return 0;}}
