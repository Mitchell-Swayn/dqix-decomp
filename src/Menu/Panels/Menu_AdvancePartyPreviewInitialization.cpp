#include <globaldefs.h>
ARM
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
extern "C" unsigned Text_ClearNameDescriptor(...);
extern "C" unsigned TextLayout_ResetFormattingWorkspace(...);
extern "C" unsigned Menu_ResetLayout(...);
extern "C" unsigned Camera_DisableTargetFollowing(...);
extern "C" unsigned DisplayContext_IgnoreCommand(...);
extern "C" unsigned ResourceFile_GetPayloadByIndex(...);
extern "C" unsigned GameResources_GetInstance(...);
extern "C" unsigned GameState_BuildTwelveByteDescriptorForPartyMember(...);
extern "C" unsigned GameState_GetObjectWithFlag100(...);
extern "C" unsigned GameState_ReadProtagonistObjectIndex(...);
extern "C" unsigned GameState_ReadUnknownB0(...);
extern "C" unsigned GameState_SetUnknown3b0(...);
extern "C" unsigned Graphics_CopySixteenBytesToEdgeColorRegisters(...);
extern "C" unsigned Graphics_DispatchDataByResourceMagic(...);
extern "C" unsigned Graphics_RestoreTextureImageAndPaletteVRAMState(...);
extern "C" unsigned Graphics_WriteHalfwordRegister35CAndDisplayControl(...);
extern "C" unsigned DisplayContext_IgnoreHook(...);
extern "C" unsigned Graphics_InitializeSpriteTransformDefaults(...);
extern "C" unsigned Graphics_InitializeSpriteResourceBuffers(...);
extern "C" unsigned Camera_InitializeTargetFollowingState(...);
extern "C" unsigned Object_InvokeSaveTextureImageVRAMState(...);
extern "C" unsigned DisplayContext_GetGlobalInstance(...);
extern "C" unsigned Camera_SetEyeCoordinates(...);
extern "C" unsigned GameResources_SetSecondaryFlags(...);
extern "C" unsigned TextMarkup_ExpandAndWrapText(...);
extern "C" unsigned GameObject_GetLinkedIndexedState(...);
extern "C" unsigned TextContext_GetSharedInstance(...);
extern "C" unsigned ResourceStringTable_GetTextByKey(...);
extern "C" unsigned ResourceFile_CountActiveStrideRecords(...);
extern "C" unsigned DisplayContext_ReportRequestComplete(...);
extern "C" unsigned CharacterPreview_SetStandingAnimationMode(...);
extern "C" unsigned Menu_SetCharacterPreviewResourceCatalogue(...);
extern "C" unsigned TextWindow_SetRenderResourceDescriptor(...);
extern "C" unsigned TextureVRAM_SnapshotAllocationBounds(...);
extern "C" unsigned TextWindow_StagePaletteAndRefreshRendering(...);
extern "C" unsigned VRAM_SaveStateAndReserveImagePaletteBytes(...);
extern "C" unsigned Camera_SetTargetCoordinates(...);
extern "C" unsigned _Z32IsMainBrightnessTransitionActiveP13GameResources(...);
extern "C" unsigned _ZN13SafeAllocator11CreateTypeAEPvj(...);
extern "C" unsigned _ZN13SafeAllocator5ResetEv(...);
extern "C" unsigned _ZN13SafeAllocator8AllocateEj(...);
extern "C" unsigned _ZN13ZoneState275420BuildAlternateForKeyEP13SafeAllocatorPvjs(...);
extern "C" unsigned _ZN13ZoneState275421BuildAlternateForKeysEP13SafeAllocatorPvjPKss(...);
extern "C" unsigned _ZN13ZoneState27544Data16GetRecordAtIndexEi(...);
extern "C" unsigned _ZN13ZoneState27544Data19GetRecordCountBoundEv(...);
extern "C" unsigned _ZN13ZoneState27545ResetEv(...);
extern "C" unsigned _ZN16BackgroundLoader10RemoveTaskEi(...);
extern "C" unsigned _ZN16BackgroundLoader11GetInstanceEv(...);
extern "C" unsigned _ZN16BackgroundLoader13GetTaskStatusEi(...);
extern "C" unsigned _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(...);
extern "C" unsigned _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(...);
extern "C" unsigned _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(...);
extern "C" unsigned _ZN9GameState11GetInstanceEv(...);
extern "C" unsigned Menu_DisableEmptyCatalogueSubtypes(...);
extern "C" unsigned Memory_CreateNestedAllocatorGroup(...);
extern "C" unsigned Graphics_ReserveAndSnapshotPaletteBlocks(...);
extern "C" unsigned EquipmentMenu_InitializeController(...);
extern "C" unsigned EquipmentMenu_AdvanceResourceInitialization(...);
extern "C" unsigned Graphics_InitializeWindowEntryArrays(...);
extern "C" unsigned EquipmentMenu_CacheQuantityDigitGlyphs(...);
extern "C" unsigned EquipmentMenu_CacheEquippedItemNames(...);
extern "C" unsigned Field_LoadWindowCoffinShadowAndAnimationResources(...);
extern "C" unsigned LoadRelativeLayoutRecords(...);
extern "C" unsigned Menu_UploadPartyVocationIconTiles(...);
extern "C" unsigned Menu_SetPartyPreviewPhase(...);
extern "C" unsigned Menu_ClearLayoutGroupFlags(...);
extern "C" unsigned Menu_CachePartyPreviewSummaryText(...);
extern "C" unsigned Graphics_InitializeTenModelsAndAllocators(...);
extern "C" unsigned CharacterPreview_CreateModelAndAnimationAllocators(...);
extern "C" unsigned Graphics_SaveAndReserveTenModelPaletteRanges(...);
extern "C" unsigned CharacterPreview_QueueAppearanceModelsAndAnimations(...);
extern "C" unsigned Ov023_InitializeFourEmbeddedFields(...);
extern "C" unsigned memcpy(...);
extern "C" unsigned memset(...);

