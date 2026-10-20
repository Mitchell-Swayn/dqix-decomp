#include <globaldefs.h>
#include <System/ColorEffects.h>
ARM
struct FormatByte { unsigned char low:4,high:4; };
struct Record;struct Owner;struct State;struct SafeAllocator;struct TilemapOwner;
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" unsigned _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(void*,const char*,const char*,void*);
extern "C" unsigned _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(void*,const char*,void*);
extern "C" unsigned _ZN16BackgroundLoader13GetTaskStatusEi(void*,unsigned);
extern "C" void _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(void*,int,void**,unsigned*);
extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(void*,int);
extern "C" void _ZN13SafeAllocator5ResetEv(void*);
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
extern "C" int ResourceStringTable_CopySerializedData(unsigned*,void*,unsigned char*,unsigned);
extern "C" unsigned TextContext_GetSharedInstance();
extern "C" void Selection_EnableTouchInput(int);
extern "C" void Selection_EnableDirectionalInput(int);
extern "C" void InitializeMatchingSelectionOverlay(unsigned char*);
extern "C" void RefreshHeadingAndUploadFontTiles(char*);
extern "C" unsigned DisplayContext_GetGlobalInstance();
extern "C" void DisplayContext_IgnoreTransitionParameter(void*,int);
extern "C" void DisplayContext_IgnoreRequest(int,int,int);
extern "C" int DisplayContext_ReportRequestComplete();
extern "C" void Graphics_SetTextBackgroundScreenSize(int,unsigned);
extern "C" void Graphics_SetBackgroundColorMode(Owner*,unsigned);
extern "C" void Graphics_AllocateAndClearConfiguredBuffer(char*,SafeAllocator*);
extern "C" int Graphics_InvokeTwoIndexTransferCallback(State*,void*,void*);
extern "C" int ResourceFile_CountActiveStrideRecords(Record*);
extern "C" char* ResourceFile_GetPayloadByIndex(char*,int,char**,unsigned*);
extern "C" int Graphics_LoadTaggedLayerResource(Owner*,const void*,unsigned);
extern "C" void Tilemap_FillClippedRectangle(TilemapOwner*,unsigned,short,short,short,short,unsigned);
extern "C" void Graphics_CleanAndTransferScreenBuffer(char*,void*);
extern "C" void TextCanvas_AllocateTilemapAndBindPixels(char*,SafeAllocator*,int,unsigned);
extern "C" void Selection_AttachBackwardLinkedDisplayRecords(unsigned char*,char*,unsigned char);
extern "C" char AdvanceHeadingResourceInitialization_PathDataBinMenuStrSuGp2[],AdvanceHeadingResourceInitialization_MarkupStrSuLGNat[],AdvanceHeadingResourceInitialization_PathDataAniBgTmPac[];
// Original data: arm9/ov013 @ 0x2187d88; symbol: data_ov013_02187d88.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0100.
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov013.md.
// Original data: arm9/ov013 @ 0x2187d8a; symbol: data_ov013_02187d8a.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 01020106000080000000.
// Observed span: 10 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov013.md.
extern "C" const unsigned char AdvanceHeadingResourceInitialization_UnknownRoleInitializedBytes_Variant2[],AdvanceHeadingResourceInitialization_UnknownRoleInitializedBytes[];
// Original: arm9/ov013 @ 0x02184D80; symbol: func_ov013_02184d80; size: 0x590.
// Advances asynchronous heading resource loading and initializes main/sub display resources.
extern "C" void AdvanceHeadingResourceInitialization(unsigned char* p){
 if(p[0x63c])return;
 void* loader=_ZN16BackgroundLoader11GetInstanceEv();
 if(p[0x640]){
 if(p[0x63e]==0){
 *(unsigned*)(p+0x650)=_ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(loader,AdvanceHeadingResourceInitialization_PathDataBinMenuStrSuGp2,AdvanceHeadingResourceInitialization_MarkupStrSuLGNat,0);p[0x63e]++;
 }else if(p[0x63e]==1){
 if(_ZN16BackgroundLoader13GetTaskStatusEi(loader,*(unsigned*)(p+0x650))){
 void* file;unsigned size;
 _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,*(int*)(p+0x650),&file,&size);
 _ZN13SafeAllocator5ResetEv(p+0x60c);
 ResourceStringTable_CopySerializedData((unsigned*)(p+0x620),p+0x60c,(unsigned char*)file,size);
 _ZN16BackgroundLoader10RemoveTaskEi(loader,*(int*)(p+0x650));*(int*)(p+0x650)=-1;p[0x63e]++;
 }
 }else if(p[0x63e]==2){
 *(unsigned*)(p+0x658)=*(unsigned*)(TextContext_GetSharedInstance()+0x5c);
 *(volatile unsigned short*)0x0400100c=(*(volatile unsigned short*)0x0400100c&~3)|1;
 *(volatile unsigned short*)0x04001008=(*(volatile unsigned short*)0x04001008&~3)|2;
 *(volatile unsigned short*)0x0400100a=(*(volatile unsigned short*)0x0400100a&~3)|3;
 *(volatile unsigned*)0x04001000=(*(volatile unsigned*)0x04001000&~0x1f00)|0x1700;
 Selection_EnableTouchInput((int)(p+0x38));Selection_EnableDirectionalInput((int)(p+0x38));InitializeMatchingSelectionOverlay(p);RefreshHeadingAndUploadFontTiles((char*)p);p[0x63e]=0;p[0x63c]=1;
 }
 }else{
 if(p[0x63e]==0){
 unsigned context=DisplayContext_GetGlobalInstance();DisplayContext_IgnoreTransitionParameter((void*)context,12);DisplayContext_IgnoreRequest(context,503,0);p[0x63e]++;
 }else if(p[0x63e]==1){
 DisplayContext_GetGlobalInstance();if(DisplayContext_ReportRequestComplete()){
 *(unsigned*)(p+0x658)=*(unsigned*)(TextContext_GetSharedInstance()+0x5c);
 char* child=(char*)p+0xf4;
 for(int i=0;i<2;child+=32,i++){
 Graphics_SetTextBackgroundScreenSize((int)child,0);unsigned format=AdvanceHeadingResourceInitialization_UnknownRoleInitializedBytes_Variant2[i];unsigned mode=AdvanceHeadingResourceInitialization_UnknownRoleInitializedBytes[i];((FormatByte*)(child+0x1c))->low=0;((FormatByte*)(child+0x1c))->high=format;
 Graphics_SetBackgroundColorMode((Owner*)child,mode);Graphics_AllocateAndClearConfiguredBuffer(child,(SafeAllocator*)p);Graphics_InvokeTwoIndexTransferCallback((State*)child,0,0);
 }
 *(volatile unsigned short*)0x0400000a=(*(volatile unsigned short*)0x0400000a&0x43)|0x1d00;
 *(volatile unsigned short*)0x0400000c=(*(volatile unsigned short*)0x0400000c&0x43)|0x1e00;
 ColorEffect_ConfigureAlphaBlend(0x04000050,2,1,10,6);
 *(unsigned*)(p+0x650)=_ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader,AdvanceHeadingResourceInitialization_PathDataAniBgTmPac,0);p[0x63e]++;
 }
 }else if(p[0x63e]==2){
 if(_ZN16BackgroundLoader13GetTaskStatusEi(loader,*(unsigned*)(p+0x650))){
 char* scratch=0;void* file;unsigned size;char* blocks[2];unsigned lengths[2];
 _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,*(int*)(p+0x650),&file,&size);
 int count=ResourceFile_CountActiveStrideRecords((Record*)file);
 for(int i=0;i<count;i++)blocks[i]=ResourceFile_GetPayloadByIndex((char*)file,i,&scratch,&lengths[i]);
 for(int i=0;i<count;i++)if(blocks[i])((int(*)(Owner*,const void*,unsigned,unsigned))Graphics_LoadTaggedLayerResource)((Owner*)(p+0x114),blocks[i],(unsigned)p,lengths[i]);
 _ZN16BackgroundLoader10RemoveTaskEi(loader,*(int*)(p+0x650));*(int*)(p+0x650)=-1;
 Tilemap_FillClippedRectangle((TilemapOwner*)(p+0xf4),0,0,0,32,25,0);Graphics_CleanAndTransferScreenBuffer((char*)p+0xf4,0);
 Tilemap_FillClippedRectangle((TilemapOwner*)(p+0x114),0,0,0,32,25,0);Graphics_CleanAndTransferScreenBuffer((char*)p+0x114,0);
 *(char**)(p+0x654)=_ZN13SafeAllocator8AllocateEj((unsigned)p,0x3c00);
 for(int i=0;i<3;i++){
 TextCanvas_AllocateTilemapAndBindPixels((char*)p+0x134+i*224,(SafeAllocator*)p,*(int*)(p+0x654),0x380);*(unsigned char**)(p+0x138+i*224)=p+0x114;
 }
 *(unsigned char**)(p+0xd0)=p+0xf4;p[0xea]=2;Selection_AttachBackwardLinkedDisplayRecords(p+0x38,(char*)p+0x134,3);
 *(unsigned*)(p+0x650)=_ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(loader,AdvanceHeadingResourceInitialization_PathDataBinMenuStrSuGp2,AdvanceHeadingResourceInitialization_MarkupStrSuLGNat,0);p[0x63e]++;
 }
 }else if(p[0x63e]==3){
 if(_ZN16BackgroundLoader13GetTaskStatusEi(loader,*(unsigned*)(p+0x650))){
 void* file;unsigned size;_ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,*(int*)(p+0x650),&file,&size);
 _ZN13SafeAllocator5ResetEv(p+0x60c);ResourceStringTable_CopySerializedData((unsigned*)(p+0x620),p+0x60c,(unsigned char*)file,size);
 _ZN16BackgroundLoader10RemoveTaskEi(loader,*(int*)(p+0x650));*(int*)(p+0x650)=-1;p[0x63e]++;
 }
 }else if(p[0x63e]==4){
 *(volatile unsigned short*)0x04000008=(*(volatile unsigned short*)0x04000008&~3)|2;
 *(volatile unsigned short*)0x0400000a=(*(volatile unsigned short*)0x0400000a&~3)|1;
 *(volatile unsigned short*)0x0400000c=(*(volatile unsigned short*)0x0400000c&~3);
 *(volatile unsigned*)0x04000000=(*(volatile unsigned*)0x04000000&~0x1f00)|0x1700;
 Selection_EnableTouchInput((int)(p+0x38));Selection_EnableDirectionalInput((int)(p+0x38));InitializeMatchingSelectionOverlay(p);RefreshHeadingAndUploadFontTiles((char*)p);p[0x63e]=0;p[0x63c]=1;
 }
 }
}
