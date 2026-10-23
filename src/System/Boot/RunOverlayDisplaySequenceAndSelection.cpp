#include <globaldefs.h>
#include <std_library_functions.h>
ARM
#pragma opt_propagation off
#pragma opt_common_subs off
struct GameState;struct AllocatorUnion;struct SafeAllocator;struct Owner;struct State;struct Record;struct TilemapOwner;struct GridSelection;struct Object;struct LoadingOwner;struct Overlay20TimedState;struct Overlay20Grids;struct Overlay20AllocatorOwner;
struct Overlay20BrightnessTransition {float current;int target,duration;};
struct Overlay20TimedState {unsigned char pad[0x4e4];int countdown;Overlay20BrightnessTransition mainBrightness,subBrightness;inline bool HasCountdown()const{return countdown>0;}inline bool HasSubTransition()const{return subBrightness.duration>0;}};
struct Nibbles {unsigned char low:4,high:4;};
struct Canvas {char pad[28];Nibbles flags;};
struct Frame {unsigned blockSize,fileSize;void* file;char* blockName;char buffer[128];};
inline int GetSdkBuild(){return 0x7539;}
inline int GetWifiBuild(){return 0x7533;}
inline int GetCryptoBuild(){return 0x7533;}
inline int GetDownloadBuild(){return 0x7536;}
inline int GetSwcBuild(){return 0x7531;}
extern "C" {
void* _ZN9GameState11GetInstanceEv();unsigned char GameState_ReadByteAtOffset4(GameState*);
unsigned GameState_GetStartupDispatchMode(GameState*);void GameState_SetUnknown7f6c(GameState*,unsigned);
void GameState_SetUnk4Element0(GameState*,unsigned char);void GameState_WriteUnknownF70(GameState*,unsigned char);
void System_WaitForInterruptOneAfterShortDelay();void Graphics_WriteSignedBrightnessMagnitudeAndMode(unsigned short*,int);void GX_DispOn();
void Graphics_SetMainBrightnessTarget(Overlay20TimedState*,int,int);void Graphics_SetSubBrightnessTarget(Overlay20TimedState*,int,int);
bool Graphics_HasActiveBrightnessTransition(Overlay20TimedState*);void Graphics_AdvanceBrightnessTransitions(Overlay20TimedState*);void BootScreen_AdvanceScreenDelay(Overlay20TimedState*);
void Graphics_WriteSwapControlAndToggleGlobalState(unsigned,unsigned);
void* AllocatorUnion_AllocateFourByteAligned(AllocatorUnion*,unsigned);void Memory_FreeThroughAllocatorUnion(void*,void*);
void _ZN13SafeAllocator11CreateTypeAEPvj(void*,void*,unsigned);void _ZN13SafeAllocator5ResetEv(void*);char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
void* _ZNK13SafeAllocator18GetSignedAllocatorEv(void*);void _ZN13SafeAllocator7DestroyEv(void*);
void Selection_InitializeDisplayController(State*);void Graphics_InitializeCanvasTransferState(char*);void TextCanvas_InitializeLayoutAndTransferDefaults(unsigned char*);
void MapVRAMBanksToMainBG(int);void MapVRAMBanksToMainObj(int);void MapVRAMBanksToTextureImage(int);void MapVRAMBanksToTexturePalette(int);
void ConfigureBackgroundLayerOneControlBits(unsigned,unsigned,unsigned,unsigned,unsigned);
void Graphics_SetTextBackgroundScreenSize(int,unsigned);void Graphics_SetBackgroundColorMode(Owner*,unsigned);
void Graphics_AllocateAndClearConfiguredBuffer(char*,SafeAllocator*);int Graphics_InvokeTwoIndexTransferCallback(State*,void*,void*);
void* _ZN16BackgroundLoader11GetInstanceEv();void _ZN16BackgroundLoader31ResetQueuedTasksAndScratchUsageEv(void*);
unsigned _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(void*,const char*,void*);
unsigned _ZN16BackgroundLoader13GetTaskStatusEi(void*,unsigned);void _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(void*,int,void**,unsigned*);
void _ZN16BackgroundLoader10RemoveTaskEi(void*,int);void _ZN16BackgroundLoader14RemoveAllLocksEv(void*);
int ResourceFile_CountActiveStrideRecords(Record*);char* ResourceFile_GetPayloadByIndex(char*,int,char**,unsigned*);
int Graphics_LoadTaggedLayerResource(void*,const void*,unsigned,unsigned);
void Tilemap_FillClippedRectangle(TilemapOwner*,unsigned,short,short,short,short,unsigned);
void Graphics_CleanAndTransferScreenBuffer(char*,void*);
void TextCanvas_AllocateTilemapAndBindPixels(char*,SafeAllocator*,int,unsigned);
void Selection_AttachBackwardLinkedDisplayRecords(unsigned char*,char*,unsigned char);
unsigned TextContext_GetSharedInstance();void __clear(void*,unsigned);
int Text_AppendFormattedXYPair(char*,int,int);int Text_AppendFormatString(char*,const char*);
unsigned Text_AppendCenteredTextUsingComputedWidth(char*,const char*,int,int);
void Window_PushTextCanvas(void*,void*,int,int,int,int,int,int);
int Window_UpdateCanvasesAndSelection(unsigned char*,unsigned);
void ProcessAllTwoHundredTwentyFourByteRecordsWhenBothPointersSet(void*);void Graphics_ResetCountedThirtyTwoByteTransfers(void*);void Window_ResetResourceTransfers(void*);
void Graphics_DrainTransferQueue();void Input_UpdatePowerKeysAndTouch();int Input_IsKeyMaskNewlyPressed(unsigned short*,unsigned);
void _Z28LockStagedTextureVRAMCopyingv();void _Z30UnlockStagedTextureVRAMCopyingv();void _Z26UpdateVRAMStagingVRAMBanksv();
void _Z26InitializeTextureImageVRAMjb(unsigned,bool);void _Z28InitializeTexturePaletteVRAMjb(unsigned,bool);
void VRAM_SaveStateAndReserveImagePaletteBytes(State*,unsigned,unsigned);
void Graphics_InitializeSelectionAndRenderState(unsigned char*);void Graphics_ClearAndStageSharedBuffers(char*);void Filesystem_LoadEmbeddedArchiveUsingScratchAllocator(char*);
void TextureVRAM_SnapshotAllocationBounds(char*);void Graphics_RestoreTextureImageAndPaletteVRAMState(void*);void TextWindow_StagePaletteAndRefreshRendering(char*);void Object_InvokeSaveTextureImageVRAMState(char*);
void G3X_SetClearColor(unsigned,unsigned,unsigned short,unsigned,int);
void Graphics_InitializeSubBackgroundCanvasAndDisplay(char*);void Graphics_InitializeDualScreenCanvasResources(char*);void Graphics_InitializeCanvasAndLoadSelectedArchive(char*,int);void Graphics_LoadDualScreenCanvasResources(unsigned char*);
void TextEntry_ResetGlyphCacheAndTextureAllocator(Owner*);void TextLayout_InitializeSelectionPanel(unsigned char*);
int SaveData_GetBankHeaderValidationStatus(int);void TextLayout_AppendConvertedLineAndUpdateWidths(char*,void*);void TextWindow_AdvanceTextForRequestedTicks(void*,int);void TextWindow_RenderAndTransferDisplayBuffers(void*,int);
void BootScreen_ConfigureMenuSelectionGrids(Overlay20Grids*,int,int);void TextLayout_ComputeSelectionPanelBounds(Object*,int,short);
void Grid_SelectIndexAndInvalidateTouchHistory(State*,int);void Grid_SelectIndexAndComputePageCoordinates(GridSelection*,int);
void BackgroundLoader_AdvanceThreePhaseArchiveAssetLoad(LoadingOwner*);void* Graphics_GetGlobalOamTransferState();void Graphics_InitializeSubOamStagingState(char*);
void SoundSfx_RestoreSecondaryHeapStateAndVolume(char*);void ResourceHandle_SwitchTargetUnlessBlocked(State*,int);
void Graphics_InitializeGeometryAndDisplayState();void Graphics_ResetGeometryMatrixStackState();
void UpdateDisplaySelectionAndSetGameStateByte4(unsigned char*);void Graphics_FlushTwoBackgroundBuffers();void Graphics_LoadAndClearEnabledOamScreens(unsigned char*);void Sound_UpdatePlaybackAndFlushCommands();
void BootScreen_ReleaseResourcesAndResetAudio(Overlay20AllocatorOwner*);
// Original data: arm9/ov020 @ 0x218d9b0; symbol: data_ov020_0218d9b0.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 44656275670000000000000000000000000000000000000000000000000000005374617274000000000000000000000000000000000000000000000000000000 ...; full span in module reference.
// Observed span: 224 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov020.md.
// Original data: arm9/ov020 @ 0x218da90; symbol: data_ov020_0218da90.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 44656275670000000000000000000000000000000000000000000000000000005374617274000000000000000000000000000000000000000000000000000000 ...; full span in module reference.
// Observed span: 256 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov020.md.
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2109bf4; symbol: data_02109bf4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern char Main_UnknownRoleZeroInitializedStorage_Variant3[],RunOverlayDisplaySequenceAndSelection_PathDataAniBgTmPac[],RunOverlayDisplaySequenceAndSelection_FormatSS[],RunOverlayDisplaySequenceAndSelection_TextVer035[],RunOverlayDisplaySequenceAndSelection_TextApr142010[],RunOverlayDisplaySequenceAndSelection_FormatNITROSDKDDD[],RunOverlayDisplaySequenceAndSelection_FormatNITROSYSTEMD[],RunOverlayDisplaySequenceAndSelection_FormatNITROWiFiDDD[],RunOverlayDisplaySequenceAndSelection_FormatNITROCRYPTODDD[],RunOverlayDisplaySequenceAndSelection_FormatDWCDLDDD[],RunOverlayDisplaySequenceAndSelection_FormatSWCDDD[],RunOverlayDisplaySequenceAndSelection_TextDRAGONQUESTIX[],RunOverlayDisplaySequenceAndSelection_TextXENLONProject[],RunOverlayDisplaySequenceAndSelection_TextLEVEL5INC[],RunOverlayDisplaySequenceAndSelection_UnknownRoleInitializedBytes_Variant2[],RunOverlayDisplaySequenceAndSelection_UnknownRoleInitializedBytes[],Main_UnknownRoleZeroInitializedStorage[],Main_UnknownRoleZeroInitializedStorage_Variant2[];
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2114e54; symbol: data_02114e54.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 112 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned short KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[];extern unsigned char Main_UnknownRoleZeroInitializedStorage_Variant4[];
}
#define W(o) (*(int*)(p+(o)))
#define H(o) (*(short*)(p+(o)))
#define B(o) (*(unsigned char*)(p+(o)))
#define R32(a) (*(volatile unsigned*)(a))
#define R16(a) (*(volatile unsigned short*)(a))
#define TIMED ((Overlay20TimedState*)p)
// Original: arm9/ov020 @ 0x0218B710; symbol: func_ov020_0218b710; size: 0x10AC.
// Runs overlay display/resource setup, timed brightness screens, input selection and cleanup.
extern "C" void RunOverlayDisplaySequenceAndSelection(char* p){
 GameState* state=(GameState*)_ZN9GameState11GetInstanceEv();
 System_WaitForInterruptOneAfterShortDelay();
 Graphics_WriteSignedBrightnessMagnitudeAndMode((unsigned short*)0x0400006c,-16);
 Graphics_WriteSignedBrightnessMagnitudeAndMode((unsigned short*)0x0400106c,-16);
 if(GameState_GetStartupDispatchMode(state)==1){
 Graphics_WriteSignedBrightnessMagnitudeAndMode((unsigned short*)0x0400006c,16);
 Graphics_WriteSignedBrightnessMagnitudeAndMode((unsigned short*)0x0400106c,16);
 }
 GX_DispOn();R32(0x04001000)|=0x10000;
 if(GameState_GetStartupDispatchMode(state)==1){
 Graphics_SetMainBrightnessTarget(TIMED,-16,2000);Graphics_SetSubBrightnessTarget(TIMED,-16,2000);
 while(1){if(!Graphics_HasActiveBrightnessTransition(TIMED))break;Graphics_AdvanceBrightnessTransitions(TIMED);System_WaitForInterruptOneAfterShortDelay();Graphics_WriteSwapControlAndToggleGlobalState(0,1);}
 }
 Graphics_WriteSignedBrightnessMagnitudeAndMode((unsigned short*)0x0400006c,-16);
 Graphics_WriteSignedBrightnessMagnitudeAndMode((unsigned short*)0x0400106c,-16);
 R16(0x04000008)&=~3;R16(0x0400000a)=(R16(0x0400000a)&~3)|1;
 System_WaitForInterruptOneAfterShortDelay();GX_DispOn();R32(0x04001000)|=0x10000;
 Graphics_WriteSignedBrightnessMagnitudeAndMode((unsigned short*)0x0400006c,-16);
 Graphics_WriteSignedBrightnessMagnitudeAndMode((unsigned short*)0x0400106c,-16);
 if(GameState_ReadByteAtOffset4(state)!=6){
 _ZN13SafeAllocator11CreateTypeAEPvj(p+0x470,AllocatorUnion_AllocateFourByteAligned((AllocatorUnion*)Main_UnknownRoleZeroInitializedStorage_Variant3,0x10000),0x10000);
 _ZN13SafeAllocator5ResetEv(p+0x470);
 Selection_InitializeDisplayController((State*)(p+0x2b4));Graphics_InitializeCanvasTransferState(p+0x370);TextCanvas_InitializeLayoutAndTransferDefaults((unsigned char*)p+0x390);
 MapVRAMBanksToMainBG(4);ConfigureBackgroundLayerOneControlBits(0,0,1,1,0);
 Graphics_SetTextBackgroundScreenSize((int)(p+0x370),0);
 ((Canvas*)(p+0x370))->flags.low=0;((Canvas*)(p+0x370))->flags.high=1;
 Graphics_SetBackgroundColorMode((Owner*)(p+0x370),0);
 Graphics_AllocateAndClearConfiguredBuffer(p+0x370,(SafeAllocator*)(p+0x470));Graphics_InvokeTwoIndexTransferCallback((State*)(p+0x370),0,0);
 Frame f;
 int task;void* loader=_ZN16BackgroundLoader11GetInstanceEv();_ZN16BackgroundLoader31ResetQueuedTasksAndScratchUsageEv(loader);
 task=_ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader,RunOverlayDisplaySequenceAndSelection_PathDataAniBgTmPac,0);
 while(1){if(_ZN16BackgroundLoader13GetTaskStatusEi(loader,task)){

 _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,task,&f.file,&f.fileSize);
 int count=ResourceFile_CountActiveStrideRecords((Record*)f.file);
 for(int i=0;i<count;i++){
 char* block=ResourceFile_GetPayloadByIndex((char*)f.file,i,&f.blockName,&f.blockSize);
 // Target call supplies the archive length as a fourth argument. The current callee ignores it.
 if(block)Graphics_LoadTaggedLayerResource((Owner*)(p+0x370),block,(unsigned)((SafeAllocator*)(p+0x470)),f.blockSize);
 }
 _ZN16BackgroundLoader10RemoveTaskEi(loader,task);
 Tilemap_FillClippedRectangle((TilemapOwner*)(p+0x370),0,0,0,32,25,0);Graphics_CleanAndTransferScreenBuffer(p+0x370,0);
 W(0x498)=(int)_ZN13SafeAllocator8AllocateEj((unsigned)(p+0x470),0x8000);
 TextCanvas_AllocateTilemapAndBindPixels(p+0x390,(SafeAllocator*)(p+0x470),W(0x498),0x800);
 W(0x394)=(int)(p+0x370);W(0x34c)=(int)(p+0x370);B(0x366)=1;
 Selection_AttachBackwardLinkedDisplayRecords((unsigned char*)p+0x2b4,p+0x390,1);break;
 }else _ZN16BackgroundLoader14RemoveAllLocksEv(loader);}
 B(0x365)=1;H(0x358)=0;H(0x35a)=0;H(0x35c)=0;H(0x35e)=0;H(0x354)=32;H(0x356)=24;H(0x360)=10;H(0x362)=13;B(0x369)=0;B(0x36a)=1;
 char* text=*(char**)((char*)TextContext_GetSharedInstance()+0x5c);memset(text,0,0x960);
 __clear(f.buffer,128);
 Text_AppendFormattedXYPair(text,4,0x68);sprintf(f.buffer,RunOverlayDisplaySequenceAndSelection_FormatSS,RunOverlayDisplaySequenceAndSelection_TextVer035,RunOverlayDisplaySequenceAndSelection_TextApr142010);Text_AppendFormatString(text,f.buffer);
 Text_AppendFormattedXYPair(text,4,0x74);int sdkBuild=GetSdkBuild();sprintf(f.buffer,RunOverlayDisplaySequenceAndSelection_FormatNITROSDKDDD,4,2,sdkBuild);Text_AppendFormatString(text,f.buffer);
 Text_AppendFormattedXYPair(text,4,0x80);sprintf(f.buffer,RunOverlayDisplaySequenceAndSelection_FormatNITROSYSTEMD,0x13242d6);Text_AppendFormatString(text,f.buffer);
 Text_AppendFormattedXYPair(text,4,0x8c);int wifiBuild=GetWifiBuild();sprintf(f.buffer,RunOverlayDisplaySequenceAndSelection_FormatNITROWiFiDDD,2,1,wifiBuild);Text_AppendFormatString(text,f.buffer);
 Text_AppendFormattedXYPair(text,4,0x98);int cryptoBuild=GetCryptoBuild();sprintf(f.buffer,RunOverlayDisplaySequenceAndSelection_FormatNITROCRYPTODDD,2,1,cryptoBuild);Text_AppendFormatString(text,f.buffer);
 Text_AppendFormattedXYPair(text,4,0xa4);int downloadBuild=GetDownloadBuild();sprintf(f.buffer,RunOverlayDisplaySequenceAndSelection_FormatDWCDLDDD,3,1,downloadBuild);Text_AppendFormatString(text,f.buffer);
 Text_AppendFormattedXYPair(text,4,0xb0);int swcBuild=GetSwcBuild();sprintf(f.buffer,RunOverlayDisplaySequenceAndSelection_FormatSWCDDD,3,0,swcBuild);Text_AppendFormatString(text,f.buffer);
 Text_AppendFormattedXYPair(text,0,0x28);Text_AppendCenteredTextUsingComputedWidth(text,RunOverlayDisplaySequenceAndSelection_TextDRAGONQUESTIX,256,0);
 Text_AppendFormattedXYPair(text,0,0x36);Text_AppendCenteredTextUsingComputedWidth(text,RunOverlayDisplaySequenceAndSelection_TextXENLONProject,256,0);
 Text_AppendFormattedXYPair(text,0,0x50);Text_AppendCenteredTextUsingComputedWidth(text,RunOverlayDisplaySequenceAndSelection_TextLEVEL5INC,256,0);
 Window_PushTextCanvas(p+0x2b4,text,0,0,0,1,0,0);
 Window_UpdateCanvasesAndSelection((unsigned char*)p+0x2b4,1);Window_UpdateCanvasesAndSelection((unsigned char*)p+0x2b4,1);
 ProcessAllTwoHundredTwentyFourByteRecordsWhenBothPointersSet(p+0x2b4);Graphics_ResetCountedThirtyTwoByteTransfers(p+0x2b4);Window_ResetResourceTransfers(p+0x2b4);
 Graphics_WriteSwapControlAndToggleGlobalState(0,1);System_WaitForInterruptOneAfterShortDelay();GX_DispOn();
 R32(0x04000000)=(R32(0x04000000)&~0x1f00)|0x200;
 Graphics_DrainTransferQueue();Graphics_WriteSwapControlAndToggleGlobalState(0,1);
 while(W(0)!=-1){
 Input_UpdatePowerKeysAndTouch();
 if(Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,1))break;
 if(Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,2))break;
 if(Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x400))break;
 if(Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x800)||Main_UnknownRoleZeroInitializedStorage_Variant4[0x55])break;
 System_WaitForInterruptOneAfterShortDelay();Graphics_WriteSignedBrightnessMagnitudeAndMode((unsigned short*)0x0400006c,0);Graphics_WriteSwapControlAndToggleGlobalState(0,1);
 }
 void* allocation=_ZNK13SafeAllocator18GetSignedAllocatorEv(p+0x470);_ZN13SafeAllocator7DestroyEv(p+0x470);Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3,allocation);
 }
 System_WaitForInterruptOneAfterShortDelay();
 Graphics_WriteSignedBrightnessMagnitudeAndMode((unsigned short*)0x0400006c,-16);Graphics_WriteSignedBrightnessMagnitudeAndMode((unsigned short*)0x0400106c,-16);
 R16(0x04000008)=(R16(0x04000008)&~3)|1;R16(0x0400000a)&=~3;R16(0x0400000c)=(R16(0x0400000c)&~3)|2;R16(0x0400000e)=(R16(0x0400000e)&~3)|3;
 R16(0x04001008)&=~3;R16(0x0400100a)=(R16(0x0400100a)&~3)|1;R16(0x0400100c)=(R16(0x0400100c)&~3)|2;R16(0x0400100e)=(R16(0x0400100e)&~3)|3;
 _Z28LockStagedTextureVRAMCopyingv();MapVRAMBanksToTextureImage(1);_Z26InitializeTextureImageVRAMjb(1,true);MapVRAMBanksToTexturePalette(0x60);_Z28InitializeTexturePaletteVRAMjb(0x8000,true);_Z26UpdateVRAMStagingVRAMBanksv();_Z30UnlockStagedTextureVRAMCopyingv();
 _ZN13SafeAllocator11CreateTypeAEPvj(p+0x470,AllocatorUnion_AllocateFourByteAligned((AllocatorUnion*)Main_UnknownRoleZeroInitializedStorage_Variant3,0x10000),0x10000);
 VRAM_SaveStateAndReserveImagePaletteBytes((State*)(p+0x244),0x4000,0x400);
 char* global=(char*)TextContext_GetSharedInstance();Graphics_InitializeSelectionAndRenderState((unsigned char*)global);Graphics_ClearAndStageSharedBuffers(global);Filesystem_LoadEmbeddedArchiveUsingScratchAllocator(global);
 *(char**)(global+0x1e28)=p+0x244;TextureVRAM_SnapshotAllocationBounds(p+0x244);Graphics_RestoreTextureImageAndPaletteVRAMState(p+0x244);TextWindow_StagePaletteAndRefreshRendering(global);Object_InvokeSaveTextureImageVRAMState(p+0x244);
 W(0)=100;W(4)=-1;
 if(GameState_ReadByteAtOffset4(state)==6){
 if(GameState_GetStartupDispatchMode(state)==0){
 G3X_SetClearColor(0x7fff,31,0x7fff,0,0);Graphics_InitializeSubBackgroundCanvasAndDisplay(p);GX_DispOn();R32(0x04001000)|=0x10000;
 W(0x4e4)=2000;
 while(1){if(!TIMED->HasCountdown())break;BootScreen_AdvanceScreenDelay(TIMED);System_WaitForInterruptOneAfterShortDelay();Input_UpdatePowerKeysAndTouch();Graphics_WriteSwapControlAndToggleGlobalState(0,1);}
 Graphics_SetMainBrightnessTarget(TIMED,0,500);Graphics_SetSubBrightnessTarget(TIMED,0,500);W(0x4e4)=3000;
 while(1){if(!TIMED->HasSubTransition()){if(!TIMED->HasCountdown())break;BootScreen_AdvanceScreenDelay(TIMED);Input_UpdatePowerKeysAndTouch();}Graphics_AdvanceBrightnessTransitions(TIMED);System_WaitForInterruptOneAfterShortDelay();Graphics_WriteSwapControlAndToggleGlobalState(0,1);}
 Graphics_SetMainBrightnessTarget(TIMED,-16,500);Graphics_SetSubBrightnessTarget(TIMED,-16,500);
 while(1){if(!TIMED->HasSubTransition())break;Graphics_AdvanceBrightnessTransitions(TIMED);System_WaitForInterruptOneAfterShortDelay();Input_UpdatePowerKeysAndTouch();Graphics_WriteSwapControlAndToggleGlobalState(0,1);}
 W(0x4e4)=1000;while(1){if(!TIMED->HasCountdown())break;BootScreen_AdvanceScreenDelay(TIMED);System_WaitForInterruptOneAfterShortDelay();Input_UpdatePowerKeysAndTouch();Graphics_WriteSwapControlAndToggleGlobalState(0,1);}
 Graphics_InitializeDualScreenCanvasResources(p);GX_DispOn();R32(0x04001000)|=0x10000;
 Graphics_SetMainBrightnessTarget(TIMED,0,1500);Graphics_SetSubBrightnessTarget(TIMED,0,1500);W(0x4e4)=7000;
 while(1){if(!Graphics_HasActiveBrightnessTransition(TIMED)){if(!TIMED->HasCountdown())break;BootScreen_AdvanceScreenDelay(TIMED);Input_UpdatePowerKeysAndTouch();if(W(0x4e4)<=2500&&(Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0xf0b)||Main_UnknownRoleZeroInitializedStorage_Variant4[0x55]))break;}Graphics_AdvanceBrightnessTransitions(TIMED);System_WaitForInterruptOneAfterShortDelay();Graphics_WriteSwapControlAndToggleGlobalState(0,1);}
 Graphics_SetMainBrightnessTarget(TIMED,-16,1000);Graphics_SetSubBrightnessTarget(TIMED,-16,1000);
 while(1){if(!TIMED->HasSubTransition())break;Graphics_AdvanceBrightnessTransitions(TIMED);System_WaitForInterruptOneAfterShortDelay();Input_UpdatePowerKeysAndTouch();Graphics_WriteSwapControlAndToggleGlobalState(0,1);}
 W(0x4e4)=1000;while(1){if(!TIMED->HasCountdown())break;BootScreen_AdvanceScreenDelay(TIMED);System_WaitForInterruptOneAfterShortDelay();Input_UpdatePowerKeysAndTouch();Graphics_WriteSwapControlAndToggleGlobalState(0,1);}
 Graphics_InitializeCanvasAndLoadSelectedArchive(p,0);GX_DispOn();R32(0x04001000)|=0x10000;
 Graphics_SetMainBrightnessTarget(TIMED,0,1500);Graphics_SetSubBrightnessTarget(TIMED,0,1500);W(0x4e4)=6000;
 while(1){if(!TIMED->HasSubTransition()){if(!TIMED->HasCountdown())break;BootScreen_AdvanceScreenDelay(TIMED);Input_UpdatePowerKeysAndTouch();if(Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0xf0b)||Main_UnknownRoleZeroInitializedStorage_Variant4[0x55])break;}Graphics_AdvanceBrightnessTransitions(TIMED);System_WaitForInterruptOneAfterShortDelay();Graphics_WriteSwapControlAndToggleGlobalState(0,1);}
 Graphics_SetMainBrightnessTarget(TIMED,-16,1000);Graphics_SetSubBrightnessTarget(TIMED,-16,1000);
 while(1){if(!TIMED->HasSubTransition())break;Graphics_AdvanceBrightnessTransitions(TIMED);System_WaitForInterruptOneAfterShortDelay();Input_UpdatePowerKeysAndTouch();Graphics_WriteSwapControlAndToggleGlobalState(0,1);}
 W(0x4e4)=1000;while(1){if(!TIMED->HasCountdown())break;BootScreen_AdvanceScreenDelay(TIMED);System_WaitForInterruptOneAfterShortDelay();Input_UpdatePowerKeysAndTouch();Graphics_WriteSwapControlAndToggleGlobalState(0,1);}
 G3X_SetClearColor(0,31,0x7fff,0,0);
 }
 GameState_SetUnknown7f6c(state,5);GameState_SetUnk4Element0(state,0);GameState_WriteUnknownF70(state,1);
 }else{
 GameState_SetUnknown7f6c(state,0);Graphics_LoadDualScreenCanvasResources((unsigned char*)p);GX_DispOn();R32(0x04001000)|=0x10000;
 TextEntry_ResetGlyphCacheAndTextureAllocator((Owner*)global);TextLayout_InitializeSelectionPanel((unsigned char*)p+0xc);B(0xbd)=1;B(0xbc)=1;
 if(SaveData_GetBankHeaderValidationStatus(1)==4){for(int i=0;i<8;i++){TextLayout_AppendConvertedLineAndUpdateWidths(p+0xc,RunOverlayDisplaySequenceAndSelection_UnknownRoleInitializedBytes_Variant2+i*32);TextWindow_AdvanceTextForRequestedTicks(global,16);TextWindow_RenderAndTransferDisplayBuffers(global,0);}BootScreen_ConfigureMenuSelectionGrids((Overlay20Grids*)(p+0xc),1,8);}
 else {for(int i=0;i<7;i++){TextLayout_AppendConvertedLineAndUpdateWidths(p+0xc,RunOverlayDisplaySequenceAndSelection_UnknownRoleInitializedBytes+i*32);TextWindow_AdvanceTextForRequestedTicks(global,16);TextWindow_RenderAndTransferDisplayBuffers(global,0);}BootScreen_ConfigureMenuSelectionGrids((Overlay20Grids*)(p+0xc),1,7);}
 TextLayout_ComputeSelectionPanelBounds((Object*)(p+0xc),0,-4);
 int width=H(0xc4),height=H(0xc6);
 int x=256-width,y=192-height;
 H(0xc0)=x>>1;H(0xc2)=y>>2;
 TextLayout_ComputeSelectionPanelBounds((Object*)(p+0xc),0,-4);Grid_SelectIndexAndInvalidateTouchHistory((State*)(p+0x2c),0);Grid_SelectIndexAndComputePageCoordinates((GridSelection*)(p+0x7c),0);
 MapVRAMBanksToMainObj(2);
 void* loader=_ZN16BackgroundLoader11GetInstanceEv();char* loading=(char*)TextContext_GetSharedInstance();
 while(1){BackgroundLoader_AdvanceThreePhaseArchiveAssetLoad((LoadingOwner*)loading);if((unsigned char)loading[0x2e7]==2)break;_ZN16BackgroundLoader14RemoveAllLocksEv(loader);}
 char* oam=(char*)Graphics_GetGlobalOamTransferState();Graphics_InitializeSubOamStagingState(oam);SoundSfx_RestoreSecondaryHeapStateAndVolume(Main_UnknownRoleZeroInitializedStorage);ResourceHandle_SwitchTargetUnlessBlocked((State*)Main_UnknownRoleZeroInitializedStorage_Variant2,2);
 while(W(0)!=-1){
 Input_UpdatePowerKeysAndTouch();W(4)++;if(W(4)>=0xffffff)W(4)=1;
 Graphics_InitializeGeometryAndDisplayState();Graphics_ResetGeometryMatrixStackState();R16(0x04000060)&=0xcfdf;
 switch(W(0)){case 100: UpdateDisplaySelectionAndSetGameStateByte4((unsigned char*)p);break;default:W(0)=-1;break;}
 Graphics_WriteSwapControlAndToggleGlobalState(0,1);
 // The target passes the staging owner although this callee currently ignores it.
 ((void(*)(char*))Graphics_FlushTwoBackgroundBuffers)(oam);System_WaitForInterruptOneAfterShortDelay();Graphics_LoadAndClearEnabledOamScreens((unsigned char*)oam);Graphics_DrainTransferQueue();Sound_UpdatePlaybackAndFlushCommands();
 Graphics_WriteSignedBrightnessMagnitudeAndMode((unsigned short*)0x0400006c,0);Graphics_WriteSignedBrightnessMagnitudeAndMode((unsigned short*)0x0400106c,0);
 }
 if(GameState_ReadByteAtOffset4(state)==0)GameState_SetUnknown7f6c(state,6);
 else if(GameState_ReadByteAtOffset4(state)==5)GameState_SetUnknown7f6c(state,6);
 }
 BootScreen_ReleaseResourcesAndResetAudio((Overlay20AllocatorOwner*)p);TextureVRAM_SnapshotAllocationBounds(p+0x244);
 Graphics_WriteSignedBrightnessMagnitudeAndMode((unsigned short*)0x0400006c,-16);Graphics_WriteSignedBrightnessMagnitudeAndMode((unsigned short*)0x0400106c,-16);
}
