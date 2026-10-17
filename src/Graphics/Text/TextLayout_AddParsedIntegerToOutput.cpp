#include <globaldefs.h>
extern "C" void Text_ParseDelimitedSignedIntegerSequence(void*,int*,int);
// Original: arm9/main @ 0x0206B900; symbol: func_0206b900; size: 0x34.
extern "C" ARM int TextLayout_AddParsedIntegerToOutput(void* p,int* out){int n;Text_ParseDelimitedSignedIntegerSequence(p,&n,1);*out+=n;return 0;}
