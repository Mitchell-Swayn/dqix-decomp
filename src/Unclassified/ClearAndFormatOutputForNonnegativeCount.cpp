#include "globaldefs.h"
#pragma optimize_for_size on
#pragma opt_propagation off
ARM
struct Context{unsigned words[6];}; extern "C" Context* Object_ResetEmbeddedStateAndReturnSelf(Context*); extern "C" void ClearRecordAndInvalidateTwoIndices(Context*); extern "C" int LoadAndProcessDataWithOptionalBackgroundLoaderLock(char*,const void*,int,int,bool,const void*); extern "C" unsigned char data_020f29b8,data_020f29cc;
// Original: arm9/main @ 0x020DD0B0; symbol: func_020dd0b0; size: 0x6C.
extern "C" void ClearAndFormatOutputForNonnegativeCount(int count,char*out){Context context;if(count>=0 && out){*out=0;const void*b;const void*a=&data_020f29b8;b=&data_020f29cc;Object_ResetEmbeddedStateAndReturnSelf(&context);ClearRecordAndInvalidateTwoIndices(&context);LoadAndProcessDataWithOptionalBackgroundLoaderLock(out,b,count,0,true,a);}}
