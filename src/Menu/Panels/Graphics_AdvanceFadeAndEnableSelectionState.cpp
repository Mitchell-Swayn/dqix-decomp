#include "globaldefs.h"
#include "std_library_functions.h"
#define H(p,o) (*(unsigned short*)((unsigned char*)(p)+(o)))
#define S(p,o) (*(short*)((unsigned char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((unsigned char*)(p)+(o)))
#define P(p,o) (*(unsigned char**)((unsigned char*)(p)+(o)))
#include "Resource/GameResources.h"
#include "System/ColorEffects.h"
// Original data: arm9/main @ 0x2109bf4; symbol: data_02109bf4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct State;struct Nibble{unsigned char screen:4,rest:4;};extern char Main_UnknownRoleZeroInitializedStorage_Variant2[];extern "C" void _Z17SetMainBrightnessP13GameResourcesii(void*,int,int),_Z16SetSubBrightnessP13GameResourcesii(void*,int,int),Window_PopCanvasesAndResetSelection(State*,int),SystemState_ClearFlags(unsigned*,unsigned);extern "C" int _Z28IsBrightnessTransitionActiveP13GameResources(void*);extern "C" bool Bgm_IsTemporarySequencePendingOrPlaying(char*);extern "C" void*SystemState_GetGlobalFlags();
// Original: arm9/ov023 @ 0x021ECAA4; symbol: func_ov023_021ecaa4; size: 0x118.
extern "C" ARM void Graphics_AdvanceFadeAndEnableSelectionState(unsigned char*self){GameResources*resources=GameResources_GetInstance();unsigned phase=self[0x432];if(phase==0){if(!((Nibble*)(self+0x60))->screen)_Z17SetMainBrightnessP13GameResourcesii(resources,-16,15);else _Z16SetSubBrightnessP13GameResourcesii(resources,-16,15);self[0x432]++;}if(phase!=1)return;if(_Z28IsBrightnessTransitionActiveP13GameResources(resources))return;if(self[0x44a]){unsigned kind=self[0x430];if(kind!=0&&kind!=1&&Bgm_IsTemporarySequencePendingOrPlaying(Main_UnknownRoleZeroInitializedStorage_Variant2))return;if(!(H(self,0x438)&32)){if(!((Nibble*)(self+0xc0))->screen)ColorEffect_ConfigureBrightnessAdjust(0x04000050,23,0);else ColorEffect_ConfigureBrightnessAdjust(0x04001050,23,0);}}Window_PopCanvasesAndResetSelection((State*)(self+0xc4),1);H(self,0x438)|=4;if(H(self,0x438)&16)SystemState_ClearFlags((unsigned*)SystemState_GetGlobalFlags(),1);self[0x432]++;}