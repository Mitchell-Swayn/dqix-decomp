#include <globaldefs.h>
extern "C" void Text_ParseDelimitedSignedIntegerSequence(void*,int*,int);
// Original: arm9/main @ 0x0206B8CC; symbol: func_0206b8cc; size: 0x34.
extern "C" ARM int Text_AddParsedSignedIntegerToOutput(void* p,int* out){int n;Text_ParseDelimitedSignedIntegerSequence(p,&n,1);*out+=n;return 0;}
