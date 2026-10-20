#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2250ba8; symbol: data_ov031_02250ba8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char *WfcUtilityDestroyBottomButtonBar_UnknownRoleZeroInitializedStorage;
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
extern "C" unsigned char WfcUtilityCreateBottomButtonBar_UnknownRoleInitializedBytes_Variant2[],WfcUtilityCreateBottomButtonBar_UnknownRoleInitializedBytes[][2];
extern "C" void* WfcUtility_GetSpriteGroupEntry(void*,int);
extern "C" void WfcUtility_ExpandSpriteCellTemplate(unsigned,unsigned,void*);
extern "C" void WfcUtility_SetSpriteGroupPriority(void*,int,unsigned);
extern "C" void Graphics_SetSharedModeEntriesFromTables(char*);
extern "C" void WfcUtility_RequestTaskRemoval(unsigned,unsigned);
// Original: arm9/ov031 @ 0x02223268; symbol: Graphics_CompleteTimedSharedSpriteTransition; size: 0xf0.
// At tick sixteen expands mode-selected sprites, restores priority and resolves pending completion.
extern "C" void WfcUtility_RestoreBottomButtonAfterPress(unsigned argument){
++*(unsigned short*)(WfcUtilityDestroyBottomButtonBar_UnknownRoleZeroInitializedStorage+20);
 if(*(unsigned short*)(WfcUtilityDestroyBottomButtonBar_UnknownRoleZeroInitializedStorage+20)<16)return;
 int n=WfcUtilityCreateBottomButtonBar_UnknownRoleInitializedBytes_Variant2[(unsigned char)WfcUtilityDestroyBottomButtonBar_UnknownRoleZeroInitializedStorage[23]];
 for(int i=0;i<n;++i){int v=WfcUtilityCreateBottomButtonBar_UnknownRoleInitializedBytes[(unsigned char)WfcUtilityDestroyBottomButtonBar_UnknownRoleZeroInitializedStorage[23]][i];void *e=WfcUtility_GetSpriteGroupEntry(((void**)WfcUtilityDestroyBottomButtonBar_UnknownRoleZeroInitializedStorage)[i],0);WfcUtility_ExpandSpriteCellTemplate(0,v,e);WfcUtility_SetSpriteGroupPriority(((void**)WfcUtilityDestroyBottomButtonBar_UnknownRoleZeroInitializedStorage)[i],-1,1);}
 Graphics_SetSharedModeEntriesFromTables((char*)168);
 *(unsigned short*)(WfcUtilityDestroyBottomButtonBar_UnknownRoleZeroInitializedStorage+20)=0;WfcUtilityDestroyBottomButtonBar_UnknownRoleZeroInitializedStorage[22]=-1;
 if(*(int*)(WfcUtilityDestroyBottomButtonBar_UnknownRoleZeroInitializedStorage+16)){*(int*)(WfcUtilityDestroyBottomButtonBar_UnknownRoleZeroInitializedStorage+16)=0;WfcUtility_RequestTaskRemoval(0,argument);}
}
