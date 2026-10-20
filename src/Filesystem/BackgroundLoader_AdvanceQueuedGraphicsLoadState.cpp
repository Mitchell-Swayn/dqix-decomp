#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Filesystem/BackgroundLoader.h>
#include <Resource/Script.h>
#include <Resource/GameResources.h>
#include <std_library_functions.h>
extern "C" unsigned short* Zone3D_GetMainInstance();
extern "C" void *Graphics_GetGlobalOamTransferState();extern "C" unsigned *Graphics_GetGlobalBackgroundState();
extern "C" int GameResources_IsSelectedScreenBrightnessWithinExtremes(GameResources*,int);
extern "C" void Graphics_AdvanceSubBrightnessTowardExtreme(void*,int),WorldMap_ResetDisplayAndMarkerState(void*),Graphics_ConfigureSubDisplayForThreeBackgrounds(void*),Graphics_ResetBackgroundBankState(void*),Graphics_ResetTransferRecordQueue(void*),Graphics_InitializeSubOamStagingState(void*),Graphics_UploadDirtySubBackgroundScreenMaps(void*);
extern "C" unsigned Graphics_AppendAndUploadBackgroundCharacterData(void*,int,unsigned short,const void*,unsigned,unsigned);
extern "C" void Graphics_FillBackgroundStagingSlotAndMarkDirty(void*,int,int,unsigned);
extern "C" void Graphics_InitializeSpriteTransformDefaults(void*),Graphics_InitializeSpriteResourceBuffers(void*),ConsumeLoadedTaskAndInitializeEmbeddedResources(void*,int*,SafeAllocator*),PartyStatus_RefreshAllMemberPortraitLabels(void*);
extern "C" void Graphics_ResetBackgroundMapResourceBindings(void*),Graphics_InitializeBackgroundMapFromDataAndPalette(void*,const void*,SafeAllocator*,int,unsigned short),Graphics_SubmitObjectBackgroundParameters(void*,int,int);
extern "C" void WorldMap_ResetTrackingOriginToSelectedObject(void*),Field_RebuildDisplayedAndProtagonistRosters(GameResources*),System_WaitForInterruptOneAfterShortDelay(),Object_UpdateGraphicsReadinessAndBrightness(void*),SetBitsForPresentFirstFourGameObjects(void*),WorldMap_ApplyObjectIdFilterRules(void*,int);
// Original data: arm9/main @ 0x20ef460; symbol: data_020ef460.
// Contains original relocated data addresses. Referenced targets and raw storage values are recorded; semantic role and record layout remain unresolved.
// Initial values: hex 70f40e0281f40e02b0f40e02caf40e02.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20ef498; symbol: data_020ef498.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 6600000090f3010267000000b4f301020000000000000000.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20ef6b5; symbol: data_020ef6b5.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00.
// Observed span: 1 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20fdc4c; symbol: data_020fdc4c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" const char BackgroundLoader_AdvanceQueuedGraphicsLoadState_PathDataAniObjMmWPac[],BackgroundLoader_AdvanceQueuedGraphicsLoadState_TextO00M0001Obg[],BackgroundLoader_AdvanceQueuedGraphicsLoadState_PathDataMapWOffsetBin[],WorldMapFormatTreasureMapLevelLabel_UnknownRoleInitializedBytes[];extern "C" char* WorldMapAdvanceZoneMapLoad_UnknownRoleDataReferences[];extern "C" unsigned PartyStatusRefreshMemberRatioPaletteColors_UnknownRoleZeroInitializedStorage[];extern "C" Script::OpcodeLookupEntry BackgroundLoaderAdvanceQueuedGraphicsLoadState_UnknownRoleProcedureReferenceRecords[];
// Original: arm9/main @ 0x020227DC; symbol: func_020227dc; size: 0x3B4.
extern "C" void BackgroundLoader_AdvanceQueuedGraphicsLoadState(char *self){
GameState::GetInstance();BackgroundLoader *loader=BackgroundLoader::GetInstance();unsigned short *location=Zone3D_GetMainInstance();GameResources *resources=GameResources_GetInstance();int i;void *texture=Graphics_GetGlobalOamTransferState();SafeAllocator *allocator;unsigned *background=Graphics_GetGlobalBackgroundState();allocator=&resources->allocator_array_38[12];
if(*(signed char*)(self+0x9c2)==0){Graphics_AdvanceSubBrightnessTowardExtreme(self,25);loader->AddFence();*(int*)(self+0xa24)=loader->QueueLoadFile(BackgroundLoader_AdvanceQueuedGraphicsLoadState_PathDataAniObjMmWPac,0);*(int*)(self+0xa20)=loader->QueueLoadFileInGP2(WorldMapAdvanceZoneMapLoad_UnknownRoleDataReferences[2],BackgroundLoader_AdvanceQueuedGraphicsLoadState_TextO00M0001Obg,0);*(int*)(self+0xa28)=loader->QueueLoadFile(BackgroundLoader_AdvanceQueuedGraphicsLoadState_PathDataMapWOffsetBin,0);++*(signed char*)(self+0x9c2);}
else if(*(signed char*)(self+0x9c2)==1&&loader->GetTaskStatus(*(int*)(self+0xa24))&&loader->GetTaskStatus(*(int*)(self+0xa20))&&loader->GetTaskStatus(*(int*)(self+0xa28))){Graphics_AdvanceSubBrightnessTowardExtreme(self,25);if(!GameResources_IsSelectedScreenBrightnessWithinExtremes(resources,1)){
WorldMap_ResetDisplayAndMarkerState(self);Graphics_ConfigureSubDisplayForThreeBackgrounds(self);Graphics_ResetBackgroundBankState(background);allocator->Reset();Graphics_ResetTransferRecordQueue(texture);Graphics_InitializeSubOamStagingState(texture);
char empty[32];memset(empty,0,32);Graphics_AppendAndUploadBackgroundCharacterData(background,1,1,empty,32,1);Graphics_FillBackgroundStagingSlotAndMarkDirty(background,1,0,0);Graphics_FillBackgroundStagingSlotAndMarkDirty(background,1,1,0);Graphics_UploadDirtySubBackgroundScreenMaps(background);
for(i=0;i<28;i++)Graphics_InitializeSpriteTransformDefaults(self+0xe8+i*40);Graphics_InitializeSpriteResourceBuffers(self+0x94);self[0xe4]=1;*(char**)(self+0xd4)=self+0xe8;*(short*)(self+0xe0)=28;*(unsigned*)(self+20)=1;ConsumeLoadedTaskAndInitializeEmbeddedResources(self,(int*)(self+0xa24),allocator);PartyStatus_RefreshAllMemberPortraitLabels(self);*(unsigned*)(self+0x24)=1;*(unsigned*)(self+0x30)=1;
void *file=0;unsigned length=0;loader->GetLoadedFileByID(*(int*)(self+0xa20),&file,&length);*(void**)(self+0x20)=allocator->Allocate(36);Graphics_ResetBackgroundMapResourceBindings(*(char**)(self+0x20)+8);Graphics_InitializeBackgroundMapFromDataAndPalette(*(char**)(self+0x20)+8,file,allocator,1,0);Graphics_SubmitObjectBackgroundParameters(*(char**)(self+0x20)+8,0,0);BackgroundLoader::GetInstance()->RemoveTask(*(int*)(self+0xa20));*(int*)(self+0xa20)=-1;
loader->GetLoadedFileByID(*(int*)(self+0xa28),&file,&length);PartyStatusRefreshMemberRatioPaletteColors_UnknownRoleZeroInitializedStorage[4]=(unsigned)self;PartyStatusRefreshMemberRatioPaletteColors_UnknownRoleZeroInitializedStorage[2]=(unsigned)allocator;Script script;script.Initialize();script.SetOpcodeLookup(BackgroundLoaderAdvanceQueuedGraphicsLoadState_UnknownRoleProcedureReferenceRecords);script.Load(file,length);script.Execute();if(*location==10000||*location==10100){self[0x12]=1;self[0x779]=0;self[0x9ba]=0;strcpy(self+2,WorldMapFormatTreasureMapLevelLabel_UnknownRoleInitializedBytes);}BackgroundLoader::GetInstance()->RemoveTask(*(int*)(self+0xa28));*(int*)(self+0xa28)=-1;WorldMap_ResetTrackingOriginToSelectedObject(self);Field_RebuildDisplayedAndProtagonistRosters(resources);self[0x55c]=1;self[0x9c4]=1;self[0x9c8]=0;self[0x9c3]=0;++*(signed char*)(self+0x9c2);System_WaitForInterruptOneAfterShortDelay();Object_UpdateGraphicsReadinessAndBrightness(self);SetBitsForPresentFirstFourGameObjects(self);WorldMap_ApplyObjectIdFilterRules(self,0);}}
}
