#include <globaldefs.h>
ARM
extern "C" int NNS_G2dGetUnpackedCharacterData(void*,void**);
// Original: arm9/main @ 0x0205A1F0; symbol: func_0205a1f0; size: 0x44.
extern "C" bool Graphics_TestOptionalCharacterBlockUnavailable(void** out,void* file,int enabled) { if(!out)return true;if(!file)return true;if(!enabled)return true;int result=NNS_G2dGetUnpackedCharacterData(file,out);if(result==0)return true;return false; }
