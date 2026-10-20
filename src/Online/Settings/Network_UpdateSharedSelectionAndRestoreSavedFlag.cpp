#include <globaldefs.h>
ARM
extern "C" {
char* WfcUtility_GetEditableConnectionProfile();
void WfcUtility_SetAutomaticIpAddressing(unsigned char);
void WfcUtility_SetAutomaticDnsAddressing(unsigned);
void WfcSettingsList_RedrawVisibleRows();
// Original data: arm9/ov031 @ 0x2290ca0; symbol: data_ov031_02290ca0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern char StartMode6ContextCallback_UnknownRoleZeroInitializedStorage[];
}
// Original: arm9/ov031 @ 0x0222F38C; symbol: func_ov031_0222f38c; size: 0x6C.
// Changes shared selection, preserving the active flag while enabled and restoring it when disabled.
extern "C" void Network_UpdateSharedSelectionAndRestoreSavedFlag(unsigned char value) {
 char* shared=WfcUtility_GetEditableConnectionProfile();
 if(*(unsigned char*)(shared+0xf5)==value)return;
 bool flag;
 if(value)flag=*(unsigned char*)(*(char**)(StartMode6ContextCallback_UnknownRoleZeroInitializedStorage+8)+0x43)!=0;
 else {*(unsigned char*)(*(char**)(StartMode6ContextCallback_UnknownRoleZeroInitializedStorage+8)+0x43)=*(unsigned char*)(shared+0xf6);flag=false;}
 WfcUtility_SetAutomaticIpAddressing(value);
 WfcUtility_SetAutomaticDnsAddressing(flag);
 WfcSettingsList_RedrawVisibleRows();
}
