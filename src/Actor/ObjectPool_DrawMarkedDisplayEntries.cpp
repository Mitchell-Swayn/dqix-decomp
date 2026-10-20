#pragma opt_foldconstants off
#include <globaldefs.h>
extern "C" void Object3D_DrawEntryWithOptionalInverseViewTransform(void*,int);
// Original: arm9/main @ 0x02057A6C; symbol: func_02057a6c; size: 0x4C.
extern "C" ARM void ObjectPool_DrawMarkedDisplayEntries(unsigned char* owner){for(int i=0;i<16;++i){unsigned offset=i*212;if(((unsigned)(owner+offset)[212]<<30)>>31)Object3D_DrawEntryWithOptionalInverseViewTransform(owner+8+offset,i+208);}}
