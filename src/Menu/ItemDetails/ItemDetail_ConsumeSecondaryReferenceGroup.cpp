#include <globaldefs.h>
ARM
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();extern "C" unsigned _ZN16BackgroundLoader13GetTaskStatusEi(void*,unsigned);extern "C" void _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(void*,int,void**,unsigned*);extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(void*,int);extern "C" void ResourceGroupTable_CopyAllOrSelectedGroup(void*,void*,void*,unsigned,int);
// Original: arm9/ov023 @ 0x021E0B9C; symbol: PollLoadTaskAndInitializeLoadedObject; size: 0x9c.
extern "C" int ItemDetail_ConsumeSecondaryReferenceGroup(char* self){
if(W(self,0x74c)==-1)return -1;void* loader=_ZN16BackgroundLoader11GetInstanceEv();if(_ZN16BackgroundLoader13GetTaskStatusEi(loader,W(self,0x74c))){void* buffer;unsigned size;_ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,W(self,0x74c),&buffer,&size);if(buffer&&size)ResourceGroupTable_CopyAllOrSelectedGroup(self+0x7c,self+0x28,buffer,size,*(short*)(P(self,0x4c)+24));_ZN16BackgroundLoader10RemoveTaskEi(loader,W(self,0x74c));W(self,0x74c)=-1;return 15;}else return 13;
}
