#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021F71A8; symbol: func_021f71a8; size: 0xE8.
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv(); extern "C" unsigned Menu_GetBackgroundLoadTicket(void*); extern "C" unsigned _ZN16BackgroundLoader13GetTaskStatusEi(void*,unsigned); extern "C" unsigned _ZN16BackgroundLoader21GetDetailedTaskStatusEi(void*,unsigned); extern "C" void _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(void*,unsigned,void**,unsigned*);
extern "C" int _Z13GetFileInNarcPKvPKcPS0_Pjj(const void*,const char*,void**,unsigned*,unsigned); extern "C" void* ResourceFile_FindNamedPayloadAndSize(void*,const char*,unsigned*); extern "C" void World_LoadZoneRenderPartWithSavedVram(char*,void*,const void*,int);
extern "C" void World_LoadZoneResourceAfterBackgroundTask(void *self,void *state) {
 unsigned char *p=(unsigned char*)self; void *loader=_ZN16BackgroundLoader11GetInstanceEv(); int id=(int)Menu_GetBackgroundLoadTicket(state); if(id<0 || !_ZN16BackgroundLoader13GetTaskStatusEi(loader,id) || _ZN16BackgroundLoader21GetDetailedTaskStatusEi(loader,id)!=2) return;
 void *file; unsigned fileSize; void *data; unsigned payloadSize; _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,id,&file,&fileSize);
 if(_Z13GetFileInNarcPKvPKcPS0_Pjj(file,*(const char**)(p+0x10),&data,&payloadSize,0)) { World_LoadZoneRenderPartWithSavedVram((char*)self,state,file,fileSize); *(unsigned int*)(p+0x1c)=2; }
 else { data=ResourceFile_FindNamedPayloadAndSize(file,*(const char**)(p+0x10),&payloadSize); if(data) { World_LoadZoneRenderPartWithSavedVram((char*)self,state,file,fileSize); *(unsigned int*)(p+0x1c)=2; } }
}
