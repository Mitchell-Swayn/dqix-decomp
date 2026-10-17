#include <globaldefs.h>
#include <std_library_functions.h>
#include <GameState/GameState.h>
#include <Memory/SafeAllocator.h>
#include <Resource/Script.h>
extern "C" {
extern void **data_02109ba8;extern Script::OpcodeLookupEntry data_020f1640[];
// Original: arm9/main @ 0x0209A8B4; symbol: func_0209a8b4; size: 0x88.
void AllocateZeroed550ByteScriptState(void **p,SafeAllocator *a,void *code,unsigned int len){Script s;void *data=a->Allocate(0x550);*p=data;if(data){memset(data,0,0x550);data_02109ba8=p;s.Initialize();s.SetOpcodeLookup(data_020f1640);s.Load(code,len);s.Execute();data_02109ba8=0;}}
}
