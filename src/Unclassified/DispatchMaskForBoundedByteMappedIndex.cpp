#include <globaldefs.h>
ARM
#pragma optimize_for_size off
extern "C" void SubmitOperationCodeTwentyOne(unsigned,unsigned);
// Original: arm9/main @ 0x020BCC4C; symbol: func_020bcc4c; size: 0x30.
extern "C" void DispatchMaskForBoundedByteMappedIndex(char* p,int index,unsigned value){if(index>*(int*)(p+72)-1)return;SubmitOperationCodeTwentyOne(1u<<((unsigned char*)(p+index))[76],value);}
