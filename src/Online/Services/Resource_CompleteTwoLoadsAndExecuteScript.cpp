#include <globaldefs.h>
ARM
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" unsigned _ZN16BackgroundLoader13GetTaskStatusEi(void*,unsigned);
extern "C" int _ZN16BackgroundLoader21GetDetailedTaskStatusEi(void*,int);
extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(void*,int);
extern "C" void _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(void*,int,void**,unsigned*);
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
extern "C" void* memset(void*,int,unsigned);
extern "C" void _ZN6Script10InitializeEv(void*);
extern "C" void _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(void*,void*);
extern "C" void _ZN6Script4LoadEPKvj(void*,const void*,unsigned);
extern "C" void _ZN6Script7ExecuteEv(void*);
// Original data: arm9/ov031 @ 0x2291e04; symbol: data_ov031_02291e04.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 56 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char ScriptSetIndexedNetworkWord_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov031 @ 0x224c8dc; symbol: data_ov031_0224c8dc.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 640000000830240265000000103024026600000044312402670000001830240268000000003324020000000000000000.
// Observed span: 48 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char ResourceCompleteTwoLoadsAndExecuteScript_UnknownRoleProcedureReferenceRecords[];
// Original: arm9/ov031 @ 0x02243714; symbol: func_ov031_02243714; size: 0x13C.
extern "C" int Resource_CompleteTwoLoadsAndExecuteScript(unsigned char* self) {
 void* loader=_ZN16BackgroundLoader11GetInstanceEv();
 if(!_ZN16BackgroundLoader13GetTaskStatusEi(loader,*(unsigned*)(self+0x39c)) || !_ZN16BackgroundLoader13GetTaskStatusEi(loader,*(unsigned*)(self+0x3a0))) return 3;
 if(_ZN16BackgroundLoader21GetDetailedTaskStatusEi(loader,*(int*)(self+0x39c))!=2) {
  _ZN16BackgroundLoader10RemoveTaskEi(loader,*(int*)(self+0x39c));return 2;
 }
 if(_ZN16BackgroundLoader21GetDetailedTaskStatusEi(loader,*(int*)(self+0x3a0))!=2) {
  _ZN16BackgroundLoader10RemoveTaskEi(loader,*(int*)(self+0x3a0));return 2;
 }
 void* file;unsigned size;
 _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,*(int*)(self+0x39c),&file,&size);
 *(void**)(self+0x388)=file;
 *(unsigned*)(self+0x38c)=size;
 void* buffer=_ZN13SafeAllocator8AllocateEj((unsigned)self,0x38);
 *(void**)(ScriptSetIndexedNetworkWord_UnknownRoleZeroInitializedStorage+0x28)=buffer;
 if(!buffer)return 2;
 memset(buffer,0,0x38);
 _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,*(int*)(self+0x3a0),&file,&size);
 unsigned char script[0x430];
 _ZN6Script10InitializeEv(script);
 _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(script,ResourceCompleteTwoLoadsAndExecuteScript_UnknownRoleProcedureReferenceRecords);
 _ZN6Script4LoadEPKvj(script,file,size);
 _ZN6Script7ExecuteEv(script);
 return 1;
}
