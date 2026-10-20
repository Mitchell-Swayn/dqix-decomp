#include "globaldefs.h"
#pragma optimize_for_size on
#pragma opt_propagation off
ARM
struct Context{unsigned words[6];}; extern "C" Context* ResourceStringLoader_Initialize(Context*); extern "C" void ResourceStringLoader_Reset(Context*); extern "C" int LoadAndProcessDataWithOptionalBackgroundLoaderLock(char*,const void*,int,int,bool,const void*); extern "C" unsigned char Text_CopyBattleStringByKey_PathDataBinStrbtlGp2,Text_CopyBattleStringByKey_MarkupStrbtlLGNat;
// Original: arm9/main @ 0x020DD0B0; symbol: func_020dd0b0; size: 0x6C.
extern "C" void Text_CopyBattleStringByKey(int count,char*out){Context context;if(count>=0 && out){*out=0;const void*b;const void*a=&Text_CopyBattleStringByKey_PathDataBinStrbtlGp2;b=&Text_CopyBattleStringByKey_MarkupStrbtlLGNat;ResourceStringLoader_Initialize(&context);ResourceStringLoader_Reset(&context);LoadAndProcessDataWithOptionalBackgroundLoaderLock(out,b,count,0,true,a);}}
