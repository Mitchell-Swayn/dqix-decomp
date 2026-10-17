#include <globaldefs.h>
struct Record { short id; short y; unsigned flags; char* text; };
struct List { float speed; Record* records; unsigned short used, capacity; };
struct Pair { List* list; void* allocator; };
extern "C" {
extern Pair data_ov028_021d9bc4;
void* _ZN13SafeAllocator8AllocateEj(void*, unsigned);
void func_ov028_021d987c(Record*);
void func_ov028_021d98b8(List*);
void func_ov028_021d9494(void*);
void func_ov028_021d94e4(void*);
void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*);
unsigned _ZNK6Script9Parameter5ToIntEv(void*);
float _ZNK6Script9Parameter7ToFloatEv(void*);
void func_ov028_021d9940(List*, void*, unsigned short);
}
// Original: arm9/ov028 @ 0x021D987C; symbol: func_ov028_021d987c; size: 0x1C.
extern "C" void func_ov028_021d987c(Record* p) { p->id=-1; p->y=0; p->flags=0; p->text=0; }