struct Owner{char pad[0x640];char* names[2];};
// Original data: arm9/main @ 0x20f2a30; symbol: data_020f2a30.
// Contains original relocated data addresses. Referenced targets and raw storage values are recorded; semantic role and record layout remain unresolved.
// Initial values: hex 612a0f02.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20f2a38; symbol: data_020f2a38.
// Contains original relocated data addresses. Referenced targets and raw storage values are recorded; semantic role and record layout remain unresolved.
// Initial values: hex c82a0f02.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20f2a40; symbol: data_020f2a40.
// Contains original relocated data addresses. Referenced targets and raw storage values are recorded; semantic role and record layout remain unresolved.
// Initial values: hex 322b0f02.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char* CharacterViewerRun_UnknownRoleDataReferences_Variant2;extern "C" char* CharacterViewerRun_UnknownRoleDataReferences;extern "C" char* MenuAdvancePartyPreviewInitialization_UnknownRoleDataReferences;
// Original data: arm9/ov023 @ 0x21fd66c; symbol: data_ov023_021fd66c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00010203040506070b000000.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov023.md.
// Original data: arm9/ov023 @ 0x21fdc94; symbol: data_ov023_021fdc94.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 86108610861086108610861086108610.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov023.md.
extern "C" char MenuAdvancePartyPreviewInitialization_UnknownRoleInitializedBytes[],Menu_AdvancePartyPreviewInitialization_PathDataAniClmmGp2[],Menu_AdvancePartyPreviewInitialization_MarkupClmmLGPac[],Menu_AdvancePartyPreviewInitialization_PathDataAniLayMmLia[],MenuAdvancePartyPreviewInitialization_UnknownRoleInitializedBytes_Variant2[];
// Original: arm9/ov023 @ 0x021E33B4; symbol: AdvanceDescriptorResourceInitialization; size: 0x988.
// Loads descriptor resources through nine phases, constructs nested allocators and models and restores display configuration.
extern "C" void Menu_AdvancePartyPreviewInitialization(char* self){
 void* game=(void*)_ZN9GameState11GetInstanceEv();void* resources=(void*)GameResources_GetInstance();void* loader=(void*)_ZN16BackgroundLoader11GetInstanceEv();if(!B(self,0x4e4))B(self,0x4e4)++;
 if(_Z32IsMainBrightnessTransitionActiveP13GameResources(resources))return;
 if(B(self,0x4e4)==1){void* context=(void*)DisplayContext_GetGlobalInstance();DisplayContext_IgnoreHook(context);DisplayContext_IgnoreCommand(context,0x79,506,0,0);B(self,0x4e4)++;return;}
 if(B(self,0x4e4)==2){if(!DisplayContext_ReportRequestComplete(DisplayContext_GetGlobalInstance()))return;Field_LoadWindowCoffinShadowAndAnimationResources(resources,1);W(self,0x630)=_ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(loader,CharacterViewerRun_UnknownRoleDataReferences_Variant2,CharacterViewerRun_UnknownRoleDataReferences,0);B(self,0x4e4)++;return;}
 if(B(self,0x4e4)==3){
  if(!_ZN16BackgroundLoader13GetTaskStatusEi(loader,W(self,0x630)))return;void* code;unsigned length;_ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,W(self,0x630),&code,&length);
  GameResources_SetSecondaryFlags(resources,0x601fe);Graphics_RestoreTextureImageAndPaletteVRAMState(P(self,8));_ZN13SafeAllocator5ResetEv(P(self,0x14));_ZN13ZoneState27545ResetEv(self+0xa4);_ZN13ZoneState275420BuildAlternateForKeyEP13SafeAllocatorPvjs(self+0xa4,P(self,0x14),code,length,11);
  U(self,0xbe)=_ZN13ZoneState27544Data19GetRecordCountBoundEv(self+0xa4);U(self,0xbc)=U(self,0xbe)+49;for(int i=0;i<U(self,0xbc);i++)_ZN13ZoneState27544Data16GetRecordAtIndexEi(self+0xa4,(short)i);_ZN13SafeAllocator5ResetEv(P(self,0x14));
  if(S(self,0x4e5)==3){P(self,0)=(char*)_ZN13SafeAllocator8AllocateEj(P(self,0x10),0x428c);EquipmentMenu_InitializeController(P(self,0));Memory_CreateNestedAllocatorGroup(P(self,0),P(self,0x10),P(self,12));Menu_DisableEmptyCatalogueSubtypes(P(self,0),code,length);}
  void* memory=(void*)_ZN13SafeAllocator8AllocateEj(P(self,0x10),0x800);_ZN13SafeAllocator11CreateTypeAEPvj(self+0x2c,memory,0x800);memory=(void*)_ZN13SafeAllocator8AllocateEj(P(self,0x10),0x100);_ZN13SafeAllocator11CreateTypeAEPvj(self+0x40,memory,0x100);
  for(int i=0;i<2;i++){((Owner*)self)->names[i]=(char*)_ZN13SafeAllocator8AllocateEj(self+0x2c,64);memset(((Owner*)self)->names[i],0,64);}
  memory=(void*)_ZN13SafeAllocator8AllocateEj(P(self,4),0x100);_ZN13SafeAllocator11CreateTypeAEPvj(self+0x68,memory,0x100);
  P(self,0xc8)=(char*)_ZN13SafeAllocator8AllocateEj(P(self,4),0x54);P(self,0xcc)=(char*)_ZN13SafeAllocator8AllocateEj(P(self,4),0x280);P(self,0xd0)=(char*)_ZN13SafeAllocator8AllocateEj(P(self,4),8);
  if(P(self,0)&&P(self,0xd0)&&P(self,0xc8))Graphics_InitializeWindowEntryArrays(P(self,0),P(self,0xd0),P(self,0xc8));
  memory=(void*)_ZN13SafeAllocator8AllocateEj(P(self,4),0x300);_ZN13SafeAllocator11CreateTypeAEPvj(self+0x7c,memory,0x300);memory=(void*)_ZN13SafeAllocator8AllocateEj(P(self,4),0x200);_ZN13SafeAllocator11CreateTypeAEPvj(self+0x90,memory,0x200);
  P(self,0x120)=(char*)_ZN13SafeAllocator8AllocateEj(P(self,4),0xc20);Graphics_InitializeTenModelsAndAllocators(P(self,0x120));CharacterPreview_CreateModelAndAnimationAllocators(P(self,0x120),P(self,4));Graphics_SaveAndReserveTenModelPaletteRanges(P(self,0x120));Menu_SetCharacterPreviewResourceCatalogue(P(self,0x120),self+0xa4);CharacterPreview_SetStandingAnimationMode(P(self,0x120),1);
  P(self,0x124)=(char*)_ZN13SafeAllocator8AllocateEj(P(self,4),0xc20);Graphics_InitializeTenModelsAndAllocators(P(self,0x124));CharacterPreview_CreateModelAndAnimationAllocators(P(self,0x124),P(self,4));Graphics_SaveAndReserveTenModelPaletteRanges(P(self,0x124));Menu_SetCharacterPreviewResourceCatalogue(P(self,0x124),self+0xa4);CharacterPreview_SetStandingAnimationMode(P(self,0x124),1);
  _ZN13SafeAllocator5ResetEv(P(self,0x14));_ZN13ZoneState27545ResetEv(self+0xa4);_ZN13ZoneState275421BuildAlternateForKeysEP13SafeAllocatorPvjPKss(self+0xa4,P(self,0x14),code,length,MenuAdvancePartyPreviewInitialization_UnknownRoleInitializedBytes,9);
  P(self,0x638)=(char*)_ZN13SafeAllocator8AllocateEj(self+0x2c,0x2a0);memset(P(self,0x638),0,0x2a0);P(self,0x63c)=(char*)_ZN13SafeAllocator8AllocateEj(self+0x2c,0x400);memset(P(self,0x63c),0,0x400);if(P(self,0))P(P(self,0),0xdf4)=self+0xa4;
  VRAM_SaveStateAndReserveImagePaletteBytes(self+0x474,0x4000,64);TextureVRAM_SnapshotAllocationBounds(self+0x474);if(S(self,0x4e5)==3&&P(self,0))Graphics_ReserveAndSnapshotPaletteBlocks(P(self,0));VRAM_SaveStateAndReserveImagePaletteBytes(self+0x404,0,0);TextureVRAM_SnapshotAllocationBounds(self+0x404);
  void* owner=(void*)TextContext_GetSharedInstance();TextWindow_SetRenderResourceDescriptor(owner,self+0x474);Graphics_RestoreTextureImageAndPaletteVRAMState(self+0x474);TextWindow_StagePaletteAndRefreshRendering(owner);Object_InvokeSaveTextureImageVRAMState(self+0x474);
  W(self,0x138)=GameState_ReadUnknownB0(game);Camera_InitializeTargetFollowingState(self+0x13c);Camera_SetEyeCoordinates(self+0x13c,0xb666,0xa800,0x42ccc);Camera_SetTargetCoordinates(self+0x13c,0xb666,0xa800,0);Camera_DisableTargetFollowing(self+0x13c);GameState_SetUnknown3b0(game,self+0x13c);Graphics_WriteHalfwordRegister35CAndDisplayControl(0,0,0,0);
  _ZN16BackgroundLoader10RemoveTaskEi(loader,W(self,0x630));W(self,0x630)=-1;W(self,0x630)=_ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader,MenuAdvancePartyPreviewInitialization_UnknownRoleDataReferences,0);B(self,0x4e4)++;return;
 }
 if(B(self,0x4e4)==4){
  if(!_ZN16BackgroundLoader13GetTaskStatusEi(loader,W(self,0x630)))return;void* code;unsigned length;_ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,W(self,0x630),&code,&length);P(self,0xc0)=(char*)_ZN13SafeAllocator8AllocateEj(self+0x90,length);memcpy(P(self,0xc0),code,length);W(self,0xc4)=length;_ZN16BackgroundLoader10RemoveTaskEi(loader,W(self,0x630));W(self,0x630)=-1;
  Graphics_InitializeSpriteResourceBuffers(P(self,0xc8));B(P(self,0xc8),0x50)=0;char* layout=P(self,0xc8);P(layout,0x40)=P(self,0xcc);H(layout,0x4c)=16;P(P(self,0xc8),0x3c)=P(self,0xd0);for(int i=0;i<16;i++)Graphics_InitializeSpriteTransformDefaults(P(self,0xcc)+i*40);
  W(self,0x630)=_ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(loader,Menu_AdvancePartyPreviewInitialization_PathDataAniClmmGp2,Menu_AdvancePartyPreviewInitialization_MarkupClmmLGPac,0);B(self,0x4e4)++;return;
 }
 if(B(self,0x4e4)==5){
  if(!_ZN16BackgroundLoader13GetTaskStatusEi(loader,W(self,0x630)))return;_ZN13SafeAllocator5ResetEv(self+0x68);char* block;char* code;unsigned length;_ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,W(self,0x630),&code,&length);int count=ResourceFile_CountActiveStrideRecords(code);unsigned size;
  for(int i=0;i<count;i++){void* entry=(void*)ResourceFile_GetPayloadByIndex(code,i,&block,&size);if(entry)Graphics_DispatchDataByResourceMagic(P(self,0xc8),entry,size,self+0x68);}
  _ZN16BackgroundLoader10RemoveTaskEi(loader,W(self,0x630));W(self,0x630)=-1;B(self,0x4e4)++;return;
 }
 if(B(self,0x4e4)==6){if(P(self,0)&&EquipmentMenu_AdvanceResourceInitialization(P(self,0)))B(self,0x4e4)++;return;}
 if(B(self,0x4e4)==7){
  unsigned descriptor[3];Text_ClearNameDescriptor(descriptor);GameState_BuildTwelveByteDescriptorForPartyMember(descriptor,GameState_ReadProtagonistObjectIndex(game));char* owner=(char*)TextContext_GetSharedInstance();char* textOwner=P(self,0)+0xdf8;
  for(int i=0;i<2;i++){descriptor[2]=(descriptor[2]&~0x3000000)|((i&3)<<24);TextLayout_ResetFormattingWorkspace(owner);P(owner,0)=(char*)descriptor;void* text=(void*)ResourceStringTable_GetTextByKey(textOwner,550);TextMarkup_ExpandAndWrapText(owner,8,text,((Owner*)self)->names[i],256,0,0);}
  W(self,0x630)=_ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader,Menu_AdvancePartyPreviewInitialization_PathDataAniLayMmLia,0);B(self,0x4e4)++;return;
 }
 if(B(self,0x4e4)==8){
  if(!_ZN16BackgroundLoader13GetTaskStatusEi(loader,W(self,0x630)))return;void* code;unsigned length;_ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,W(self,0x630),&code,&length);
  if(code){_ZN13SafeAllocator5ResetEv(self+0x7c);Menu_ResetLayout(self+0xd4);LoadRelativeLayoutRecords(self+0xd4,self+0x7c,code,length);Menu_ClearLayoutGroupFlags(self+0xd4,1,1);}
  _ZN16BackgroundLoader10RemoveTaskEi(loader,W(self,0x630));W(self,0x630)=-1;B(self,0x4e4)++;return;
 }
 char* object=(char*)GameState_GetObjectWithFlag100(_ZN9GameState11GetInstanceEv(),W(self,0x4fc));
 if(object){Ov023_InitializeFourEmbeddedFields(P(self,0x120),491);void* record=(void*)GameObject_GetLinkedIndexedState(object);CharacterPreview_QueueAppearanceModelsAndAnimations(P(self,0x120),record,W(self,0x4fc),0,0);}
 P(self,0x128)=P(self,0x120);P(self,0x12c)=P(self,0x124);U(self,0x634)|=0xa1;Menu_CachePartyPreviewSummaryText(self);
 if(S(self,0x4e5)==3&&P(self,0)){EquipmentMenu_CacheQuantityDigitGlyphs(P(self,0));EquipmentMenu_CacheEquippedItemNames(P(self,0));}
 Graphics_CopySixteenBytesToEdgeColorRegisters(MenuAdvancePartyPreviewInitialization_UnknownRoleInitializedBytes_Variant2);Menu_ClearLayoutGroupFlags(self+0xd4,17,1);Menu_ClearLayoutGroupFlags(self+0xd4,18,1);Menu_ClearLayoutGroupFlags(self+0xd4,27,1);Menu_ClearLayoutGroupFlags(self+0xd4,32,1);Menu_UploadPartyVocationIconTiles(W(self,0x4fc),P(self,0xc8));Menu_SetPartyPreviewPhase(self,S(self,0x4e5));B(self,0x4e4)=0;U(self,0x634)&=~0x2000;
}
