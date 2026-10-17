#include <globaldefs.h>
ARM
extern "C" void WriteOrApplyHalfwordFileStatePair(void*,int,int,int);
// Original: arm9/main @ 0x0205EBFC; symbol: func_0205ebfc; size: 0x24.
extern "C" void ResourceHandle_InvokeOperationWithValidHalfwordIndex(char* p,int a,int b,int c){int n=*(short*)(p+196);if(n<0)return;WriteOrApplyHalfwordFileStatePair(p,n,a,b);}
