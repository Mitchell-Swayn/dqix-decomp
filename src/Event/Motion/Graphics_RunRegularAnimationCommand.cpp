#include <globaldefs.h>
ARM
// Original data: arm9/ov001 @ 0x2165884; symbol: data_ov001_02165884.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 52 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" { int _fflt(int); int Graphics_HasIndexedSlotAnimationStopped(void*,int); int Graphics_SetIndexedObjectRegularAnimation(void*,int,const char*,int,unsigned); extern void* AdvanceSessionCommandLists_UnknownRoleZeroInitializedStorage; }
// Original: arm9/ov001 @ 0x02159A74; symbol: func_ov001_02159a74; size: 0x90.
extern "C" int Graphics_RunRegularAnimationCommand(unsigned char* command,unsigned char* context) {
 if(!*(int*)(command+0x18)) {
 if(Graphics_HasIndexedSlotAnimationStopped(AdvanceSessionCommandLists_UnknownRoleZeroInitializedStorage,*(int*)(context+0x70))) {
 unsigned rate=_fflt(*(int*)(command+0x14));
 Graphics_SetIndexedObjectRegularAnimation(AdvanceSessionCommandLists_UnknownRoleZeroInitializedStorage,*(int*)(context+0x70),(const char*)command+0x1c,*(int*)(command+0x10),rate);
 unsigned* next=*(unsigned**)(command+0x3c);
 if(next && *next==13) return 0;
 *(int*)(command+0x18)=1;
 return 1;
 }
 return 1;
 }
 return 0;
}
