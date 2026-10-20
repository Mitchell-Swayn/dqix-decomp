#include <globaldefs.h>
ARM
#pragma always_inline on
struct SafeAllocator;struct Record;struct Owner;struct State;struct TilemapOwner;struct ScriptBundle;
extern "C" {
void* __clear(void*,unsigned);void* _ZN16BackgroundLoader11GetInstanceEv();
unsigned _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(void*,const char*,void*);
unsigned _ZN16BackgroundLoader13GetTaskStatusEi(void*,unsigned);
void _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(void*,int,void**,unsigned*);
void _ZN16BackgroundLoader38ReleaseCompletedBuffersAndRequeueTasksEv(void*);void _ZN16BackgroundLoader10RemoveTaskEi(void*,int);
char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);void _ZN13SafeAllocator5ResetEv(void*);
char* ResourceFile_GetPayloadByIndex(char*,int,char**,unsigned*);int ResourceFile_CountActiveStrideRecords(Record*);
char* Graphics_GetLoadedScreenDescriptor(char*,unsigned);
void Graphics_AllocateScreenDescriptors(unsigned char*,unsigned,SafeAllocator*);
void Graphics_InitializeCanvasTransferState(char*);void Graphics_CleanAndTransferScreenBuffer(char*,void*);void Graphics_SetTextBackgroundScreenSize(int,unsigned);
void Graphics_AllocateAndClearConfiguredBuffer(char*,SafeAllocator*);int Graphics_LoadTaggedLayerResource(Owner*,const void*,unsigned);
void Graphics_SetBackgroundColorMode(Owner*,unsigned);int Graphics_InvokeTwoIndexTransferCallback(State*,void*,void*);
void Tilemap_FillClippedRectangle(TilemapOwner*,unsigned,short,short,short,short,unsigned);
void TextCanvas_InitializeLayoutAndTransferDefaults(unsigned char*);void TextCanvas_AllocateTilemapAndBindPixels(char*,SafeAllocator*,int,unsigned);
void DisplayLayout_AttachBackwardLinkedCanvases(unsigned char*,char*,unsigned char);void DisplayLayout_Initialize(char*);
void BackgroundLoader_QueueThreeNamedGP2Files(unsigned*,unsigned,const char*,unsigned);int PollAndExecuteLoadedScriptBundles(ScriptBundle*);
void Graphics_UpdateCounted224ByteDisplayRecords(char*);void MapVRAMBanksToSubBG(int);unsigned DisableSubBGVRAMBanks();
void LoadToSubBGStandardPalette(const void*,unsigned,unsigned);void LoadToSubBG1ScreenData(const void*,unsigned,unsigned);
void _Z15CleanCacheRangePKvj(const void*,unsigned);void _Z25CleanInvalidateCacheRangePKvj(const void*,unsigned);
void CharacterStatus_RefreshChangedDisplayMode(char*,int,int);
// Original data: arm9/ov003 @ 0x217f4dc; symbol: data_ov003_0217f4dc.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex c618000000001000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov003.md.
extern char PollSubCanvasAndTextResourceInitialization_PathDataAniBgSlime3Pac[],PollSubCanvasAndTextResourceInitialization_PathDataBinMenuBmTuyoGp2[],PollSubCanvasAndTextResourceInitialization_TextBmTuyo[];extern unsigned short PollSubCanvasAndTextResourceInitialization_UnknownRoleInitializedBytes;
}
inline void InitializeTextRecords(char* p,SafeAllocator* allocator){ for(int i=0;i<4;++i){char* record=*(char**)(p+0xc)+i*224;TextCanvas_InitializeLayoutAndTransferDefaults((unsigned char*)record);TextCanvas_AllocateTilemapAndBindPixels(record,(SafeAllocator*)((char*)allocator+0x14),*(int*)p,0x600);*(char**)(record+4)=*(char**)(p+8);}}
// Original: arm9/ov003 @ 0x0216759C; symbol: func_ov003_0216759c; size: 0x4C0.
// Loads two sub-screen canvases and four text records, then activates their palettes and queued mode handler.
extern "C" int PollSubCanvasAndTextResourceInitialization(char* p) {
 if(((unsigned char*)p)[0x74])return 1;
 int result=1;void* loader=_ZN16BackgroundLoader11GetInstanceEv();unsigned phase=((unsigned char*)p)[0x75];
 if(phase==0) {
 *(volatile unsigned*)0x4001010=0;*(volatile unsigned*)0x4001014=0;
 SafeAllocator* allocator=*(SafeAllocator**)(p+4);_ZN13SafeAllocator5ResetEv(allocator);
 *(char**)(p+8)=_ZN13SafeAllocator8AllocateEj((unsigned)allocator,0x40);
 unsigned words[2];__clear(words,8);
 char* canvas;
 for(int i=0;i<2;++i) {
 canvas=*(char**)(p+8)+i*32;Graphics_InitializeCanvasTransferState(canvas);
 Graphics_SetTextBackgroundScreenSize((int)canvas,words[i]);
 ((unsigned char*)canvas)[0x1c]=(((unsigned char*)canvas)[0x1c]&~15)|1;
 ((unsigned char*)canvas)[0x1c]=(((unsigned char*)canvas)[0x1c]&~0xf0)|((unsigned)(unsigned char)i<<28>>24);
 Graphics_SetBackgroundColorMode((Owner*)canvas,i);
 Graphics_AllocateAndClearConfiguredBuffer(canvas,allocator);Graphics_InvokeTwoIndexTransferCallback((State*)canvas,0,0);
 }
 Graphics_AllocateScreenDescriptors(*(unsigned char**)(p+8)+32,1,allocator);
 DisableSubBGVRAMBanks();MapVRAMBanksToSubBG(0x80);
 volatile unsigned short* bg=(volatile unsigned short*)0x4001008;bg[0]=(bg[0]&0x43)|0xe00;bg[1]=(bg[1]&0x43)|0xf00;bg[0x24]=0;
 _ZN16BackgroundLoader38ReleaseCompletedBuffersAndRequeueTasksEv(loader);
 *(int*)(p+0x64)=_ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader,PollSubCanvasAndTextResourceInitialization_PathDataAniBgSlime3Pac,0);
 ++((unsigned char*)p)[0x75];result=0;
 }else if(phase==1) {
 if(_ZN16BackgroundLoader13GetTaskStatusEi(loader,*(int*)(p+0x64))) {
 char* tag;void* file;unsigned length,size;
 _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,*(int*)(p+0x64),&file,&length);
 int textIndex;int count=ResourceFile_CountActiveStrideRecords((Record*)file);
 SafeAllocator* allocator=*(SafeAllocator**)(p+4);char* canvas=*(char**)(p+8);
 for(int i=0;i<count;++i) {
 char* block=ResourceFile_GetPayloadByIndex((char*)file,i,&tag,&size);
 if(block){((int(*)(Owner*,const void*,unsigned,unsigned))Graphics_LoadTaggedLayerResource)((Owner*)canvas,block,(unsigned)allocator,size);canvas=*(char**)(p+8)+32;}
 }
 _ZN16BackgroundLoader10RemoveTaskEi(loader,*(int*)(p+0x64));*(int*)(p+0x64)=-1;
 canvas=*(char**)(p+8);Tilemap_FillClippedRectangle((TilemapOwner*)canvas,0,0,0,32,25,0);Graphics_CleanAndTransferScreenBuffer(canvas,0);
 char* entry=Graphics_GetLoadedScreenDescriptor(*(char**)(p+8)+32,0);
 if(entry){void* data;unsigned bytes;bytes=*(unsigned*)(entry+8);data=*(void**)(entry+12);_Z25CleanInvalidateCacheRangePKvj(data,bytes);LoadToSubBG1ScreenData(data,0,bytes);}
 allocator=*(SafeAllocator**)(p+4);_ZN13SafeAllocator5ResetEv((char*)allocator+0x14);
 *(char**)(p+0xc)=_ZN13SafeAllocator8AllocateEj((unsigned)((char*)allocator+0x14),0x380);
 InitializeTextRecords(p,allocator);
 ++((unsigned char*)p)[0x75];
 }
 result=0;
 }else if(phase==2) {
 char* allocator=*(char**)(p+4);_ZN13SafeAllocator5ResetEv(allocator+0x28);*(char**)(p+0x10)=_ZN13SafeAllocator8AllocateEj((unsigned)(allocator+0x28),0x40);
 DisplayLayout_Initialize(*(char**)(p+0x10));
 BackgroundLoader_QueueThreeNamedGP2Files(*(unsigned**)(p+0x10),(unsigned)(allocator+0x28),PollSubCanvasAndTextResourceInitialization_PathDataBinMenuBmTuyoGp2,(unsigned)PollSubCanvasAndTextResourceInitialization_TextBmTuyo);
 ++((unsigned char*)p)[0x75];result=0;
 }else if(phase==3) {
 int status=PollAndExecuteLoadedScriptBundles(*(ScriptBundle**)(p+0x10));if(status==0)++((unsigned char*)p)[0x75];if(status<0)p[0x74]=2;result=0;
 }else if(phase==4) {
 volatile unsigned short* bg=(volatile unsigned short*)0x4001008;bg[0]&=~3;bg[1]=(bg[1]&~3)|1;bg[2]=(bg[2]&~3)|2;bg[3]=(bg[3]&~3)|3;
 *(volatile unsigned*)0x4001000=(*(volatile unsigned*)0x4001000&~0x1f00)|0x1300;
 _Z25CleanInvalidateCacheRangePKvj(&PollSubCanvasAndTextResourceInitialization_UnknownRoleInitializedBytes,2);LoadToSubBGStandardPalette(&PollSubCanvasAndTextResourceInitialization_UnknownRoleInitializedBytes,2,2);_Z15CleanCacheRangePKvj(&PollSubCanvasAndTextResourceInitialization_UnknownRoleInitializedBytes,2);
 _Z25CleanInvalidateCacheRangePKvj(&PollSubCanvasAndTextResourceInitialization_UnknownRoleInitializedBytes,2);LoadToSubBGStandardPalette(&PollSubCanvasAndTextResourceInitialization_UnknownRoleInitializedBytes,0x22,2);_Z15CleanCacheRangePKvj(&PollSubCanvasAndTextResourceInitialization_UnknownRoleInitializedBytes,2);
 DisplayLayout_AttachBackwardLinkedCanvases(*(unsigned char**)(p+0x10),*(char**)(p+0xc),4);
 char* display=*(char**)(p+0x10);*(char**)(display+0x2c)=*(char**)(p+8);display[0x38]=result;
 (*(char**)(p+0x10))[0x3a]=0;p[0x74]=result;p[0x75]=0;
 if(*(int*)(p+0x70)&&p[0x76]>=0){Graphics_UpdateCounted224ByteDisplayRecords(*(char**)(p+0x10));int value=p[0x76];p[0x76]=-1;CharacterStatus_RefreshChangedDisplayMode(p,*(int*)(p+0x70),value);}
 }
 return result;
}
