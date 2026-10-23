#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" int FastIntDivide(int,int);
extern "C" int FastIntModulus(int,int);
struct ScrollState {int unknown;unsigned short position;unsigned short pad;unsigned char* dirty;};
// Original data: arm9/ov031 @ 0x2290ca0; symbol: data_ov031_02290ca0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" ScrollState StartMode6ContextCallback_UnknownRoleZeroInitializedStorage;
// Original data: arm9/ov031 @ 0x2249048; symbol: data_ov031_02249048.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 000502070401060300000000.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" volatile unsigned char GraphicsUpdateBackgroundVerticalScroll_UnknownRoleInitializedBytes[];
// Original: arm9/ov031 @ 0x02230778; symbol: func_ov031_02230778; size: 0x84.
extern "C" void Graphics_UpdateBackgroundVerticalScroll(void*,void*){
 if(!StartMode6ContextCallback_UnknownRoleZeroInitializedStorage.dirty[0x44])return;
 int index=FastIntDivide(StartMode6ContextCallback_UnknownRoleZeroInitializedStorage.position,29);
 int scroll=FastIntModulus(StartMode6ContextCallback_UnknownRoleZeroInitializedStorage.position,29)-51;
 int amount=GraphicsUpdateBackgroundVerticalScroll_UnknownRoleInitializedBytes[index];
 *(unsigned int*)0x04000010=(scroll<<16)&0x1ff0000;
 *(unsigned int*)0x04000018=((scroll+amount)<<16)&0x1ff0000;
 StartMode6ContextCallback_UnknownRoleZeroInitializedStorage.dirty[0x44]=0;
}
