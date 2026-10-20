#include <globaldefs.h>
ARM
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" int Menu_HitTestEnabledLayoutGroups(void*);extern "C" int Input_IsKeyMaskNewlyPressed(void*,unsigned);extern "C" char KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov006 @ 0x02159BB0; symbol: ClassifySelectionOrNewInputAction; size: 0xb4.
extern "C" int KrakPot_ClassifyRecipeBrowserAction(char* self){
int a=0,b=0,c=0,d=0;int key=Menu_HitTestEnabledLayoutGroups(self+256);if(key>=0){if(key==65)a=1;b=key==66;c=key==19;d=key==38;}else{if(Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,4))c=1;if(Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x300))d=1;}if(c)return 1;if(a)return 2;if(b)return 3;if(d)return 4;return 0;
}
