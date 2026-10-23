#include <globaldefs.h>
ARM
#define W(o) (*(unsigned*)(self+(o)))
#define B(o) (*(unsigned char*)(self+(o)))
#define H(o) (*(short*)(self+(o)))
#define P(o) (*(char**)(self+(o)))
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv(...);
extern "C" void _ZN13SafeAllocator5ResetEv(...);
extern "C" char* _ZN13SafeAllocator8AllocateEj(...);
extern "C" void Resource_AllocateFourTextBuffers(...);
extern "C" void CharacterStatus_InitializeSubDisplaySnapshot(...);
extern "C" void ResourceTracks_ClearBindingOwner(...);
extern "C" void Object_InitializeAnimationControlDefaults(...);
extern "C" void DisplayLayout_Initialize(...);
extern "C" void Graphics_InitializeCanvasTransferState(...);
extern "C" void TextCanvas_InitializeLayoutAndTransferDefaults(...);
extern "C" int _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(...);
extern "C" unsigned _ZN16BackgroundLoader13GetTaskStatusEi(...);
extern "C" void _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(...);
extern "C" void ResourceStringTable_CopySerializedData(...);
extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(...);
extern "C" void Graphics_SetTextBackgroundScreenSize(...);
extern "C" void Graphics_SetBackgroundColorMode(...);
extern "C" void Graphics_AllocateAndClearConfiguredBuffer(...);
extern "C" void Graphics_InvokeTwoIndexTransferCallback(...);
extern "C" void Graphics_AllocateScreenDescriptors(...);
extern "C" void ColorEffect_ConfigureAlphaBlend(...);
extern "C" int ResourceFile_CountActiveStrideRecords(...);
extern "C" char* ResourceFile_GetPayloadByIndex(...);
extern "C" int Graphics_LoadTaggedLayerResource(void*,const void*,unsigned,unsigned);
extern "C" void Tilemap_FillClippedRectangle(...);
extern "C" void Graphics_CleanAndTransferScreenBuffer(...);
extern "C" void TextCanvas_AllocateTilemapAndBindPixels(...);
extern "C" void BackgroundLoader_QueueThreeNamedGP2Files(...);
extern "C" int PollAndExecuteLoadedScriptBundles(...);
extern "C" char* TextContext_GetSharedInstance(...);
extern "C" void TextCanvas_EnableEntryHorizontalCentering(...);
extern "C" void TextCanvas_EnableEntryMarkupWithControlByte(...);
extern "C" void TextCanvas_SetEntryTextAlignmentMode(...);
extern "C" void Graphics_InitializeSpriteTransformDefaults(...);
extern "C" void SpriteAnimation_ResetTrackList(...);
extern "C" void Window_AllocateAndInitializeEntryArraysAndControls(...);
extern "C" int _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(...);
extern "C" void Graphics_DispatchDataByResourceMagic(...);
extern "C" void Graphics_OffsetCellOamStartIndices(...);
extern "C" void DisplayLayout_AttachBackwardLinkedCanvases(...);
extern "C" void TextCanvas_DistributeGroupEntriesVertically(...);
extern "C" int Network_ClassifyConnectionByProtagonistIndex(...);
extern "C" char* GameState_GetSerializedProgressState(...);
extern "C" char* GameResources_GetInstance(...);
extern "C" void* _ZN9GameState11GetInstanceEv(...);
extern "C" char* _ZN9GameState14GetProtagonistEv(...);
extern "C" unsigned BitArray_ReadNonnegativeIndexMask(...);
extern "C" void BitArray_SetIndexedBoolean(...);
extern "C" char Tavern_AdvancePartyMenuResourceLoading_PathDataBinMenuStrLavGp2[];
extern "C" char Tavern_AdvancePartyMenuResourceLoading_MarkupStrLavLGNat[];
extern "C" char Tavern_AdvancePartyMenuResourceLoading_PathDataBinMenuStrLuiGp2[];
extern "C" char Tavern_AdvancePartyMenuResourceLoading_MarkupStrLuiLGNat[];
// Original data: arm9/ov003 @ 0x217f454; symbol: data_ov003_0217f454.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 010000000200000003000000.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov003.md.
extern "C" unsigned TavernAdvancePartyMenuResourceLoading_UnknownRoleInitializedBytes[];
// Original data: arm9/ov003 @ 0x217f460; symbol: data_ov003_0217f460.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 010000000000000002000000.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov003.md.
extern "C" unsigned TavernAdvancePartyMenuResourceLoading_UnknownRoleInitializedBytes_Variant2[];
extern "C" char Tavern_AdvancePartyMenuResourceLoading_PathDataAniBgLidGp2[];
extern "C" char Tavern_AdvancePartyMenuResourceLoading_MarkupBgLidLGPac[];
extern "C" char Tavern_AdvancePartyMenuResourceLoading_PathDataBinMenuBmLuiGp2[];
extern "C" char Tavern_AdvancePartyMenuResourceLoading_TextBmLui[];
// Original data: arm9/ov003 @ 0x217f46c; symbol: data_ov003_0217f46c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex a600a700a800a900ab00ffffafabffff9901000000b8ffff.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov003.md.
extern "C" short TavernAdvancePartyMenuResourceLoading_UnknownRoleInitializedBytes_Variant3[];
extern "C" char Tavern_AdvancePartyMenuResourceLoading_PathDataAniObjLuida2Pac[];

