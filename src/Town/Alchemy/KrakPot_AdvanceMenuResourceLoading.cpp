#include <globaldefs.h>
ARM
extern "C" int Graphics_AllocateScreenDescriptors(...);
extern "C" int BackgroundLoader_QueueThreeNamedGP2Files(...);
extern "C" int ResourceStringLoader_Reset(...);
extern "C" int Menu_ResetLayout(...);
extern "C" int ScriptRecordTable_Reset(...);
extern "C" int ColorEffect_ConfigureAlphaBlend(...);
extern "C" int ResourceStringTable_CopySerializedData(...);
extern "C" int Text_CopyNameTableIntoAllocator(...);
extern "C" int Graphics_SetBackgroundColorMode(...);
extern "C" int Graphics_LoadTaggedLayerResource(...);
extern "C" int DisplayContext_IgnoreCommand(...);
extern "C" int TextCanvas_FindDisplayPartByKey(...);
extern "C" int ResourceFile_GetPayloadByIndex(...);
extern "C" int GameState_ReadPResources(...);
extern "C" int GetSubBG0ScreenBase(...);
extern "C" int Graphics_AllocateAndClearConfiguredBuffer(...);
extern "C" int Graphics_DispatchDataByResourceMagic(...);
extern "C" int Graphics_InitializeCanvasTransferState(...);
extern "C" int Graphics_InvokeTwoIndexTransferCallback(...);
extern "C" int Graphics_WriteHalfwordRegister35CAndDisplayControl(...);
extern "C" int DisplayContext_IgnoreHook(...);
extern "C" int DisplayLayout_Initialize(...);
extern "C" int Graphics_InitializeSpriteResourceBuffers(...);
extern "C" int LinkedList_SelectAndRebuildNodes(...);
extern "C" int TextCanvas_AllocateTilemapAndBindPixels(...);
extern "C" int TextCanvas_EnableEntryHorizontalCentering(...);
extern "C" int Text_InitializeNameTableHeader(...);
extern "C" int TextCanvas_CreateAndConfigureDisplayPart(...);
extern "C" int DisplayLayout_AttachBackwardLinkedCanvases(...);
extern "C" int DisplayContext_GetGlobalInstance(...);
extern "C" int PollAndExecuteLoadedScriptBundles(...);
extern "C" int TextMarkup_ExpandAndWrapText(...);
extern "C" int TextContext_GetSharedInstance(...);
extern "C" int ResourceStringTable_GetTextByKey(...);
extern "C" int ResourceFile_CountActiveStrideRecords(...);
extern "C" int ResourceHandle_SwitchTargetUnlessBlocked(...);
extern "C" int KrakPot_FindLayoutHitRegion(...);
extern "C" int DisplayContext_ReportRequestComplete(...);
extern "C" int Script_ExecuteWithPairContextAndResetResult(...);
extern "C" int TextCanvas_SetEntryTextPointer(...);
extern "C" int TextCanvas_EnableEntryExtendedFontRange(...);
extern "C" int Graphics_SetTextBackgroundScreenSize(...);
extern "C" int TextCanvas_InitializeLayoutAndTransferDefaults(...);
extern "C" int Graphics_CleanAndTransferScreenBuffer(...);
extern "C" int G3X_SetClearColor(...);
extern "C" int TextCanvas_SetGroupInteriorFillSuppressed(...);
extern "C" int _ZN13SafeAllocator5ResetEv(...);
extern "C" int _ZN16BackgroundLoader10RemoveTaskEi(...);
extern "C" int _ZN16BackgroundLoader11GetInstanceEv(...);
extern "C" int _ZN16BackgroundLoader13GetTaskStatusEi(...);
extern "C" int _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(...);
extern "C" int _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(...);
extern "C" int _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(...);
extern "C" int _ZN9GameState11GetInstanceEv(...);
extern "C" int __clear(...);
extern "C" int Memory_WriteWordAtOffset0(...);
extern "C" int KrakPot_ApplySavedRecipeDiscoveryFlags(...);
extern "C" int KrakPot_BindRecipeProgressRecords(...);
extern "C" int KrakPot_ResetRecipePagination(...);
extern "C" int KrakPot_RebuildAvailableIngredientInventory(...);
extern "C" int LoadRelativeLayoutRecords(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);extern "C" char* strcpy(char*,const char*);extern "C" int sprintf(char*,const char*,...);
// Original data: arm9/main @ 0x2109bf4; symbol: data_02109bf4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage_Variant2[];
extern "C" char KrakPot_AdvanceMenuResourceLoading_PathDataBinMenuStrRenGp2[];
extern "C" char KrakPot_AdvanceMenuResourceLoading_MarkupStrRenLGNat[];
extern "C" char KrakPot_AdvanceMenuResourceLoading_PathDataBinRecipeGp2[];
extern "C" char KrakPot_AdvanceMenuResourceLoading_MarkupRecipeLGBin[];
extern "C" char KrakPot_AdvanceMenuResourceLoading_PathDataAniBgKamaelPac[];
extern "C" char KrakPot_AdvanceMenuResourceLoading_PathDataAniLayRrbGp2[];
extern "C" char KrakPot_AdvanceMenuResourceLoading_MarkupLayRrbLGLia[];
extern "C" char KrakPot_AdvanceMenuResourceLoading_PathDataAniOrrbGp2[];
extern "C" char KrakPot_AdvanceMenuResourceLoading_MarkupOrrbLGPac[];
extern "C" char KrakPot_AdvanceMenuResourceLoading_PathDataPrmItemnameGp2[];
extern "C" char KrakPot_AdvanceMenuResourceLoading_MarkupItemnameLGNat[];
extern "C" char KrakPot_AdvanceMenuResourceLoading_PathDataBinMenuBmRrbGp2[];
extern "C" char KrakPot_AdvanceMenuResourceLoading_TextBmRrb[];

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov006 @ 0x0215A5FC; symbol: AdvanceSeventeenStageDisplayResourceInitialization.
extern "C" void KrakPot_AdvanceMenuResourceLoading(char*self){

int state=_ZN9GameState11GetInstanceEv();GameState_ReadPResources(state);int loader=_ZN16BackgroundLoader11GetInstanceEv();unsigned phase=B(self,0x390);
if(phase==0){if(!(H(self,0x394)&2))ResourceHandle_SwitchTargetUnlessBlocked(Main_UnknownRoleZeroInitializedStorage_Variant2,8);Graphics_WriteHalfwordRegister35CAndDisplayControl(0,0,0,0);G3X_SetClearColor(0,0,32767,0,0);int display=DisplayContext_GetGlobalInstance();DisplayContext_IgnoreHook(display);DisplayContext_IgnoreCommand(display,108,509,0,0);B(self,0x390)++;}
else if(phase==1){if(DisplayContext_ReportRequestComplete(DisplayContext_GetGlobalInstance()))B(self,0x390)++;}
else if(phase==2){W(self,0x354)=_ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(loader,KrakPot_AdvanceMenuResourceLoading_PathDataBinMenuStrRenGp2,KrakPot_AdvanceMenuResourceLoading_MarkupStrRenLGNat,0);B(self,0x390)++;}
else if(phase==3){if(!_ZN16BackgroundLoader13GetTaskStatusEi(loader,W(self,0x354)))return;void*data;unsigned size;_ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,W(self,0x354),&data,&size);if(data){char*alloc=P(self,12)+20;_ZN13SafeAllocator5ResetEv(alloc);ResourceStringLoader_Reset(self+344);ResourceStringTable_CopySerializedData(self+344,alloc,data,size);}_ZN16BackgroundLoader10RemoveTaskEi(loader,W(self,0x354));W(self,0x354)=-1;B(self,0x390)++;}
else if(phase==4){W(self,0x354)=_ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(loader,KrakPot_AdvanceMenuResourceLoading_PathDataBinRecipeGp2,KrakPot_AdvanceMenuResourceLoading_MarkupRecipeLGBin,0);B(self,0x390)++;}
else if(phase==5){if(!_ZN16BackgroundLoader13GetTaskStatusEi(loader,W(self,0x354)))return;void*data;unsigned size;_ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,W(self,0x354),&data,&size);if(data){char*alloc=P(self,12);_ZN13SafeAllocator5ResetEv(alloc);ScriptRecordTable_Reset(self+332);Script_ExecuteWithPairContextAndResetResult(self+332,alloc,data,size);}_ZN16BackgroundLoader10RemoveTaskEi(loader,W(self,0x354));W(self,0x354)=-1;B(self,0x390)++;}
else if(phase==6){volatile unsigned short*bg=(volatile unsigned short*)0x04001008;bg[0]=(bg[0]&0x43)|0x1010;bg[1]=(bg[1]&0x43)|0x1110;bg[2]=(bg[2]&0x43)|0x1210;volatile unsigned short*bg3=(volatile unsigned short*)0x0400100e;*bg3=(*bg3&0x43)|0x1300;memset((void*)GetSubBG0ScreenBase(),0,2048);*(volatile unsigned*)0x04001010=0;_ZN13SafeAllocator5ResetEv(P(self,12)+60);Graphics_InitializeCanvasTransferState(self+84);Graphics_SetTextBackgroundScreenSize(self+84,0);struct Format{unsigned char low:4;unsigned char high:4;};((Format*)(self+112))->low=1;((Format*)(self+112))->high=3;Graphics_SetBackgroundColorMode(self+84,3);Graphics_InvokeTwoIndexTransferCallback(self+84,0,0);Graphics_AllocateAndClearConfiguredBuffer(self+84,P(self,12)+60);Graphics_AllocateScreenDescriptors(self+84,7,P(self,12)+60);W(self,0x354)=_ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader,KrakPot_AdvanceMenuResourceLoading_PathDataAniBgKamaelPac,0);B(self,0x390)++;}
else if(phase==7){if(!_ZN16BackgroundLoader13GetTaskStatusEi(loader,W(self,0x354)))return;char*out;void*data;unsigned size;_ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,W(self,0x354),&data,&size);char*block;int count=ResourceFile_CountActiveStrideRecords(data);for(int i=0;i<count;i++){unsigned bytes;block=C(ResourceFile_GetPayloadByIndex(data,i,&out,&bytes));if(!block)continue;if(i==0){for(int j=0;j<2;j++){char*canvas=P(self,28)+j*32;Graphics_InitializeCanvasTransferState(canvas);Graphics_SetTextBackgroundScreenSize(canvas,0);struct Format{unsigned char low:4;unsigned char high:4;};((Format*)(canvas+28))->low=1;((Format*)(canvas+28))->high=(unsigned char)(j+1);Graphics_InvokeTwoIndexTransferCallback(canvas,0,0);Graphics_SetBackgroundColorMode(canvas,j+1);Graphics_AllocateAndClearConfiguredBuffer(canvas,P(self,12)+60);Graphics_LoadTaggedLayerResource(canvas,block,P(self,12)+60,bytes);}}else Graphics_LoadTaggedLayerResource(self+84,block,P(self,12)+60,bytes);}Graphics_CleanAndTransferScreenBuffer(self+84,0);_ZN16BackgroundLoader10RemoveTaskEi(loader,W(self,0x354));W(self,0x354)=-1;B(self,0x390)++;}
else if(phase==8){char*alloc=P(self,12);_ZN13SafeAllocator5ResetEv(alloc+80);for(unsigned char i=0;i<7;i++){char*canvas=P(self,32)+i*224;TextCanvas_InitializeLayoutAndTransferDefaults(canvas);TextCanvas_AllocateTilemapAndBindPixels(canvas,alloc+80,W(self,8),1536);P(canvas,4)=P(self,28);}W(self,0x354)=_ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(loader,KrakPot_AdvanceMenuResourceLoading_PathDataAniLayRrbGp2,KrakPot_AdvanceMenuResourceLoading_MarkupLayRrbLGLia,0);B(self,0x390)++;}
else if(phase==9){if(!_ZN16BackgroundLoader13GetTaskStatusEi(loader,W(self,0x354)))return;void*data;unsigned size;_ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,W(self,0x354),&data,&size);if(data){char*alloc=P(self,12)+120;_ZN13SafeAllocator5ResetEv(alloc);Menu_ResetLayout(self+256);LoadRelativeLayoutRecords(self+256,alloc,data,size);char*record=C(KrakPot_FindLayoutHitRegion(self+256,1));if(record)B(record,22)&=~1;record=C(KrakPot_FindLayoutHitRegion(self+256,35));if(record)B(record,22)&=~1;record=C(KrakPot_FindLayoutHitRegion(self+256,36));if(record)B(record,22)&=~1;}_ZN16BackgroundLoader10RemoveTaskEi(loader,W(self,0x354));W(self,0x354)=-1;B(self,0x390)++;}
else if(phase==10){Graphics_InitializeSpriteResourceBuffers(self+172);B(self,252)=1;P(self,236)=P(self,36);H(self,248)=29;W(self,232)=W(P(self,24),32);W(self,0x354)=_ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(loader,KrakPot_AdvanceMenuResourceLoading_PathDataAniOrrbGp2,KrakPot_AdvanceMenuResourceLoading_MarkupOrrbLGPac,0);B(self,0x390)++;}
else if(phase==11){if(!_ZN16BackgroundLoader13GetTaskStatusEi(loader,W(self,0x354)))return;char*out;void*data;unsigned size;_ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,W(self,0x354),&data,&size);int count=ResourceFile_CountActiveStrideRecords(data);char*alloc=P(self,12)+140;_ZN13SafeAllocator5ResetEv(alloc);for(int i=0;i<count;i++){unsigned bytes;char*block=C(ResourceFile_GetPayloadByIndex(data,i,&out,&bytes));if(block)Graphics_DispatchDataByResourceMagic(self+172,block,bytes,alloc);}_ZN16BackgroundLoader10RemoveTaskEi(loader,W(self,0x354));W(self,0x354)=-1;B(self,0x390)++;for(int i=0;i<8;i++)B(P(self,36)+(i+18)*40,34)=24;}
else if(phase==12){W(self,0x354)=_ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(loader,KrakPot_AdvanceMenuResourceLoading_PathDataPrmItemnameGp2,KrakPot_AdvanceMenuResourceLoading_MarkupItemnameLGNat,0);B(self,0x390)++;}
else if(phase==13){if(!_ZN16BackgroundLoader13GetTaskStatusEi(loader,W(self,0x354)))return;void*data;unsigned size;_ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,W(self,0x354),&data,&size);if(data){char*alloc=P(self,12)+40;_ZN13SafeAllocator5ResetEv(alloc);Text_InitializeNameTableHeader(self+368);Text_CopyNameTableIntoAllocator(self+368,alloc,data,size);}_ZN16BackgroundLoader10RemoveTaskEi(loader,W(self,0x354));W(self,0x354)=-1;B(self,0x390)++;}
else if(phase==14){char*alloc=P(self,12)+100;_ZN13SafeAllocator5ResetEv(alloc);DisplayLayout_Initialize(P(self,20));BackgroundLoader_QueueThreeNamedGP2Files(P(self,20),alloc,KrakPot_AdvanceMenuResourceLoading_PathDataBinMenuBmRrbGp2,KrakPot_AdvanceMenuResourceLoading_TextBmRrb);B(self,0x390)++;}
else if(phase==15){int result=PollAndExecuteLoadedScriptBundles(P(self,20));if(result==0)B(self,0x390)++;if(result<0)B(self,0x38f)=12;}
else if(phase==16){TextCanvas_EnableEntryExtendedFontRange(P(self,20),1);char*display=P(self,20);P(display,44)=P(self,28);B(display,56)=2;DisplayLayout_AttachBackwardLinkedCanvases(P(self,20),P(self,32),7);B(P(self,20),58)=1;TextCanvas_EnableEntryHorizontalCentering(P(self,20),32);TextCanvas_EnableEntryHorizontalCentering(P(self,20),62);volatile unsigned short*bg=(volatile unsigned short*)0x04001008;bg[0]&=~3;bg[1]=(bg[1]&~3)|1;bg[2]=(bg[2]&~3)|2;bg[3]=(bg[3]&~3)|3;*(volatile unsigned*)0x04001000=(*(volatile unsigned*)0x04001000&~0x1f00)|0x1f00;ColorEffect_ConfigureAlphaBlend(0x04001050,4,24,10,6);KrakPot_RebuildAvailableIngredientInventory(self);B(self,0x38f)=1;B(self,0x390)=0;KrakPot_ApplySavedRecipeDiscoveryFlags(self+116,self+332,W(self,56),471);LinkedList_SelectAndRebuildNodes(self+332,-1,-1,0,0,(short*)(self+860));short count=0;LinkedList_SelectAndRebuildNodes(self+332,*(signed char*)(self+900),*(signed char*)(self+901),B(self,902),16,&count);int head=W(self,332);W(self,44)=head;W(self,48)=head;KrakPot_ResetRecipePagination(self);KrakPot_BindRecipeProgressRecords(self+116,W(self,56),471);Memory_WriteWordAtOffset0(self+116,self+332);if(!(H(self,0x394)&2)){TextCanvas_SetGroupInteriorFillSuppressed(P(self,20),0,1);TextCanvas_SetGroupInteriorFillSuppressed(P(self,20),1,1);TextCanvas_CreateAndConfigureDisplayPart(P(self,20),0);TextCanvas_CreateAndConfigureDisplayPart(P(self,20),1);char*record=C(TextCanvas_FindDisplayPartByKey(P(self,20),1));if(record){H(record,184)=12;H(record,186)=16;}char text[1024];__clear(text,1024);int formatter=TextContext_GetSharedInstance();int format=ResourceStringTable_GetTextByKey(self+344,0);TextMarkup_ExpandAndWrapText(formatter,12,format,text,227,0,1);TextCanvas_SetEntryTextPointer(P(self,20),1,text);TextCanvas_CreateAndConfigureDisplayPart(P(self,20),1);}}

}
