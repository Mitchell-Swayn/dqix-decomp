#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x0203E5D8; symbol: func_0203e5d8; size: 0x4C.
extern "C" void SetVisibilityFlagForThirtyTwoChildObjects(unsigned char* p,int visible){void** entries=(void**)(p+12);for(int i=0;i<32;++i,++entries){unsigned char* q=(unsigned char*)*entries;if(q){unsigned char* obj=*(unsigned char**)(q+20);if(obj){if(visible)*(unsigned*)(obj+80)&=~16U;else *(unsigned*)(obj+80)|=16;}}}}
