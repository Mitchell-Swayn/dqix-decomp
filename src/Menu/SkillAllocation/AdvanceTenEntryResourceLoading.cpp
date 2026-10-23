#include <globaldefs.h>
ARM
struct Record;struct Owner;struct Object;struct Position;
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" unsigned _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(void*,const char*,void*);
extern "C" unsigned _ZN16BackgroundLoader13GetTaskStatusEi(void*,unsigned);
extern "C" void _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(void*,int,void**,unsigned*);
extern "C" void _ZN16BackgroundLoader38ReleaseCompletedBuffersAndRequeueTasksEv(void*);
extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(void*,int);
extern "C" char* ResourceFile_GetPayloadByIndex(char*,int,char**,unsigned*);
extern "C" int ResourceFile_CountActiveStrideRecords(Record*);
extern "C" void TextCanvas_InitializeLayoutAndTransferDefaults(unsigned char*);
extern "C" void DrawSortedSelectorEntries(char*,unsigned char*);
extern "C" int Graphics_LoadTaggedLayerResource(void*,const void*,unsigned,unsigned);
extern "C" char* Graphics_GetLoadedScreenDescriptor(char*,unsigned);
extern "C" void Tilemap_SetWholeMapPalette(Position*,int);
extern "C" void Graphics_UpdateBoundedSixteenByteEntry(Object*,unsigned,unsigned,unsigned,unsigned short);
extern "C" void Graphics_CleanAndTransferScreenBuffer(char*,void*);
extern "C" char AdvanceTenEntryResourceLoading_PathDataAniBgSknPac[];
// Original: arm9/ov013 @ 0x021878B0; symbol: func_ov013_021878b0; size: 0x1A8.
// Resets ten entry indices and asynchronously loads the canvas resource for them.
extern "C" void AdvanceTenEntryResourceLoading(char* p){
 void* loader=_ZN16BackgroundLoader11GetInstanceEv();
 if(*(unsigned char*)(p+0x66)==0){
 for(int i=0;i<10;i++){(*(short**)(p+0x50))[i]=-1;(*(short**)(p+0x54))[i]=-1;(*(char**)(p+0x58))[i]=2;}
 p[0x6a]=-1;_ZN16BackgroundLoader38ReleaseCompletedBuffersAndRequeueTasksEv(loader);
 *(unsigned*)(p+0x5c)=_ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader,AdvanceTenEntryResourceLoading_PathDataAniBgSknPac,0);(*(unsigned char*)(p+0x66))++;
 }else if(*(unsigned char*)(p+0x66)==1){
 if(_ZN16BackgroundLoader13GetTaskStatusEi(loader,*(unsigned*)(p+0x5c))){
 char* scratch;void* file;unsigned fileSize;unsigned length;unsigned char canvas[224];
 _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,*(int*)(p+0x5c),&file,&fileSize);
 ResourceFile_CountActiveStrideRecords((Record*)file);
 char* block=ResourceFile_GetPayloadByIndex((char*)file,0,&scratch,&length);
 if(block){TextCanvas_InitializeLayoutAndTransferDefaults(canvas);*(char**)(canvas+8)=block+16;*(short*)(canvas+0xb4)=10;*(short*)(canvas+0xb6)=11;*(short*)(canvas+0xa8)=32;*(short*)(canvas+0xaa)=24;DrawSortedSelectorEntries(p,canvas);
 Graphics_LoadTaggedLayerResource((Owner*)(p+0x28),block,0,length);
 }
 _ZN16BackgroundLoader10RemoveTaskEi(loader,*(int*)(p+0x5c));*(int*)(p+0x5c)=-1;
 char* entry=Graphics_GetLoadedScreenDescriptor(p+0x28,0);if(entry)Tilemap_SetWholeMapPalette((Position*)entry,p[0x67]);
 Graphics_UpdateBoundedSixteenByteEntry((Object*)(p+0x28),0,0,0,65535);Graphics_CleanAndTransferScreenBuffer(p+0x28,0);p[0x66]=0;(*(unsigned char*)(p+0x69))&=~1;
 }
 }
}
