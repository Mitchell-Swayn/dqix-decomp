#include <globaldefs.h>
ARM
#include <Resource/Script.h>
struct State {unsigned char enabled,pad;unsigned short mode;unsigned arg;unsigned* value;unsigned result,owner;};extern "C" State data_02108db0;extern "C" Script::OpcodeLookupEntry data_020f0cc8[];
// Original: arm9/main @ 0x02072928; symbol: func_02072928; size: 0x8C.
extern "C" void Script_ExecuteCodeWithOwnerModeAndOutputValue(unsigned owner,void* code,unsigned size,unsigned value,unsigned arg,unsigned char enabled) {Script script;data_02108db0.owner=owner;data_02108db0.result=0;data_02108db0.value=&value;data_02108db0.mode=1;data_02108db0.arg=arg;data_02108db0.enabled=enabled;script.Initialize();script.SetOpcodeLookup(data_020f0cc8);script.Load(code,size);script.Execute(); }