// Original: arm9/ov003 @ 0x021615BC; symbol: Resource_AdvanceCanvasAndMenuInitialization; size: 0xa60.
// Advances nine asynchronous resource-loading stages, initializes canvases and selects initial message state.
extern "C" void Tavern_AdvancePartyMenuResourceLoading(char *self){
 void *loader=_ZN16BackgroundLoader11GetInstanceEv();unsigned char *canvas;
 if(B(0x4a4)==0){
 _ZN13SafeAllocator5ResetEv(self+0x228);
P(792)=_ZN13SafeAllocator8AllocateEj(self+0x228,120);
P(796)=_ZN13SafeAllocator8AllocateEj(self+0x228,28);
P(800)=_ZN13SafeAllocator8AllocateEj(self+0x228,304);
P(804)=_ZN13SafeAllocator8AllocateEj(self+0x228,64);
P(808)=_ZN13SafeAllocator8AllocateEj(self+0x228,96);
P(812)=_ZN13SafeAllocator8AllocateEj(self+0x228,896);
P(916)=_ZN13SafeAllocator8AllocateEj(self+0x228,16);
Resource_AllocateFourTextBuffers(self);CharacterStatus_InitializeSubDisplaySnapshot(P(0x318),0,-1);ResourceTracks_ClearBindingOwner(P(0x31c));Object_InitializeAnimationControlDefaults(P(0x320));DisplayLayout_Initialize(P(0x324));
 for(int i=0;i<3;++i)Graphics_InitializeCanvasTransferState(P(0x328)+i*32);
 for(int i=0;i<4;++i)TextCanvas_InitializeLayoutAndTransferDefaults(P(0x32c)+i*224);
 if(W(0x464)&0x10000)W(0x46c)=_ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(loader,Tavern_AdvancePartyMenuResourceLoading_PathDataBinMenuStrLavGp2,Tavern_AdvancePartyMenuResourceLoading_MarkupStrLavLGNat,0);
 else W(0x46c)=_ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(loader,Tavern_AdvancePartyMenuResourceLoading_PathDataBinMenuStrLuiGp2,Tavern_AdvancePartyMenuResourceLoading_MarkupStrLuiLGNat,0);
 ++B(0x4a4);
 }
 if(B(0x4a4)==1&&_ZN16BackgroundLoader13GetTaskStatusEi(loader,W(0x46c))){
 char *data;unsigned size;_ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,W(0x46c),&data,&size);
 _ZN13SafeAllocator5ResetEv(self+0x2b4);ResourceStringTable_CopySerializedData(self+0x2dc,self+0x2b4,data,size);_ZN16BackgroundLoader10RemoveTaskEi(loader,W(0x46c));W(0x46c)=-1;++B(0x4a4);
 }
 int iteration,initial;
 if(B(0x4a4)==2){
 _ZN13SafeAllocator5ResetEv(self+0x264);
 for(iteration=0;iteration<3;++iteration){canvas=(unsigned char*)P(0x328)+iteration*32;Graphics_SetTextBackgroundScreenSize(canvas,0);int format=TavernAdvancePartyMenuResourceLoading_UnknownRoleInitializedBytes[iteration];canvas[28]&=~15;canvas[28]=(canvas[28]&~0xf0)|((unsigned)(unsigned char)format<<28>>24);Graphics_SetBackgroundColorMode(canvas,TavernAdvancePartyMenuResourceLoading_UnknownRoleInitializedBytes_Variant2[iteration]);Graphics_AllocateAndClearConfiguredBuffer(canvas,self+0x264);Graphics_InvokeTwoIndexTransferCallback(canvas,0,0);if(format==3)Graphics_AllocateScreenDescriptors(canvas,5,self+0x264);}
 volatile unsigned short *bg=(volatile unsigned short*)0x400000a;
 bg[0]=(bg[0]&0x43)|0x1e00;bg[1]=(bg[1]&0x43)|0x1f00;bg[2]=(bg[2]&0x43)|0x1d08;
 ColorEffect_ConfigureAlphaBlend(0x4000050,2,9,10,6);
 W(0x46c)=_ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(loader,Tavern_AdvancePartyMenuResourceLoading_PathDataAniBgLidGp2,Tavern_AdvancePartyMenuResourceLoading_MarkupBgLidLGPac,0);++B(0x4a4);
 }
 if(B(0x4a4)==3&&_ZN16BackgroundLoader13GetTaskStatusEi(loader,W(0x46c))){
 char *tag,*data;unsigned size;char *blocks[8];unsigned sizes[8];
 _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,W(0x46c),&data,&size);int count=ResourceFile_CountActiveStrideRecords(data);int i;
 for(i=0;i<count;++i)blocks[i]=ResourceFile_GetPayloadByIndex(data,i,&tag,&sizes[i]);
 for(i=0;i<count;++i){if(blocks[i]){if(i==0)Graphics_LoadTaggedLayerResource(P(0x328)+32,blocks[i],(unsigned)(self+0x264),sizes[i]);else Graphics_LoadTaggedLayerResource(P(0x328)+64,blocks[i],(unsigned)(self+0x264),sizes[i]);}}
 _ZN16BackgroundLoader10RemoveTaskEi(loader,W(0x46c));W(0x46c)=-1;
 for(i=0;i<3;++i){char *canvas=P(0x328)+i*32;Tilemap_FillClippedRectangle(canvas,0,0,0,32,25,0);Graphics_CleanAndTransferScreenBuffer(canvas,0);}
 _ZN13SafeAllocator5ResetEv(self+0x278);P(0x398)=_ZN13SafeAllocator8AllocateEj(self+0x278,0x6000);
 for(iteration=0;iteration<4;++iteration){canvas=(unsigned char*)P(0x32c)+iteration*224;TextCanvas_AllocateTilemapAndBindPixels(canvas,self+0x278,P(0x398),0x400);*(char**)(canvas+4)=P(0x328)+32;}
 ++B(0x4a4);
 }
 if(B(0x4a4)==4){_ZN13SafeAllocator5ResetEv(self+0x28c);BackgroundLoader_QueueThreeNamedGP2Files(P(0x324),self+0x28c,Tavern_AdvancePartyMenuResourceLoading_PathDataBinMenuBmLuiGp2,Tavern_AdvancePartyMenuResourceLoading_TextBmLui);++B(0x4a4);}
 if(B(0x4a4)==5){int status=PollAndExecuteLoadedScriptBundles(P(0x324));if(status==0)++B(0x4a4);if(status<0)B(0x4a3)=16;}
 if(B(0x4a4)==6){
 if(W(0x464)&0x20000){char *owner=TextContext_GetSharedInstance();if(*(int*)(owner+0x998)&&*(int*)(owner+0x9a0)!=3)return;W(0x464)&=~0x20000;}
 char *display=P(0x324);display[0x3b]=18;display[0x3c]=16;TextCanvas_EnableEntryHorizontalCentering(display,0);TextCanvas_EnableEntryHorizontalCentering(display,1);
 short *key=TavernAdvancePartyMenuResourceLoading_UnknownRoleInitializedBytes_Variant3;for(;;){int value=*key;if(value<0)break;TextCanvas_EnableEntryMarkupWithControlByte(display,value,0x90);++key;}
 TextCanvas_EnableEntryMarkupWithControlByte(display,0xc1,0x9c);TextCanvas_EnableEntryMarkupWithControlByte(display,0xc2,0x9c);TextCanvas_EnableEntryMarkupWithControlByte(display,0xc3,0x9c);
 short part=100;for(int i=0;i<8;++i){TextCanvas_SetEntryTextAlignmentMode(display,part,1);part=(short)(part+1);}
 _ZN13SafeAllocator5ResetEv(self+0x2a0);P(0x388)=_ZN13SafeAllocator8AllocateEj(self+0x2a0,1000);P(0x38c)=_ZN13SafeAllocator8AllocateEj(self+0x2a0,8);
 for(int i=0;i<25;++i)Graphics_InitializeSpriteTransformDefaults(P(0x388)+i*40);
 SpriteAnimation_ResetTrackList(P(0x38c));B(0x384)=0;P(0x374)=P(0x388);H(0x380)=25;P(0x370)=P(0x38c);
 _ZN13SafeAllocator5ResetEv(self+0x2c8);P(0x390)=_ZN13SafeAllocator8AllocateEj(self+0x2c8,36);
 Window_AllocateAndInitializeEntryArraysAndControls(P(0x390),0,1,P(0x38c),self+0x2c8,4,64);
 W(0x46c)=_ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader,Tavern_AdvancePartyMenuResourceLoading_PathDataAniObjLuida2Pac,0);++B(0x4a4);
 }
 if(B(0x4a4)==7&&_ZN16BackgroundLoader13GetTaskStatusEi(loader,W(0x46c))){
 char *tag,*data;unsigned size,blockSize;
 _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,W(0x46c),&data,&size);int count=ResourceFile_CountActiveStrideRecords(data);
 for(int i=0;i<count;++i){char *block=ResourceFile_GetPayloadByIndex(data,i,&tag,&blockSize);Graphics_DispatchDataByResourceMagic(self+0x334,block,blockSize,self+0x2a0);}
 Graphics_OffsetCellOamStartIndices(self+0x334,P(0x388),25,64);_ZN16BackgroundLoader10RemoveTaskEi(loader,W(0x46c));W(0x46c)=-1;++B(0x4a4);
 }
 if(B(0x4a4)==8){
 volatile unsigned short *bg=(volatile unsigned short*)0x4000008;char *display=P(0x324);
 bg[0]=(bg[0]&~3)|3;bg[1]=(bg[1]&~3)|1;bg[2]=bg[2]&~3;bg[3]=(bg[3]&~3)|2;
 *(volatile unsigned*)0x4000000=(*(volatile unsigned*)0x4000000&~0x1f00)|0x1f00;
 ColorEffect_ConfigureAlphaBlend(0x4000050,2,9,10,6);
 *(char**)(display+0x2c)=P(0x328);display[0x38]=2;DisplayLayout_AttachBackwardLinkedCanvases(display,P(0x32c),4);display[0x3a]=2;
 TextCanvas_DistributeGroupEntriesVertically(display,25);TextCanvas_DistributeGroupEntriesVertically(display,26);TextCanvas_DistributeGroupEntriesVertically(display,27);
 B(0x49e)=Network_ClassifyConnectionByProtagonistIndex(self);char *global=GameState_GetSerializedProgressState();
 if(W(0x464)&0x10000){B(0x4a3)=10;B(0x4a4)=0;}
 else if(B(0x4a1)==1){B(0x4a3)=4;B(0x4a4)=2;}
 else if(B(0x4a1)==2){B(0x4a3)=4;B(0x4a4)=0;}
 else if(B(0x4a1)==3){H(0x484)=80;H(0x486)=2;B(0x4a4)=0;B(0x4a5)=0;B(0x4a3)=1;W(0x464)|=16;H(0x482)=(unsigned char)(*(char**)(GameResources_GetInstance()+0x3734))[0xcd];}
 else if(B(0x4a1)==4){H(0x484)=13;H(0x486)=2;B(0x4a4)=0;B(0x4a5)=0;B(0x4a3)=1;W(0x464)|=8;}
 else{switch(B(0x49e)){case 0:case 1:initial=0;break;case 2:initial=3;break;}H(0x484)=initial;H(0x486)=-1;
 int normal=1;char *protagonist=_ZN9GameState14GetProtagonistEv(_ZN9GameState11GetInstanceEv());if(protagonist&&(**(unsigned**)(protagonist+0x130)&1)){H(0x484)=3;H(0x486)=-1;normal=0;}
 if(normal&&B(0x49e)!=2&&!BitArray_ReadNonnegativeIndexMask(global,global+0x8c,0x77e)){BitArray_SetIndexedBoolean(global,global+0x8c,0x77e,1);H(0x484)=75;H(0x486)=initial;}
 B(0x4a3)=1;B(0x4a4)=0;B(0x4a5)=0;}
 W(0x464)|=0x1000;B(0x4a7)=0;
 }
}
