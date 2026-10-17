#include <globaldefs.h>
ARM
struct RecordArray;
extern "C" void func_ov015_0218b828(RecordArray*);
extern "C" void _ZN16BackgroundLoader13AddLockGlobalEv();
extern "C" void _ZN16BackgroundLoader16RemoveLockGlobalEv();
extern "C" void _ZN6Script10InitializeEv(void*);
extern "C" void _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(void*,void*);
extern "C" void _ZN6Script4LoadEPKvj(void*,const void*,unsigned);
extern "C" void _ZN6Script7ExecuteEv(void*);
extern "C" void* _Z18LoadFileIntoMemoryPKcPvPj(const char*,void*,unsigned*);
extern "C" char data_0211e33c[];
extern "C" char data_ov015_02193fc8[];
extern "C" void* data_ov015_02194560;
extern "C" char data_ov015_02193fa0[];
// Original: arm9/ov015 @ 0x0218BA44; symbol: func_ov015_0218ba44; size: 0xA4.
extern "C" void Resource_LoadAndExecuteScriptWithOwner(RecordArray* owner,const char* path){
 unsigned char script[0x430];unsigned size;
 func_ov015_0218b828(owner);
 _ZN16BackgroundLoader13AddLockGlobalEv();
 void* code;
 if(path)code=_Z18LoadFileIntoMemoryPKcPvPj(path,data_0211e33c,&size);
 else code=_Z18LoadFileIntoMemoryPKcPvPj(data_ov015_02193fc8,data_0211e33c,&size);
 if(code){
 data_ov015_02194560=owner;
 _ZN6Script10InitializeEv(script);
 _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(script,data_ov015_02193fa0);
 _ZN6Script4LoadEPKvj(script,code,size);
 _ZN6Script7ExecuteEv(script);
 }
 _ZN16BackgroundLoader16RemoveLockGlobalEv();
}
