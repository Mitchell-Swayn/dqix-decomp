#include <globaldefs.h>
ARM
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" unsigned _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(void*,const char*,void*);
extern "C" unsigned _ZN16BackgroundLoader13GetTaskStatusEi(void*,unsigned);
extern "C" void _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(void*,int,void**,unsigned*);
extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(void*,int);
extern "C" char* ResourceFile_GetPayloadByIndex(char*,int,char**,unsigned*);
extern "C" int ResourceFile_CountActiveStrideRecords(void*);
extern "C" void Graphics_InitializeCanvasTransferState(char*);
extern "C" void Graphics_ParseTaggedLayerResource(char*,const void*);
extern "C" void Graphics_DispatchResourceByFourByteMagic(unsigned char*,void*);
struct LoadState {char pad[0x20];int task;int state;};
// Original data: arm9/ov004 @ 0x21707e8; symbol: data_ov004_021707e8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 44 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" LoadState StatusMenuSelectNextSubpage_UnknownRoleZeroInitializedStorage;
extern "C" char Graphics_LoadAndDispatchSubscreenResources_PathDataAniBgSlime3Pac[];
struct Canvas {char pad[0x1c]; unsigned char first:4;unsigned char second:4; char rest[3];};
// Original: arm9/ov004 @ 0x02163144; symbol: func_ov004_02163144; size: 0x140.
extern "C" int Graphics_LoadAndDispatchSubscreenResources() {
 int result=1;
 void* loader=_ZN16BackgroundLoader11GetInstanceEv();
 if(StatusMenuSelectNextSubpage_UnknownRoleZeroInitializedStorage.state==0) {
  *(volatile unsigned*)0x04001010=0;
  *(volatile unsigned*)0x04001014=0;
  StatusMenuSelectNextSubpage_UnknownRoleZeroInitializedStorage.task=_ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader,Graphics_LoadAndDispatchSubscreenResources_PathDataAniBgSlime3Pac,0);
  ++StatusMenuSelectNextSubpage_UnknownRoleZeroInitializedStorage.state;
 } else if(StatusMenuSelectNextSubpage_UnknownRoleZeroInitializedStorage.state==1) {
  if(_ZN16BackgroundLoader13GetTaskStatusEi(loader,StatusMenuSelectNextSubpage_UnknownRoleZeroInitializedStorage.task)) {
   Canvas canvas;
   void* file;
   unsigned length;
   unsigned blockSize;
   char* blockData;
   _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,StatusMenuSelectNextSubpage_UnknownRoleZeroInitializedStorage.task,&file,&length);
   int count=ResourceFile_CountActiveStrideRecords(file);
   Graphics_InitializeCanvasTransferState((char*)&canvas);
   canvas.first=1;
   canvas.second=1;
   for(int i=0;i<count;i++) {
    char* block=ResourceFile_GetPayloadByIndex((char*)file,i,&blockData,&blockSize);
    if(block) {
     Graphics_ParseTaggedLayerResource((char*)&canvas,block);
     Graphics_DispatchResourceByFourByteMagic((unsigned char*)&canvas,block);
    }
   }
   _ZN16BackgroundLoader10RemoveTaskEi(loader,StatusMenuSelectNextSubpage_UnknownRoleZeroInitializedStorage.task);
   StatusMenuSelectNextSubpage_UnknownRoleZeroInitializedStorage.task=-1;
   result=0;
  }
 }
 return result;
}
