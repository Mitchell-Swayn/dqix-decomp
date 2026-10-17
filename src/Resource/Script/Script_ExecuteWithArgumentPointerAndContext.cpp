#include <globaldefs.h>
#include <Resource/Script.h>
ARM
extern "C" {
extern unsigned int data_021098e0[];
extern Script::OpcodeLookupEntry data_020f14dc[];
// Original: arm9/main @ 0x02097AC0; symbol: func_02097ac0; size: 0x74.
void Script_ExecuteWithArgumentPointerAndContext(unsigned int context, unsigned int arg, void *code, unsigned int length) {
    if (code && length) {
        data_021098e0[1] = context;
        data_021098e0[0] = (unsigned int)&arg;
        Script script;
        script.Initialize(); script.SetOpcodeLookup(data_020f14dc); script.Load(code,length); script.Execute();
    }
}
}
