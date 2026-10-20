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
// Original: arm9/ov028 @ 0x021D987C; symbol: func_ov028_021d987c; size: 0x1C.
extern "C" void StaffRoll_InitializeRecord(Record* p) { p->id=-1; p->y=0; p->flags=0; p->text=0; }
