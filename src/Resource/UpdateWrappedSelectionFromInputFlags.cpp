#include <globaldefs.h>
#include <Resource/Script.h>
ARM
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" int Input_IsKeyMaskNewlyPressed(void*,unsigned);extern "C" unsigned char KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x02045740; symbol: func_02045740; size: 0xA0.
extern "C" void UpdateWrappedSelectionFromInputFlags(int* p){p[0x958/4]=(p[0x958/4]+1)&31;if(Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,64)){int n=p[0x954/4]-1;p[0x954/4]=n;if(n<0)p[0x954/4]=p[0x9a4/4]-1;p[0x994/4]=p[0x954/4];p[0x958/4]=0;return;}if(!Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,128))return;int n=p[0x954/4]+1;p[0x954/4]=n;if(n>=p[0x9a4/4])p[0x954/4]=0;p[0x994/4]=p[0x954/4];p[0x958/4]=0;}
