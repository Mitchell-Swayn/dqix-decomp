#include <globaldefs.h>
#include <Resource/Script.h>
ARM
extern "C" void _ZN16BackgroundLoader13AddLockGlobalEv();extern "C" void _ZN16BackgroundLoader16RemoveLockGlobalEv();extern "C" const void* ExtractFileFromGP2(const char*,const char*,unsigned*);extern "C" char data_020f1b97[];extern "C" char data_020f1baa[];extern "C" void* data_02109fe0[2];extern "C" Script::OpcodeLookupEntry data_020f1b6c[];
// Original: arm9/main @ 0x020A818C; symbol: func_020a818c; size: 0x8C.
extern "C" void Script_LoadArchiveCodeAndExecuteUnderGlobalLoaderLock(void* a,void* b){_ZN16BackgroundLoader13AddLockGlobalEv();unsigned size=0;const void* code=ExtractFileFromGP2(data_020f1b97,data_020f1baa,&size);if(code){data_02109fe0[0]=b;data_02109fe0[1]=a;Script s;s.Initialize();s.SetOpcodeLookup(data_020f1b6c);s.Load(code,size);s.Execute();}_ZN16BackgroundLoader16RemoveLockGlobalEv();}
