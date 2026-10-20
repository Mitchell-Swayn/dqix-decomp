#include <globaldefs.h>
ARM
#include <std_library_functions.h>
#define I(p,o) (*(int*)((p)+(o)))
#define U(p,o) (*(unsigned*)((p)+(o)))
#define H(p,o) (*(unsigned short*)((p)+(o)))
#define S(p,o) (*(short*)((p)+(o)))
#define B(p,o) (*(unsigned char*)((p)+(o)))
#define C(p,o) (*(signed char*)((p)+(o)))
#define V(p,o) (*(char**)((p)+(o)))
// Original data: arm9/ov000 @ 0x2184264; symbol: data_ov000_02184264.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
extern "C" char CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage[],Script_QueuePatchedStringNode_TextPac[],Script_QueuePatchedStringNode_TextChr[];extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);extern "C" int _ZNK6Script9Parameter5ToIntEv(const void*);extern "C" const char* _ZNK6Script9Parameter8ToStringEv(const void*);extern "C" void Overlay_EnqueueLinkedNode(void*);
// Original: arm9/ov000 @ 0x0216A570; symbol: Script_QueueNamedStringRecordWithOptionalSelector; size: 0x11C.
extern "C" int CombatScript_QueueCharacterPathWithOptionalSelector(char* params){
char* node=_ZN13SafeAllocator8AllocateEj(U(CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage,8),16);if(!I(params,0)){I(node,0)=0;I(node,4)=0;I(node,0)=20;C(node,8)=-1;const char* text=_ZNK6Script9Parameter8ToStringEv(params);V(node,12)=_ZN13SafeAllocator8AllocateEj(U(CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage,8),strlen(text)+1);strcpy(V(node,12),text);char* suffix=strstr(V(node,12),Script_QueuePatchedStringNode_TextPac);if(suffix)strcpy(suffix,Script_QueuePatchedStringNode_TextChr);}else if(I(params,0)==1){I(node,0)=0;I(node,4)=0;I(node,0)=20;C(node,8)=_ZNK6Script9Parameter5ToIntEv(params);const char* text=_ZNK6Script9Parameter8ToStringEv(params+8);V(node,12)=_ZN13SafeAllocator8AllocateEj(U(CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage,8),strlen(text)+1);strcpy(V(node,12),text);char* suffix=strstr(V(node,12),Script_QueuePatchedStringNode_TextPac);if(suffix)strcpy(suffix,Script_QueuePatchedStringNode_TextChr);}Overlay_EnqueueLinkedNode(node);return 1;
}
