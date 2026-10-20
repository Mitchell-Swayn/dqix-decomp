#include <globaldefs.h>
ARM
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" int Menu_HitTestEnabledLayoutGroups(char*);extern "C" int Input_IsKeyMaskNewlyPressed(unsigned short*,unsigned);extern "C" unsigned short KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov023 @ 0x021E3E98; symbol: SetPanelTransitionWhenSelectionOrInputChanges; size: 0x9c.
extern "C" void Menu_HandlePartyPreviewCloseInput(char* self){
int changed=(Menu_HitTestEnabledLayoutGroups(self+0xd4)==31);if(changed)*(unsigned short*)(self+0x634)|=0x800;if(P(self,0)&&!(W(P(self,0),0x3dcc)&0x400))return;if(Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,2))changed=1;if(!changed)return;*(unsigned short*)(self+0x634)|=0x800;B(self,0x4e7)=*(signed char*)(self+0x4e6);B(self,0x4e6)=1;B(self,0x4e4)=0;
}
