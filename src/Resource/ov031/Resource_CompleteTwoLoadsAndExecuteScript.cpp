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
extern "C" unsigned char data_ov031_02291e04[];
extern "C" unsigned char data_ov031_0224c8dc[];
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
 *(void**)(data_ov031_02291e04+0x28)=buffer;
 if(!buffer)return 2;
 memset(buffer,0,0x38);
 _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,*(int*)(self+0x3a0),&file,&size);
 unsigned char script[0x430];
 _ZN6Script10InitializeEv(script);
 _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(script,data_ov031_0224c8dc);
 _ZN6Script4LoadEPKvj(script,file,size);
 _ZN6Script7ExecuteEv(script);
 return 1;
}
