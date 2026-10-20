#include <globaldefs.h>
#include <std_library_functions.h>
ARM
struct Record { char pad[12];char name[180]; };
struct Global { unsigned char count,pad[4],matches;unsigned char pad2[0x26];Record* output; };
// Original data: arm9/ov031 @ 0x2291e04; symbol: data_ov031_02291e04.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 56 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" Global ScriptSetIndexedNetworkWord_UnknownRoleZeroInitializedStorage;
extern "C" const char* _ZNK6Script9Parameter8ToStringEv(const void*);
extern "C" Record* Overlay_TryGetInterruptSafeEntry(int);
// Original: arm9/ov031 @ 0x02243348; symbol: func_ov031_02243348; size: 0x88.
extern "C" int Script_CopyUpToEightNameMatchedRecords(const void* parameter) {
const char* name=_ZNK6Script9Parameter8ToStringEv(parameter);
int count=0;
for(int i=0;i<ScriptSetIndexedNetworkWord_UnknownRoleZeroInitializedStorage.count;++i){
Record* record=Overlay_TryGetInterruptSafeEntry(i);
if(!strcmp(record->name,name)){
memcpy(&ScriptSetIndexedNetworkWord_UnknownRoleZeroInitializedStorage.output[count],record,0xc0);
++count;if(count>=8)break;
}
}
ScriptSetIndexedNetworkWord_UnknownRoleZeroInitializedStorage.matches=count;
return 1;
}
