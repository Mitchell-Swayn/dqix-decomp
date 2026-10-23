#include <globaldefs.h>
ARM
struct SafeAllocator;struct Record;struct Owner;struct State;struct TilemapOwner;struct Layout;struct Input;
struct Nibbles{unsigned char low:4;unsigned char high:4;};
extern "C" {
void* _ZN16BackgroundLoader11GetInstanceEv();
unsigned _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(void*,const char*,void*);
unsigned _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(void*,const char*,const char*,void*);
unsigned _ZN16BackgroundLoader13GetTaskStatusEi(void*,unsigned);
void _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(void*,int,void**,unsigned*);
void _ZN16BackgroundLoader10RemoveTaskEi(void*,int);
char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
char* ResourceFile_GetPayloadByIndex(char*,int,char**,unsigned*);
int ResourceFile_CountActiveStrideRecords(Record*);
void Graphics_CleanAndTransferScreenBuffer(char*,void*);
void Graphics_SetTextBackgroundScreenSize(int,unsigned);
void Graphics_AllocateAndClearConfiguredBuffer(char*,SafeAllocator*);
int Graphics_LoadTaggedLayerResource(void*,const void*,unsigned,unsigned);
void Graphics_SetBackgroundColorMode(Owner*,unsigned);
int Graphics_InvokeTwoIndexTransferCallback(State*,void*,void*);
void Tilemap_FillClippedRectangle(TilemapOwner*,unsigned,short,short,short,short,unsigned);
void TextCanvas_AllocateTilemapAndBindPixels(char*,SafeAllocator*,int,unsigned);
int Graphics_DispatchDataByResourceMagic(int,void*,int,int);
void Selection_AttachBackwardLinkedDisplayRecords(unsigned char*,char*,unsigned char);
int ResourceStringTable_CopySerializedData(unsigned*,void*,unsigned char*,unsigned);
int LoadRelativeLayoutRecords(Layout*,unsigned,Input*,void*);
// Original data: arm9/ov003 @ 0x217f5b8; symbol: data_ov003_0217f5b8.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0001.
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov003.md.
// Original data: arm9/ov003 @ 0x217f5ba; symbol: data_ov003_0217f5ba.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0102.
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov003.md.
extern const unsigned char AdvanceTwoCanvasAndLayoutResourceLoads_UnknownRoleInitializedBytes_Variant2[],AdvanceTwoCanvasAndLayoutResourceLoads_UnknownRoleInitializedBytes[];
extern char AdvanceTwoCanvasAndLayoutResourceLoads_PathDataAniBgTmPac[],AdvanceTwoCanvasAndLayoutResourceLoads_PathDataAniObjGlPac[],AdvanceTwoCanvasAndLayoutResourceLoads_PathDataAniLayGlistLia[],AdvanceTwoCanvasAndLayoutResourceLoads_PathDataBinMenuStrGlmGp2[],AdvanceTwoCanvasAndLayoutResourceLoads_MarkupStrGlmLGNat[];
}
// Original: arm9/ov003 @ 0x0216E2A4; symbol: func_ov003_0216e2a4; size: 0x470.
// Initializes two canvases and text records, then advances five background-loading stages for tagged graphics, layout and entry tables.
extern "C" void AdvanceTwoCanvasAndLayoutResourceLoads(char* p) {
 void* loader=_ZN16BackgroundLoader11GetInstanceEv();int phase=p[2];
 if(phase==0) {
 char* canvas=*(char**)(p+0x40);
 for(int i=0;i<2;++i) {
 Graphics_SetTextBackgroundScreenSize((int)canvas,0);
 unsigned format=AdvanceTwoCanvasAndLayoutResourceLoads_UnknownRoleInitializedBytes_Variant2[i];unsigned mode=AdvanceTwoCanvasAndLayoutResourceLoads_UnknownRoleInitializedBytes[i];
 ((unsigned char*)canvas)[0x1c]&=~15;
 ((unsigned char*)canvas)[0x1c]=(((unsigned char*)canvas)[0x1c]&~0xf0)|((unsigned)(unsigned char)format<<28>>24);
 Graphics_SetBackgroundColorMode((Owner*)canvas,mode);
 Graphics_AllocateAndClearConfiguredBuffer(canvas,*(SafeAllocator**)(p+0xd0));
 Graphics_InvokeTwoIndexTransferCallback((State*)canvas,0,0);canvas+=32;
 }
 volatile unsigned short* bg=(volatile unsigned short*)0x400000a;
 bg[0]=(bg[0]&0x43)|0xd08;bg[1]=(bg[1]&0x43)|0xe08;
 *(int*)(p+0x1c)=_ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader,AdvanceTwoCanvasAndLayoutResourceLoads_PathDataAniBgTmPac,0);p[2]=1;
 } else if(phase==1) {
 if(!_ZN16BackgroundLoader13GetTaskStatusEi(loader,*(int*)(p+0x1c)))return;
 char* tag;void* file;char* blocks[2];unsigned length;unsigned sizes[2];
 _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,*(int*)(p+0x1c),&file,&length);
 int count=ResourceFile_CountActiveStrideRecords((Record*)file);
 for(int i=0;i<count;++i)blocks[i]=ResourceFile_GetPayloadByIndex((char*)file,i,&tag,&sizes[i]);
 for(int i=0;i<count;++i)if(blocks[i])Graphics_LoadTaggedLayerResource((Owner*)*(char**)(p+0x40),blocks[i],*(unsigned*)(p+0xd0),sizes[i]);
 _ZN16BackgroundLoader10RemoveTaskEi(loader,*(int*)(p+0x1c));*(int*)(p+0x1c)=-1;
 char* canvas=*(char**)(p+0x40);
 for(int i=0;i<2;++i) {Tilemap_FillClippedRectangle((TilemapOwner*)canvas,0,0,0,32,25,0);Graphics_CleanAndTransferScreenBuffer(canvas,0);canvas+=32;}
 *(char**)(p+0x14)=_ZN13SafeAllocator8AllocateEj(*(unsigned*)(p+0xd0),0x2800);
 char* records=*(char**)(p+0x44);
 for(int i=0;i<2;++i) {
 TextCanvas_AllocateTilemapAndBindPixels(records,*(SafeAllocator**)(p+0xd0),*(int*)(p+0x14),0x500);
 *(char**)(records+4)=*(char**)(p+0x40)+i*32;records[0xc4]=0;records+=224;
 }
 char* display=*(char**)(p+0x3c);
 *(char**)(display+0x98)=*(char**)(p+0x40);display[0xb2]=2;
 Selection_AttachBackwardLinkedDisplayRecords(*(unsigned char**)(p+0x3c),*(char**)(p+0x44),2);
 p[0xb8]=0;*(int*)(p+0xa8)=*(int*)(p+0x60);*(short*)(p+0xb4)=0x16;*(int*)(p+0xa4)=*(int*)(p+0x64);
 *(int*)(p+0x1c)=_ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader,AdvanceTwoCanvasAndLayoutResourceLoads_PathDataAniObjGlPac,0);p[2]=2;
 } else if(phase==2) {
 if(!_ZN16BackgroundLoader13GetTaskStatusEi(loader,*(int*)(p+0x1c)))return;
 char* tag;void* file;unsigned length,size;
 _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,*(int*)(p+0x1c),&file,&length);
 int count=ResourceFile_CountActiveStrideRecords((Record*)file);
 for(int i=0;i<count;++i) {char* block=ResourceFile_GetPayloadByIndex((char*)file,i,&tag,&size);Graphics_DispatchDataByResourceMagic((int)(p+0x68),block,size,(int)(p+0xbc));}
 _ZN16BackgroundLoader10RemoveTaskEi(loader,*(int*)(p+0x1c));*(int*)(p+0x1c)=-1;
 *(int*)(p+0x1c)=_ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader,AdvanceTwoCanvasAndLayoutResourceLoads_PathDataAniLayGlistLia,0);p[2]=3;
 } else if(phase==3) {
 if(!_ZN16BackgroundLoader13GetTaskStatusEi(loader,*(int*)(p+0x1c)))return;
 void* file;unsigned length;
 _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,*(int*)(p+0x1c),&file,&length);
 LoadRelativeLayoutRecords(*(Layout**)(p+0xd4),*(unsigned*)(p+0xd0),(Input*)file,(void*)length);
 _ZN16BackgroundLoader10RemoveTaskEi(loader,*(int*)(p+0x1c));*(int*)(p+0x1c)=-1;
 *(int*)(p+0x1c)=_ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(loader,AdvanceTwoCanvasAndLayoutResourceLoads_PathDataBinMenuStrGlmGp2,AdvanceTwoCanvasAndLayoutResourceLoads_MarkupStrGlmLGNat,0);p[2]=4;
 } else if(phase==4) {
 if(!_ZN16BackgroundLoader13GetTaskStatusEi(loader,*(int*)(p+0x1c)))return;
 void* file;unsigned length;
 _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,*(int*)(p+0x1c),&file,&length);
 ResourceStringTable_CopySerializedData((unsigned*)(p+0xdc),*(void**)(p+0xd0),(unsigned char*)file,length);
 _ZN16BackgroundLoader10RemoveTaskEi(loader,*(int*)(p+0x1c));*(int*)(p+0x1c)=-1;p[1]=2;p[2]=0;
 }
}
