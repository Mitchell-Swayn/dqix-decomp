#include <globaldefs.h>
extern "C" int Text_ParseDelimitedSignedIntegerSequence(const char*,int*,int);
// Original: arm9/main @ 0x0206B940; symbol: func_0206b940; size: 0x2C.
extern "C" ARM int Text_WriteParsedSignedIntegerToOutput(const char* text,int* out){int value;Text_ParseDelimitedSignedIntegerSequence(text,&value,1);*out=value;return 1;}
