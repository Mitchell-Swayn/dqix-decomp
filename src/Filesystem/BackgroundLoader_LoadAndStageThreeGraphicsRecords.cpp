#include <globaldefs.h>
#include <Filesystem/BackgroundLoader.h>
struct Canvas { unsigned base;unsigned char pad[10];unsigned short tile;unsigned char gap[12];unsigned char mode:4;unsigned char bank:4;unsigned char tail[3]; };
struct Layer { unsigned words[4]; };
extern "C" int ResourceFile_CountActiveStrideRecords(void*);extern "C" void* FindVariableLengthBlockByIndex(void*,int,unsigned*,unsigned*);
extern "C" void Graphics_InitializeCanvasTransferState(Canvas*);extern "C" void DispatchModeThroughTwoDimensionalFlagTable(Canvas*,int);extern "C" void SetWordField18AndClearFormatByte1F(Canvas*,int);extern "C" void Graphics_InvokeTwoIndexTransferCallback(Canvas*,int,int);extern "C" void DispatchResourceParserByFourByteMagic(Canvas*,void*);extern "C" void Graphics_DispatchResourceByFourByteMagic(Canvas*,void*);
extern "C" void ClearHalfwordPairBytePairAndWordPair(Layer*);extern "C" void CopyImageLengthAndFlushPayloadCache(Layer*,void*);extern "C" int ReadTwoDimensionalGlobalWordTable(int,int);extern "C" void Graphics_CopyPayloadLengthAndInvokeTransferCallback(Layer*,int,void*);extern "C" void Graphics_ResetLayerWrapper(Layer*);extern "C" void UpdateProvidedOrStoredChildResource(Canvas*,int);extern "C" void ResetRecordAndIndexedEntries(Canvas*);
// Original: arm9/main @ 0x02020CB8; symbol: func_02020cb8; size: 0x1A0.
extern "C" void BackgroundLoader_LoadAndStageThreeGraphicsRecords(void*,int* taskInput){int* task=taskInput;
 struct Workspace {unsigned kind,length;void* file;Layer layer;Canvas canvas;unsigned sizes[3];void* records[3];} w;
 BackgroundLoader* loader=BackgroundLoader::GetInstance();w.file=0;w.length=0;loader->GetLoadedFileByID(*task,&w.file,&w.length);
 int count=ResourceFile_CountActiveStrideRecords(w.file);for(int i=0;i<count;i++)w.records[i]=FindVariableLengthBlockByIndex(w.file,i,&w.kind,&w.sizes[i]);
 Graphics_InitializeCanvasTransferState(&w.canvas);w.canvas.mode=1;w.canvas.bank=1;DispatchModeThroughTwoDimensionalFlagTable(&w.canvas,3);SetWordField18AndClearFormatByte1F(&w.canvas,0);Graphics_InvokeTwoIndexTransferCallback(&w.canvas,0,0);w.canvas.base=0x6000;w.canvas.tile=0xfffe;
 unsigned short* tiles=(unsigned short*)((char*)w.records[2]+16);for(int i=0;i<768;i++)tiles[i]+=0x300;
 for(int i=0;i<2;i++){void* record=w.records[i];DispatchResourceParserByFourByteMagic(&w.canvas,record);Graphics_DispatchResourceByFourByteMagic(&w.canvas,record);}
 ClearHalfwordPairBytePairAndWordPair(&w.layer);void* record=w.records[2];CopyImageLengthAndFlushPayloadCache(&w.layer,record);int mode=ReadTwoDimensionalGlobalWordTable(1,1);Graphics_CopyPayloadLengthAndInvokeTransferCallback(&w.layer,mode,record);Graphics_ResetLayerWrapper(&w.layer);UpdateProvidedOrStoredChildResource(&w.canvas,0);ResetRecordAndIndexedEntries(&w.canvas);
 BackgroundLoader::GetInstance()->RemoveTask(*task);*task=-1;
}
