#include <globaldefs.h>
#pragma optimize_for_size off
#pragma opt_common_subs off
#include <Resource/Script.h>
// Original data: arm9/main @ 0x2109bc8; symbol: data_02109bc8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" {extern unsigned char* ScriptApplyIdsWhenPackedDecimalRangeMatches_UnknownRoleZeroInitializedStorage;void Script_AppendSelectedId(void*,unsigned short);
// Original: arm9/main @ 0x0209BED8; symbol: func_0209bed8; size: 0x124.
ARM int Script_ApplyIdsWhenPackedDecimalRangeMatches(Script::Parameter* params,int count){if(!*(int*)(ScriptApplyIdsWhenPackedDecimalRangeMatches_UnknownRoleZeroInitializedStorage+8))return 1;unsigned int key=params->ToInt();if(key!=*(unsigned short*)(ScriptApplyIdsWhenPackedDecimalRangeMatches_UnknownRoleZeroInitializedStorage+6))return 1;Script::Parameter* second=params+1;params+=2;int packed=second->ToInt();int a=(packed>>24)&15,b=(packed>>16)&15,c=(packed>>8)&15,d=packed&15;int lower=a*100+b,upper=c*100+d;int value=*(unsigned short*)(ScriptApplyIdsWhenPackedDecimalRangeMatches_UnknownRoleZeroInitializedStorage+4);bool selected=false;if(lower<=value && value<=upper){*(int*)(ScriptApplyIdsWhenPackedDecimalRangeMatches_UnknownRoleZeroInitializedStorage+8)=0;selected=true;}else if(!a && !b && !c && !d)selected=true;if(selected){for(int i=0;i<count-2;i++){int entry=(params++)->ToInt();unsigned short high=(int)entry>>16,low=entry;if(high)Script_AppendSelectedId(*(void**)ScriptApplyIdsWhenPackedDecimalRangeMatches_UnknownRoleZeroInitializedStorage,high);if(low)Script_AppendSelectedId(*(void**)ScriptApplyIdsWhenPackedDecimalRangeMatches_UnknownRoleZeroInitializedStorage,low);}}return 1;} }
