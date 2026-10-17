#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
#include <Resource/Script.h>
extern "C" {
    extern unsigned int *data_02109ba4;
    extern Script::OpcodeLookupEntry data_020f15e8[];
// Original: arm9/main @ 0x0209A470; symbol: func_0209a470; size: 0x80.
    void Script_Allocate3444ByteBufferAndExecuteCode(unsigned int *p,SafeAllocator *alloc,void *code,unsigned int len){
        Script script;
        void *data=alloc->Allocate(0xd74);
        p[0]=(unsigned int)data;
        if(data){
            data_02109ba4=p;
            script.Initialize();
            script.SetOpcodeLookup(data_020f15e8);
            script.Load(code,len);
            script.Execute();
            data_02109ba4=0;
        }
    }
}
