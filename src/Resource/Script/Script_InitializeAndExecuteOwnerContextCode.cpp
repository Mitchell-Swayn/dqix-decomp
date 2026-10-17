#include <globaldefs.h>
#include <Resource/Script.h>
extern "C" {
    extern void *data_02108740[];
    extern Script::OpcodeLookupEntry data_020f051c[];
// Original: arm9/main @ 0x0205E104; symbol: func_0205e104; size: 0x68.
    void Script_InitializeAndExecuteOwnerContextCode(void *p,void *context,void *code,unsigned int len){
        Script script;
        if(p&&code&&len){
            data_02108740[1]=p;
            data_02108740[0]=context;
            script.Initialize();
            script.SetOpcodeLookup(data_020f051c);
            script.Load(code,len);
            script.Execute();
        }
    }
}
