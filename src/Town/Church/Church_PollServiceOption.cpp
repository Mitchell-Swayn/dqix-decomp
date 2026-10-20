#include <globaldefs.h>
ARM
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" void Graphics_ConfigureTwoSelectionsFromMode(unsigned char*);extern "C" void Selection_EnableTouchInput(void*);extern "C" void Selection_EnableDirectionalInput(void*);extern "C" int Selection_ReadEnabledIndexFromControl(void*);extern "C" int Church_IsSelectionConfirmed(char*);extern "C" int Church_IsSelectionCancelled(unsigned char*,int);extern "C" void Church_SetWindowEmphasisAndRefreshText(char*,int,int);extern "C" void SoundSfx_StartCurrentSequenceArchiveEntry(char*,int,void*);extern "C" void Selection_DisableTouchInput(void*);extern "C" void Selection_DisableDirectionalInput(void*);extern "C" char Main_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov003 @ 0x0215B7A4; symbol: Graphics_PollSelectionAndReturnMappedResult; size: 0xFC.
extern "C" int Church_PollServiceOption(char* self){unsigned state=B(self,0x581);if(state==0){Graphics_ConfigureTwoSelectionsFromMode((unsigned char*)self);Selection_EnableTouchInput(self+0xf4);Selection_EnableDirectionalInput(self+0xf4);B(self,0x581)++;}if(state==1){B(self,0x59f)|=1;B(self,0x584)=Selection_ReadEnabledIndexFromControl(self+0xf4);if(Church_IsSelectionConfirmed(self)){B(self,0x59f)&=~1;Church_SetWindowEmphasisAndRefreshText(self,1,1);SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);Selection_DisableTouchInput(self+0xf4);Selection_DisableDirectionalInput(self+0xf4);B(self,0x581)=0;return S(self+S(self,0x584),0x58a);}if(Church_IsSelectionCancelled((unsigned char*)self,1)){Selection_DisableTouchInput(self+0xf4);Selection_DisableDirectionalInput(self+0xf4);B(self,0x581)=0;return -2;}}return -1;}
