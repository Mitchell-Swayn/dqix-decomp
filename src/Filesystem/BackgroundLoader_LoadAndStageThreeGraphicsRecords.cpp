#include <globaldefs.h>
#include <Filesystem/BackgroundLoader.h>
struct Canvas { unsigned base;unsigned char pad[10];unsigned short tile;unsigned char gap[12];unsigned char mode:4;unsigned char bank:4;unsigned char tail[3]; };
struct Layer { unsigned words[4]; };
extern "C" int ResourceFile_CountActiveStrideRecords(void*);extern "C" void* ResourceFile_GetPayloadByIndex(void*,int,unsigned*,unsigned*);
extern "C" void Graphics_InitializeCanvasTransferState(Canvas*);extern "C" void Graphics_SetBackgroundColorMode(Canvas*,int);extern "C" void Graphics_SetTextBackgroundScreenSize(Canvas*,int);extern "C" void Graphics_InvokeTwoIndexTransferCallback(Canvas*,int,int);extern "C" void Graphics_ParseTaggedLayerResource(Canvas*,void*);extern "C" void Graphics_DispatchResourceByFourByteMagic(Canvas*,void*);
extern "C" void Tilemap_ResetResourceDescriptor(Layer*);extern "C" void Tilemap_ReadPayloadSizeAndCleanCache(Layer*,void*);extern "C" int Graphics_GetScreenTransferCallback(int,int);extern "C" void Graphics_CopyPayloadLengthAndInvokeTransferCallback(Layer*,int,void*);extern "C" void Graphics_ResetLayerWrapper(Layer*);extern "C" void Graphics_CleanAndTransferScreenBuffer(Canvas*,int);extern "C" void Graphics_ResetLoadedLayerResources(Canvas*);
// Original: arm9/main @ 0x02020CB8; symbol: func_02020cb8; size: 0x1A0.
extern "C" void BackgroundLoader_LoadAndStageThreeGraphicsRecords(void*,int* taskInput){int* task=taskInput;
 struct Workspace {unsigned kind,length;void* file;Layer layer;Canvas canvas;unsigned sizes[3];void* records[3];} w;
 BackgroundLoader* loader=BackgroundLoader::GetInstance();w.file=0;w.length=0;loader->GetLoadedFileByID(*task,&w.file,&w.length);
 int count=ResourceFile_CountActiveStrideRecords(w.file);for(int i=0;i<count;i++)w.records[i]=ResourceFile_GetPayloadByIndex(w.file,i,&w.kind,&w.sizes[i]);
 Graphics_InitializeCanvasTransferState(&w.canvas);w.canvas.mode=1;w.canvas.bank=1;Graphics_SetBackgroundColorMode(&w.canvas,3);Graphics_SetTextBackgroundScreenSize(&w.canvas,0);Graphics_InvokeTwoIndexTransferCallback(&w.canvas,0,0);w.canvas.base=0x6000;w.canvas.tile=0xfffe;
 unsigned short* tiles=(unsigned short*)((char*)w.records[2]+16);for(int i=0;i<768;i++)tiles[i]+=0x300;
 for(int i=0;i<2;i++){void* record=w.records[i];Graphics_ParseTaggedLayerResource(&w.canvas,record);Graphics_DispatchResourceByFourByteMagic(&w.canvas,record);}
 Tilemap_ResetResourceDescriptor(&w.layer);void* record=w.records[2];Tilemap_ReadPayloadSizeAndCleanCache(&w.layer,record);int mode=Graphics_GetScreenTransferCallback(1,1);Graphics_CopyPayloadLengthAndInvokeTransferCallback(&w.layer,mode,record);Graphics_ResetLayerWrapper(&w.layer);Graphics_CleanAndTransferScreenBuffer(&w.canvas,0);Graphics_ResetLoadedLayerResources(&w.canvas);
 BackgroundLoader::GetInstance()->RemoveTask(*task);*task=-1;
}
