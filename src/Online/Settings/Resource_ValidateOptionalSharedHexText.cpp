#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290c94; symbol: data_ov031_02290c94.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char* WfcUtilityReleaseWirelessTextEditor_UnknownRoleZeroInitializedStorage;
extern "C" int WfcUtility_ShowFormattedMessagePanel(unsigned,int,int);
extern "C" void WfcUtility_GetScreenOperationArguments(unsigned*,unsigned*);
extern "C" unsigned WfcUtility_CountNonzeroBytePrefix(const unsigned char*,int);
// Original: arm9/ov031 @ 0x0222D524; symbol: func_ov031_0222d524; size: 0x18C.
// Validates optional shared text by accepted lengths and hexadecimal character ranges.
extern "C" bool Resource_ValidateOptionalSharedHexText(){
unsigned first,second;WfcUtility_GetScreenOperationArguments(&first,&second);
if(second==1)WfcUtility_ShowFormattedMessagePanel(53,-1,0);
WfcUtility_GetScreenOperationArguments(&first,&second);
if(first==0)return *(unsigned char*)(WfcUtilityReleaseWirelessTextEditor_UnknownRoleZeroInitializedStorage+8)!=0;
if(second==1 && *(unsigned char*)(WfcUtilityReleaseWirelessTextEditor_UnknownRoleZeroInitializedStorage+8)==0)return false;
int length=WfcUtility_CountNonzeroBytePrefix((unsigned char*)WfcUtilityReleaseWirelessTextEditor_UnknownRoleZeroInitializedStorage+8,32);
switch(length){
case 0:case 5:case 13:case 16:return true;
case 10:case 26:case 32:{
unsigned c;int i=0;unsigned char* p;
if(i<length){p=(unsigned char*)WfcUtilityReleaseWirelessTextEditor_UnknownRoleZeroInitializedStorage;do{c=p[8];if(!((c>='0' && c<='9') || (c>='A' && c<='F') || (c>='a' && c<='f')))return false;++i;++p;}while(i<length);}
return true;}
default:return false;
}
}
