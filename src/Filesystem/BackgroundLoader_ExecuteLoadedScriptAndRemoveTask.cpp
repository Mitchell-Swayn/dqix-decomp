#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x20f13fc; symbol: data_020f13fc.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 64000000784d090265000000804d090266000000645309020000000000000000.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2109404; symbol: data_02109404.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();extern "C" int _ZN16BackgroundLoader13GetTaskStatusEi(void*,int);extern "C" void _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(void*,int,void**,unsigned*);extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(void*,int);extern "C" void _ZN6Script10InitializeEv(void*);extern "C" void _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(void*,void*);extern "C" void _ZN6Script4LoadEPKvj(void*,void*,unsigned);extern "C" void _ZN6Script7ExecuteEv(void*);extern "C" char ScriptQueuePackedTimedRecord_UnknownRoleZeroInitializedStorage[],ScriptExecuteRequestedCountAndReturnResult_UnknownRoleProcedureReferenceRecords[];
// Original: arm9/main @ 0x02095EE0; symbol: func_02095ee0; size: 0x110.
extern "C" int BackgroundLoader_ExecuteLoadedScriptAndRemoveTask(char* p,unsigned a,unsigned b,unsigned c){void* file;unsigned size;char script[1072];void* loader=_ZN16BackgroundLoader11GetInstanceEv();if(*(int*)(p+1220)<0)return -1;if(_ZN16BackgroundLoader13GetTaskStatusEi(loader,*(int*)(p+1220))){_ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,*(int*)(p+1220),&file,&size);*(short*)(ScriptQueuePackedTimedRecord_UnknownRoleZeroInitializedStorage+6)=0;ScriptQueuePackedTimedRecord_UnknownRoleZeroInitializedStorage[1]=0;if(!*(int*)(p+168)){_ZN16BackgroundLoader10RemoveTaskEi(loader,*(int*)(p+1220));*(int*)(p+1220)=-1;return 2;}_ZN6Script10InitializeEv(script);_ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(script,ScriptExecuteRequestedCountAndReturnResult_UnknownRoleProcedureReferenceRecords);_ZN6Script4LoadEPKvj(script,file,size);_ZN6Script7ExecuteEv(script);_ZN16BackgroundLoader10RemoveTaskEi(loader,*(int*)(p+1220));*(int*)(p+1220)=-1;for(int i=0;i<*(unsigned short*)(ScriptQueuePackedTimedRecord_UnknownRoleZeroInitializedStorage+6);i++){}return 1;}return _ZN16BackgroundLoader13GetTaskStatusEi(loader,*(int*)(p+1220))==-1?2:0;}
