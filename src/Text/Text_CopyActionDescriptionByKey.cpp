#include "globaldefs.h"
#pragma optimize_for_size on
#pragma opt_propagation off
ARM
struct Context{unsigned words[6];}; extern "C" Context* ResourceStringLoader_Initialize(Context*); extern "C" void ResourceStringLoader_Reset(Context*); extern "C" int LoadAndProcessDataWithOptionalBackgroundLoaderLock(char*,const void*,int,int,bool,const void*); extern "C" unsigned char Text_CopyActionDescriptionByKey_PathDataPrmActexpGp2,Text_CopyActionDescriptionByKey_MarkupActexpLGNat;
// Original: arm9/main @ 0x020DD040; symbol: func_020dd040; size: 0x70.
extern "C" void Text_CopyActionDescriptionByKey(int count,char*out){Context context;if(count>0 && out){*out=0;const void*b;const void*a=&Text_CopyActionDescriptionByKey_PathDataPrmActexpGp2;b=&Text_CopyActionDescriptionByKey_MarkupActexpLGNat;ResourceStringLoader_Initialize(&context);ResourceStringLoader_Reset(&context);LoadAndProcessDataWithOptionalBackgroundLoaderLock(out,b,count,0,true,a);}}
