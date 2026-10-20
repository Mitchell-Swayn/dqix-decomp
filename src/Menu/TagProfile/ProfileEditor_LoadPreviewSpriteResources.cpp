#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
extern "C" {void* _ZN16BackgroundLoader11GetInstanceEv();void Graphics_InitializeSpriteTransformDefaults(void*);void Graphics_InitializeSpriteResourceBuffers(unsigned char*);void _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(void*,int,void**,unsigned*);int ResourceFile_CountActiveStrideRecords(void*);void _ZN13SafeAllocator5ResetEv(void*);void* ResourceFile_GetPayloadByIndex(void*,int,void**,unsigned*);int Graphics_DispatchDataByResourceMagic(void*,void*,int,void*);void _ZN16BackgroundLoader10RemoveTaskEi(void*,int);}
// Original: arm9/ov012 @ 0x021862FC; symbol: Resource_LoadThreeRecordGraphicsFromCompletedTask; size: 0x100.
// Initializes three fixed-point records then loads every variable-length graphics block from a completed task.
extern "C" void ProfileEditor_LoadPreviewSpriteResources(unsigned char* self){void* loader=_ZN16BackgroundLoader11GetInstanceEv();for(int i=0;i<3;++i)Graphics_InitializeSpriteTransformDefaults(P(self,0x136c)+i*40);Graphics_InitializeSpriteResourceBuffers(P(self,0x1368));P(self,0x1368)[0x50]=1;unsigned char* owner=P(self,0x1368);P(owner,0x40)=P(self,0x136c);H(owner,0x4c)=3;void* out;void* file;unsigned size;_ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,W(self,0x1394),&file,&size);int count=ResourceFile_CountActiveStrideRecords(file);_ZN13SafeAllocator5ResetEv(self+0x98);for(int i=0;i<count;++i){unsigned length;void* block=ResourceFile_GetPayloadByIndex(file,i,&out,&length);Graphics_DispatchDataByResourceMagic(P(self,0x1368),block,length,self+0x98);}_ZN16BackgroundLoader10RemoveTaskEi(loader,W(self,0x1394));W(self,0x1394)=-1;}
