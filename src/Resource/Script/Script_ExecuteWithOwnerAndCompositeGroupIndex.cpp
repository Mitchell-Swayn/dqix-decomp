#include <globaldefs.h>
#include <Resource/Script.h>
struct Context {unsigned owner;short id;unsigned short arg;unsigned active;};
extern "C" {extern Context *data_02109bc8;extern Script::OpcodeLookupEntry data_020f16f8[];}
// Original: arm9/main @ 0x0209C008; symbol: func_0209c008; size: 0x84.
extern "C" ARM void Script_ExecuteWithOwnerAndCompositeGroupIndex(unsigned owner,const void *code,unsigned size,unsigned short arg,int group,int index){ Script script;Context ctx;ctx.owner=owner;ctx.id=(short)(group*100+index);ctx.arg=arg;ctx.active=1;data_02109bc8=&ctx;script.Initialize();script.SetOpcodeLookup(data_020f16f8);script.Load(code,size);script.Execute();}
