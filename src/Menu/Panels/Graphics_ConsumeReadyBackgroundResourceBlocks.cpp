#include <globaldefs.h>
ARM
extern "C" char* _ZN16BackgroundLoader11GetInstanceEv(...);
extern "C" char* ResourceFile_GetPayloadByIndex(...);
extern "C" int _ZN16BackgroundLoader13GetTaskStatusEi(...);
extern "C" int ResourceFile_CountActiveStrideRecords(...);
extern "C" void _ZN13SafeAllocator5ResetEv(...);
extern "C" void _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(...);
extern "C" void Graphics_DispatchDataByResourceMagic(...);
extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(...);
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
struct Four {short values[4];};struct Eight {short values[8];};
// Original: arm9/ov023 @ 0x021DDAE4; symbol: Graphics_ConsumeReadyBackgroundResourceBlocks; size: 0xd4.
// Consumes completed background task blocks into graphics context and updates state byte before task removal.
extern "C" void Graphics_ConsumeReadyBackgroundResourceBlocks(char* self){if(W(self,0x780)<0)return;char* loader=_ZN16BackgroundLoader11GetInstanceEv();if(!_ZN16BackgroundLoader13GetTaskStatusEi(loader,W(self,0x780)))return;_ZN13SafeAllocator5ResetEv(P(self,0x44));char* out;char* data;unsigned size;_ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,W(self,0x780),&data,&size);if(data&&size){int count=ResourceFile_CountActiveStrideRecords(data);unsigned length;for(int i=0;i<count;++i){char* block=ResourceFile_GetPayloadByIndex(data,i,&out,&length);Graphics_DispatchDataByResourceMagic(self+0x12c,block,length,P(self,0x44));}}B(self,0x77d)=*(signed char*)(self+0x77e);_ZN16BackgroundLoader10RemoveTaskEi(loader,W(self,0x780));W(self,0x780)=-1;}
