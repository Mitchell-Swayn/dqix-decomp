#include <globaldefs.h>
ARM
extern "C" {void* SystemState_GetGlobalFlags();void* GameResources_GetInstance();void _Z16SetSubBrightnessP13GameResourcesii(void*,int,int);int _Z31IsSubBrightnessTransitionActiveP13GameResources(void*);void CharacterStatus_RestoreSubDisplayAndReleaseResources(void*);void SystemState_ClearFlags(void*,unsigned);void ComputeGrottoAndContextDependentStateFlags(int);}
// Original: arm9/ov003 @ 0x02160E34; symbol: AdvanceSubBrightnessFadeAndClearState; size: 0x90.
// Starts sub brightness fade then clears flags41 and800 after transition completion.
extern "C" int Tavern_FadeOutPartyPreviewAndReleaseResources(unsigned char* self){int done=0;void* global=SystemState_GetGlobalFlags();void* resources=GameResources_GetInstance();if(self[0x4a8]==0){_Z16SetSubBrightnessP13GameResourcesii(resources,-16,8);++self[0x4a8];}else if(self[0x4a8]==1 && !_Z31IsSubBrightnessTransitionActiveP13GameResources(resources)){CharacterStatus_RestoreSubDisplayAndReleaseResources(*(void**)(self+0x318));self[0x4a8]=0;done=1;SystemState_ClearFlags(global,0x41);ComputeGrottoAndContextDependentStateFlags(0);*(unsigned*)(self+0x464)&=~0x800;}return done;}
