#include <globaldefs.h>
ARM
extern "C" int _ZN13SafeAllocator5ResetEv(...);
extern "C" int _ZN16BackgroundLoader10RemoveTaskEi(...);
extern "C" int _ZN16BackgroundLoader11GetInstanceEv(...);
extern "C" int _ZN16BackgroundLoader13GetTaskStatusEi(...);
extern "C" int _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(...);
extern "C" int ItemDetail_ConfigureCategoryLayout(...);
extern "C" int LoadRelativeLayoutRecords(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);extern "C" char* strcpy(char*,const char*);extern "C" int sprintf(char*,const char*,...);

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov023 @ 0x021E04E8; symbol: PollBackgroundResourceAndInitializeLoadedRecord.
extern "C" int ItemDetail_ConsumeCategoryLayout(char*self){
if(W(self,0x73c)==-1){if(P(self,76))ItemDetail_ConfigureCategoryLayout(self+204,P(self,76));return 7;}int loader=_ZN16BackgroundLoader11GetInstanceEv();if(_ZN16BackgroundLoader13GetTaskStatusEi(loader,W(self,0x73c))){void*data;unsigned size;_ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,W(self,0x73c),&data,&size);if(data&&size){_ZN13SafeAllocator5ResetEv(self);LoadRelativeLayoutRecords(self+204,self,data,size);}_ZN16BackgroundLoader10RemoveTaskEi(loader,W(self,0x73c));W(self,0x73c)=-1;if(P(self,76)){ItemDetail_ConfigureCategoryLayout(self+204,P(self,76));struct Kind{unsigned value:4;unsigned rest:28;};int enabled=((Kind*)(P(self,76)+8))->value<=7?1:0;B(self,0x79a)=enabled?1:0;}return 7;}return 5;
}
