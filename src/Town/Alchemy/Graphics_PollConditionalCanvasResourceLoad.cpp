#include <globaldefs.h>
ARM
struct Record;struct Owner;struct State;
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" unsigned _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(void*,const char*,void*);
extern "C" unsigned _ZN16BackgroundLoader13GetTaskStatusEi(void*,unsigned);
extern "C" void _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(void*,int,void**,unsigned*);
extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(void*,int);
extern "C" char* ResourceFile_GetPayloadByIndex(char*,int,char**,unsigned*);
extern "C" int ResourceFile_CountActiveStrideRecords(Record*);
extern "C" void Graphics_InitializeCanvasTransferState(char*);
extern "C" void Graphics_SetTextBackgroundScreenSize(int,unsigned);
extern "C" void Graphics_ParseTaggedLayerResource(char*,const void*);
extern "C" void Graphics_DispatchResourceByFourByteMagic(unsigned char*,void*);
extern "C" void Graphics_SetBackgroundColorMode(Owner*,unsigned);
extern "C" int Graphics_InvokeTwoIndexTransferCallback(State*,void*,void*);
extern "C" void Graphics_UpdateMainBackgroundScreens(void*,int);
extern "C" char Graphics_PollConditionalCanvasResourceLoad_PathDataAniBgRriTPac[],Graphics_PollConditionalCanvasResourceLoad_PathDataAniBgRriKariPac[];
struct Nibbles{unsigned char low:4,high:4;};
struct Canvas{char pad[0x1c];Nibbles mode;char tail[3];};
// Original: arm9/ov006 @ 0x02156BD8; symbol: func_ov006_02156bd8; size: 0x198.
extern "C" void Graphics_PollConditionalCanvasResourceLoad(char* p) {
 Canvas canvas;char* block;void* file;unsigned fileSize,blockSize;
 if(!(*(unsigned short*)(p+0xae2)&1))return;
 void* loader=_ZN16BackgroundLoader11GetInstanceEv();
 if(*(unsigned char*)(p+0xadf)==0) {
  if(*(unsigned short*)(p+0xae2)&8)*(unsigned*)(p+0xad8)=_ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader,Graphics_PollConditionalCanvasResourceLoad_PathDataAniBgRriTPac,0);
  else *(unsigned*)(p+0xad8)=_ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader,Graphics_PollConditionalCanvasResourceLoad_PathDataAniBgRriKariPac,0);
  Graphics_UpdateMainBackgroundScreens(p+0xae4,0);
  ++*(unsigned char*)(p+0xadf);
 }else if(*(unsigned char*)(p+0xadf)==1) {
  if(_ZN16BackgroundLoader13GetTaskStatusEi(loader,*(int*)(p+0xad8))) {
   _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,*(int*)(p+0xad8),&file,&fileSize);
   int count=ResourceFile_CountActiveStrideRecords((Record*)file);
   Graphics_InitializeCanvasTransferState((char*)&canvas);
   Graphics_SetTextBackgroundScreenSize((int)&canvas,0);
   canvas.mode.low=0;canvas.mode.high=3;
   Graphics_SetBackgroundColorMode((Owner*)&canvas,3);
   Graphics_InvokeTwoIndexTransferCallback((State*)&canvas,0,0);
   for(int i=0;i<count;i++) {
    char* data=ResourceFile_GetPayloadByIndex((char*)file,i,&block,&blockSize);
    if(data) {Graphics_ParseTaggedLayerResource((char*)&canvas,data);Graphics_DispatchResourceByFourByteMagic((unsigned char*)&canvas,data);}
   }
   _ZN16BackgroundLoader10RemoveTaskEi(loader,*(int*)(p+0xad8));
   *(int*)(p+0xad8)=-1;
   *(unsigned char*)(p+0xadf)=0;
   *(unsigned short*)(p+0xae2)&=~1;
   *(unsigned short*)(p+0xae2)&=~4;
  }
 }
}
