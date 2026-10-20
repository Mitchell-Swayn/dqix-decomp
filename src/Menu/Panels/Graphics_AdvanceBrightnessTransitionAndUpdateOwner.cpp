#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021E3DB0; symbol: func_021e3db0; size: 0xE8.
extern "C" void* _ZN9GameState11GetInstanceEv(); extern "C" void* GameState_ReadPResources(void*); extern "C" void _Z13SetBrightnessP13GameResourcesii(void*,int,int); extern "C" int _Z28IsBrightnessTransitionActiveP13GameResources(void*);
extern "C" unsigned _ZNK9GameState12GetTickCountEv(void*); extern "C" void Menu_HandlePartyPreviewMemberSwitch(void*); extern "C" void Menu_UpdateCharacterPreviewRotation(void*,unsigned); extern "C" void Menu_CommitLoadedCharacterPreviewSwap(void*); extern "C" void Graphics_ApplyPendingObjectAnimationTransition(void*); extern "C" void Menu_HandlePartyPreviewCloseInput(void*); extern "C" void EquipmentMenu_UpdateController(void*);
extern "C" void CharacterPreview_ConsumeLoadedModelsAndAnimations(void*);
extern "C" void Graphics_AdvanceBrightnessTransitionAndUpdateOwner(void *self) {
 unsigned char *p=(unsigned char*)self; void *gs=_ZN9GameState11GetInstanceEv(); void *resources=GameState_ReadPResources(gs);
 if(*(void**)(p+0x128)) CharacterPreview_ConsumeLoadedModelsAndAnimations(*(void**)(p+0x128)); if(*(void**)(p+0x12c)) CharacterPreview_ConsumeLoadedModelsAndAnimations(*(void**)(p+0x12c));
 unsigned char state=p[0x4e4];
 if(state==0){ if(*(void**)(p+0x128) && *((unsigned char*)*(void**)(p+0x128)+0xc12)) return; _Z13SetBrightnessP13GameResourcesii(resources,0,15); p[0x4e4]=p[0x4e4]+1; }
 else if(state==1){ if(!_Z28IsBrightnessTransitionActiveP13GameResources(resources)) p[0x4e4]=p[0x4e4]+1; }
 else if(state==2){ Menu_HandlePartyPreviewMemberSwitch(p); gs=_ZN9GameState11GetInstanceEv(); Menu_UpdateCharacterPreviewRotation(p,_ZNK9GameState12GetTickCountEv(gs)); Menu_CommitLoadedCharacterPreviewSwap(p); Graphics_ApplyPendingObjectAnimationTransition(p); Menu_HandlePartyPreviewCloseInput(p); }
 if(*(void**)p) EquipmentMenu_UpdateController(*(void**)p);
}
