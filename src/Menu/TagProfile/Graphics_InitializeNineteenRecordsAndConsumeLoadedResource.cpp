#include <globaldefs.h>
ARM
#pragma opt_common_subs off
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();extern "C" void Graphics_InitializeSpriteTransformDefaults(void*),SpriteAnimation_ResetTrackList(unsigned*),Graphics_InitializeSpriteResourceBuffers(unsigned char*);extern "C" void _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(void*,int,void**,unsigned*),_ZN16BackgroundLoader10RemoveTaskEi(void*,int),_ZN13SafeAllocator5ResetEv(void*);extern "C" int ResourceFile_CountActiveStrideRecords(void*);extern "C" char* ResourceFile_GetPayloadByIndex(char*,int,char**,unsigned*);extern "C" int Graphics_DispatchDataByResourceMagic(int,void*,int,int);
// Original: arm9/ov012 @ 0x021861e0; symbol: Graphics_InitializeNineteenRecordsAndConsumeLoadedResource; size 0x11c.
extern "C" void Graphics_InitializeNineteenRecordsAndConsumeLoadedResource(char* self){void* loader=_ZN16BackgroundLoader11GetInstanceEv();for(unsigned char i=0;i<19;i++)Graphics_InitializeSpriteTransformDefaults(P(self,0x1364)+40*i);SpriteAnimation_ResetTrackList((unsigned*)P(self,0x1360));Graphics_InitializeSpriteResourceBuffers((unsigned char*)P(self,0x135c));B(P(self,0x135c),0x50)=0;char* output=P(self,0x135c);P(output,0x40)=P(self,0x1364);H(output,0x4c)=19;P(P(self,0x135c),0x3c)=P(self,0x1360);char* record;void* data;unsigned size;unsigned recordSize;_ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,W(self,0x1390),&data,&size);int count=ResourceFile_CountActiveStrideRecords(data);_ZN13SafeAllocator5ResetEv(self+0x5c);for(int i=0;i<count;i++){char* block=ResourceFile_GetPayloadByIndex((char*)data,i,&record,&recordSize);Graphics_DispatchDataByResourceMagic((int)P(self,0x135c),block,recordSize,(int)(self+0x5c));}_ZN16BackgroundLoader10RemoveTaskEi(loader,W(self,0x1390));W(self,0x1390)=-1;}
