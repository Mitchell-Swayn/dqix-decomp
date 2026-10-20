#include <globaldefs.h>
struct Record { short id; short y; unsigned flags; char* text; };
struct List { float speed; Record* records; unsigned short used, capacity; };
struct Pair { List* list; void* allocator; };
extern "C" {
// Original data: arm9/ov028 @ 0x21d9bc4; symbol: data_ov028_021d9bc4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 28 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov028.md.
extern Pair StaffRollScriptSetScrollSpeed_UnknownRoleZeroInitializedStorage;
void* _ZN13SafeAllocator8AllocateEj(void*, unsigned);
void StaffRoll_InitializeRecord(Record*);
void StaffRoll_InitializeRecordList(List*);
void StaffRoll_InitializeStateAndTiming(void*);
void StaffRoll_ResetTimingAndRestoreDisplay(void*);
void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*);
unsigned _ZNK6Script9Parameter5ToIntEv(void*);
float _ZNK6Script9Parameter7ToFloatEv(void*);
void StaffRoll_AllocateRecords(List*, void*, unsigned short);
}
// Original: arm9/ov028 @ 0x021D97B0; symbol: func_ov028_021d97b0; size: 0x28.
extern "C" int StaffRoll_ScriptAllocateRecords(void* p) { unsigned short n=_ZNK6Script9Parameter5ToIntEv(p); StaffRoll_AllocateRecords(StaffRollScriptSetScrollSpeed_UnknownRoleZeroInitializedStorage.list,StaffRollScriptSetScrollSpeed_UnknownRoleZeroInitializedStorage.allocator,n); return 1; }
