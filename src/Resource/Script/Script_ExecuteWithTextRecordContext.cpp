#include <globaldefs.h>
#include <Resource/Script.h>
struct Context{unsigned pad[2],value;short first;unsigned short second;};struct Global{void* owner;Context* context;};extern "C" Global data_02108fc0;extern "C" Script::OpcodeLookupEntry data_020f121c[];
// Original: arm9/main @ 0x0208D860; symbol: func_0208d860; size: 0x8C.
extern "C" ARM void Script_ExecuteWithTextRecordContext(Context* context,void*owner,const void*code,unsigned len,unsigned value,short first,unsigned short second){Script script;if(owner&&code&&len){Global*g=&data_02108fc0;g->context=context;context->value=value;g->context->first=first;g->context->second=second;g->owner=owner;script.Initialize();script.SetOpcodeLookup(data_020f121c);script.Load(code,len);script.Execute();}}
