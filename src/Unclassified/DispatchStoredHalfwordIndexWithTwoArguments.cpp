#include <globaldefs.h>
ARM
extern "C" int WriteOrApplyHalfwordFileStatePair(char*,int,int,void*);
// Original: arm9/main @ 0x0205EAA0; symbol: func_0205eaa0; size: 0x1C.
extern "C" void DispatchStoredHalfwordIndexWithTwoArguments(char* p,int a,void* b){WriteOrApplyHalfwordFileStatePair(p,*(short*)(p+0xb4),a,b);}
