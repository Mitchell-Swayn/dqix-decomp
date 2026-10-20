#include <globaldefs.h>
ARM
extern "C" {
void* _ZN9GameState11GetInstanceEv();
void* GameState_ReadPResources(void*);
void GameResources_SetSecondaryFlags(int,unsigned);
void GameResources_ClearSecondaryFlags(int,unsigned);
void _ZN8Object3D18SetAnimationByNameEPKci(void*,const char*,int);
void _ZN8Object3D10EnableFlagEi(void*,int);
void _ZN8Object3D11DisableFlagEi(void*,int);
void _ZN8Object3D20StopCurrentAnimationEv(void*);
int _ZNK8Object3D19HasAnimationStoppedEv(void*);
int _ZNK8Object3D22HasAnimationReachedEndEv(void*);
void SoundSfx_LoadGroupAtCurrentHeapState(void*,unsigned,unsigned short);
void ResourceHandle_InvokeOperationWithValidHalfwordIndex(char*,int,int);
void SoundSfx_RestoreHeapAfterGroupPlayback(unsigned char*);
// Original data: arm9/ov006 @ 0x2160087; symbol: data_ov006_02160087.
// Source-defined character literal. Text: "0". Original zero separators, trailing bytes and padding remain unchanged.
// Initial values: "0".
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov006.md.
// Original data: arm9/ov006 @ 0x2160089; symbol: data_ov006_02160089.
// Source-defined character literal. Text: "1". Original zero separators, trailing bytes and padding remain unchanged.
// Initial values: "1".
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov006.md.
// Original data: arm9/ov006 @ 0x2160092; symbol: data_ov006_02160092.
// Source-defined character literal. Text: "2". Original zero separators, trailing bytes and padding remain unchanged.
// Initial values: "2".
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov006.md.
// Original data: arm9/ov006 @ 0x2160094; symbol: data_ov006_02160094.
// Source-defined character literal. Text: "3". Original zero separators, trailing bytes and padding remain unchanged.
// Initial values: "3".
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov006.md.
// Original data: arm9/ov006 @ 0x216009e; symbol: data_ov006_0216009e.
// Source-defined character literal. Text: "4". Original zero separators, trailing bytes and padding remain unchanged.
// Initial values: "4".
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov006.md.
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern char Main_UnknownRoleZeroInitializedStorage[],KrakPot_AdvanceSceneResourceLoading_TextRenIn[],GraphicsUpdateFlaggedAnimationStages_Text0[],KrakPotStartQueuedAlchemyEffect_Text1[],Graphics_UpdateFlaggedAnimationStages_TextRenkin[],KrakPotStartQueuedAlchemyEffect_Text2[],GraphicsUpdateFlaggedAnimationStages_Text3[],Graphics_UpdateFlaggedAnimationStages_TextRenOut[],GraphicsUpdateFlaggedAnimationStages_Text4[],Graphics_UpdateFlaggedAnimationStages_TextYorokobi[],Graphics_UpdateFlaggedAnimationStages_TextStand[];
}
#define FLAGS (*(unsigned short*)(p+0xae2))
#define STAGE (*(unsigned char*)(p+0xae1))
#define ANIM(o,s,n) _ZN8Object3D18SetAnimationByNameEPKci(p+o,s,n)
// Original: arm9/ov006 @ 0x02155068; symbol: func_ov006_02155068; size: 0x340.
extern "C" void Graphics_UpdateFlaggedAnimationStages(char* p){
void* resources=GameState_ReadPResources(_ZN9GameState11GetInstanceEv());
if(FLAGS&0x2000){GameResources_SetSecondaryFlags((int)resources,0x2000);ANIM(0x4e8,KrakPot_AdvanceSceneResourceLoading_TextRenIn,9);_ZN8Object3D10EnableFlagEi(p+0x4e8,0x1000);return;}
if(FLAGS&0x80){
 if(STAGE==0){SoundSfx_LoadGroupAtCurrentHeapState(Main_UnknownRoleZeroInitializedStorage,0x7a,0x7a);ResourceHandle_InvokeOperationWithValidHalfwordIndex(Main_UnknownRoleZeroInitializedStorage,0,0);ANIM(0x2e4,KrakPot_AdvanceSceneResourceLoading_TextRenIn,1);ANIM(0x43c,GraphicsUpdateFlaggedAnimationStages_Text0,1);ANIM(0x4e8,KrakPot_AdvanceSceneResourceLoading_TextRenIn,9);_ZN8Object3D11DisableFlagEi(p+0x4e8,0x1000);}
 else if(STAGE>=1){if(_ZNK8Object3D19HasAnimationStoppedEv(p+0x2e4)){STAGE=0;FLAGS&=~0x80;ANIM(0x43c,KrakPotStartQueuedAlchemyEffect_Text1,1);ANIM(0x2e4,Graphics_UpdateFlaggedAnimationStages_TextRenkin,0);_ZN8Object3D20StopCurrentAnimationEv(p+0x4e8);return;}}
 STAGE++;return;
}
if(FLAGS&0x100){
 if(!_ZNK8Object3D22HasAnimationReachedEndEv(p+0x2e4))return;
 if(STAGE==0){ANIM(0x43c,KrakPotStartQueuedAlchemyEffect_Text2,0);}
 else if(STAGE==1){ANIM(0x43c,GraphicsUpdateFlaggedAnimationStages_Text3,1);}
 else if(STAGE==2){STAGE=0;_ZN8Object3D20StopCurrentAnimationEv(p+0x2e4);ANIM(0x2e4,Graphics_UpdateFlaggedAnimationStages_TextRenOut,1);ANIM(0x43c,GraphicsUpdateFlaggedAnimationStages_Text4,0);ANIM(0x4e8,Graphics_UpdateFlaggedAnimationStages_TextRenOut,1);FLAGS&=~0x100;return;}
 STAGE++;return;
}
if(FLAGS&0x200){FLAGS|=0x800;if(!_ZNK8Object3D19HasAnimationStoppedEv(p+0x2e4)){STAGE++;return;}
 GameResources_ClearSecondaryFlags((int)resources,0x2000);SoundSfx_RestoreHeapAfterGroupPlayback((unsigned char*)Main_UnknownRoleZeroInitializedStorage);STAGE=0;ANIM(0x2e4,Graphics_UpdateFlaggedAnimationStages_TextYorokobi,1);_ZN8Object3D20StopCurrentAnimationEv(p+0x43c);FLAGS&=~0x200;return;
}
if(FLAGS&0x400){if(_ZNK8Object3D19HasAnimationStoppedEv(p+0x2e4)){STAGE=0;ANIM(0x2e4,Graphics_UpdateFlaggedAnimationStages_TextStand,0);_ZN8Object3D20StopCurrentAnimationEv(p+0x43c);FLAGS&=~0x400;return;}ANIM(0x2e4,Graphics_UpdateFlaggedAnimationStages_TextYorokobi,1);return;}
STAGE=0;ANIM(0x2e4,Graphics_UpdateFlaggedAnimationStages_TextStand,0);_ZN8Object3D20StopCurrentAnimationEv(p+0x43c);
}
