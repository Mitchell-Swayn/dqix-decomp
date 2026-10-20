#include <globaldefs.h>
ARM
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();extern "C" int Menu_GetBackgroundLoadTicket(void*);extern "C" unsigned _ZN16BackgroundLoader13GetTaskStatusEi(void*,unsigned);extern "C" unsigned _ZN16BackgroundLoader21GetDetailedTaskStatusEi(void*,unsigned);extern "C" void _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(void*,int,void**,unsigned*);extern "C" int _Z13GetFileInNarcPKvPKcPS0_Pjj(const void*,const char*,void**,unsigned*,unsigned);extern "C" void* ResourceFile_FindNamedPayloadAndSize(void*,const char*,unsigned*);extern "C" void Graphics_LoadNamedResourcesAndStageSharedState(void*,void*,void*,unsigned);
// Original: arm9/ov023 @ 0x021FAA60; symbol: StageNamedArchiveResourceWhenTaskComplete; size: 0xE8.
extern "C" void Menu_StageCompletedNamedSpriteResource(char* self,void* owner){void* loader=_ZN16BackgroundLoader11GetInstanceEv();int task=Menu_GetBackgroundLoadTicket(owner);if(task<0)return;if(!_ZN16BackgroundLoader13GetTaskStatusEi(loader,task))return;if(_ZN16BackgroundLoader21GetDetailedTaskStatusEi(loader,task)!=2)return;void* source;unsigned length;void* entry;unsigned size;_ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,task,&source,&length);if(_Z13GetFileInNarcPKvPKcPS0_Pjj(source,P(self,16),&entry,&size,0)){Graphics_LoadNamedResourcesAndStageSharedState(self,owner,source,length);W(self,28)=2;}else{entry=ResourceFile_FindNamedPayloadAndSize(source,P(self,16),&size);if(entry){Graphics_LoadNamedResourcesAndStageSharedState(self,owner,source,length);W(self,28)=2;}}}
