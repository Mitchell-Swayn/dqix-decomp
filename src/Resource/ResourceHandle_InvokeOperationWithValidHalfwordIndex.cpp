#include <globaldefs.h>
ARM
extern "C" void ResourceHandle_StartOrDeferSequenceArchiveEntry(void*,int,int,int);
// Original: arm9/main @ 0x0205EBFC; symbol: func_0205ebfc; size: 0x24.
extern "C" void ResourceHandle_InvokeOperationWithValidHalfwordIndex(char* p,int a,int b,int c){int n=*(short*)(p+196);if(n<0)return;ResourceHandle_StartOrDeferSequenceArchiveEntry(p,n,a,b);}
