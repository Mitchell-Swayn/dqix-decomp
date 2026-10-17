#include <globaldefs.h>
#pragma optimize_for_size on
#include "Resource/Script.h"
struct ScriptContext {unsigned owner,a,b,c,enabled,count,reserved;};
extern "C" ScriptContext* data_02109bb0;
extern "C" Script::OpcodeLookupEntry data_020f16c0[];
// Original: arm9/main @ 0x0209BC98; symbol: func_0209bc98; size: 0xA0.
extern "C" ARM void Script_ExecuteWithTemporaryEnabledContext(unsigned owner,const void* code,unsigned size,unsigned unused,unsigned a,unsigned b,unsigned c)
{
    if (!code) return;
    ScriptContext context;
    data_02109bb0=&context;
    data_02109bb0->owner=owner;
    data_02109bb0->a=a;
    data_02109bb0->b=b;
    data_02109bb0->c=c;
    data_02109bb0->enabled=1;
    data_02109bb0->count=0;
    Script script;
    script.Initialize();script.SetOpcodeLookup(data_020f16c0);
    script.Load(code,size);script.Execute();
}
