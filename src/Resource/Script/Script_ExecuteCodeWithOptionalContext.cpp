#include <globaldefs.h>
#include <Resource/Script.h>
extern "C" {
    extern void *data_02108ed8[];
    extern Script::OpcodeLookupEntry data_020f0f88[];
// Original: arm9/main @ 0x0207EF74; symbol: func_0207ef74; size: 0x68.
    void Script_ExecuteCodeWithOptionalContext(void *p,void *context,void *code,unsigned int len){
        Script script;
        if(context&&code&&len){
            data_02108ed8[1]=p;
            data_02108ed8[0]=context;
            script.Initialize();
            script.SetOpcodeLookup(data_020f0f88);
            script.Load(code,len);
            script.Execute();
        }
    }
}
