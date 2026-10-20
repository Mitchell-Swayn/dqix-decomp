#include <globaldefs.h>
ARM
struct Table { int entries[9]; };
struct Flags { unsigned index:4; unsigned rest:28; };
// Original data: arm9/ov003 @ 0x217fb68; symbol: data_ov003_0217fb68.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0700000008000000000000000100000006000000040000000500000009000000ffffffff.
// Observed span: 36 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov003.md.
extern "C" { void* _ZN9GameState11GetInstanceEv(); char* GameState_GetObjectWithFlag100(void*,int); int GameObject_GetLinkedStatOrInvalid(char*,int); void* ZoneState2754_FindPrimaryRecordByKey(void*,int); extern Table ResourceFindLinkedSerializedRecordOrFallback_UnknownRoleInitializedBytes; }
// Original: arm9/ov003 @ 0x02179CFC; symbol: func_ov003_02179cfc; size: 0xAC.
extern "C" void* Resource_FindLinkedSerializedRecordOrFallback(unsigned char* owner,int id,unsigned char* fallback) {
 char* object=GameState_GetObjectWithFlag100(_ZN9GameState11GetInstanceEv(),id);
 if(!object) return fallback;
 Table table=ResourceFindLinkedSerializedRecordOrFallback_UnknownRoleInitializedBytes;
 int key=GameObject_GetLinkedStatOrInvalid(object,table.entries[((Flags*)(fallback+8))->index]);
 if(key==-1) return fallback;
 void* result=ZoneState2754_FindPrimaryRecordByKey(owner+0x874,key);
 if(!result) result=fallback;
 else *(short*)(owner+0x1048)=key;
 return result;
}
