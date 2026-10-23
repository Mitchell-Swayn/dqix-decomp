#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
// Original data: arm9/ov031 @ 0x2248924; symbol: data_ov031_02248924.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 271f25002700231d210059002721.
// Observed span: 14 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x2248940; symbol: data_ov031_02248940.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 02010102010102000d003c00e6005e000d002800e6007000.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x2250ba8; symbol: data_ov031_02250ba8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" {extern unsigned char WfcUtilityCreateBottomButtonBar_UnknownRoleInitializedBytes_Variant2[],WfcUtilityCreateBottomButtonBar_UnknownRoleInitializedBytes[];extern unsigned char* WfcUtilityDestroyBottomButtonBar_UnknownRoleZeroInitializedStorage;void* Memory_AllocateZeroedBlock(unsigned);void* WfcUtility_CreateSpriteGroupFromCellTemplate(int,unsigned,int);void WfcUtility_SetSpriteGroupPriority(void*,int,unsigned);void Graphics_SetSharedModeEntriesFromTables(char*);void* WfcUtility_CreateTaskWithBorrowedContext(unsigned,void (*)(void*,void*),void*,unsigned);void WfcUtility_SlideBottomButtonBarIn(void*,void*);}
// Original: arm9/ov031 @ 0x02222CE4; symbol: Graphics_AllocateModeSpritesAndScheduleCallback; size: 0xf8.
// Allocates mode-dependent sprite handles and schedules shared callback; allocator canonical declaration takes size only.
extern "C" void WfcUtility_CreateBottomButtonBar(int mode){int count=WfcUtilityCreateBottomButtonBar_UnknownRoleInitializedBytes_Variant2[mode];WfcUtilityDestroyBottomButtonBar_UnknownRoleZeroInitializedStorage=(unsigned char*)((void*(*)(unsigned,unsigned))Memory_AllocateZeroedBlock)(28,4);signed char priority=-2;((signed char*)WfcUtilityDestroyBottomButtonBar_UnknownRoleZeroInitializedStorage)[22]=priority;WfcUtilityDestroyBottomButtonBar_UnknownRoleZeroInitializedStorage[23]=mode;int i=0;if(count>0){unsigned char* ids=WfcUtilityCreateBottomButtonBar_UnknownRoleInitializedBytes+mode*2;do{P(WfcUtilityDestroyBottomButtonBar_UnknownRoleZeroInitializedStorage,i*4)=(unsigned char*)WfcUtility_CreateSpriteGroupFromCellTemplate(0,*ids++,1);WfcUtility_SetSpriteGroupPriority(P(WfcUtilityDestroyBottomButtonBar_UnknownRoleZeroInitializedStorage,i*4),priority+1,1);++i;}while(i<count);}P(WfcUtilityDestroyBottomButtonBar_UnknownRoleZeroInitializedStorage,8)=(unsigned char*)WfcUtility_CreateSpriteGroupFromCellTemplate(0,1,1);WfcUtility_SetSpriteGroupPriority(P(WfcUtilityDestroyBottomButtonBar_UnknownRoleZeroInitializedStorage,8),-1,1);Graphics_SetSharedModeEntriesFromTables((char*)192);P(WfcUtilityDestroyBottomButtonBar_UnknownRoleZeroInitializedStorage,12)=(unsigned char*)WfcUtility_CreateTaskWithBorrowedContext(0,WfcUtility_SlideBottomButtonBarIn,0,120);}
