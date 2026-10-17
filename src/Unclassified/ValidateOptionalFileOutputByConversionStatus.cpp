#include <globaldefs.h>
ARM
extern "C" int ParseRAHCResourceBlock(void*,void**);
// Original: arm9/main @ 0x0205A1F0; symbol: func_0205a1f0; size: 0x44.
extern "C" bool ValidateOptionalFileOutputByConversionStatus(void** out,void* file,int enabled) { if(!out)return true;if(!file)return true;if(!enabled)return true;int result=ParseRAHCResourceBlock(file,out);if(result==0)return true;return false; }
