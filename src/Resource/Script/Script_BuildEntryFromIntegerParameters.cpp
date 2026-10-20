#include <globaldefs.h>
ARM
#pragma opt_common_subs off
namespace Script { struct Parameter { char data[8]; int ToInt() const; }; }
struct SafeAllocator { void *Allocate(unsigned); };
// Original data: arm9/main @ 0x2108ed8; symbol: data_02108ed8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct Loader { SafeAllocator *allocator; void *owner; }; extern "C" Loader ScriptAppendIndexedHalfwordRecord_UnknownRoleZeroInitializedStorage;
struct Entry { void *first,*second; short id; short a,b,c,d; unsigned char type:4; unsigned char flag:4; unsigned char firstCount,secondCount,reserved; };
extern "C" void DisplayLayout_AppendGroup(void *,Entry *);
#pragma always_inline on
static void Initialize(Entry *entry) { entry->first=0; entry->second=0; entry->id=-1; entry->b=0; entry->a=0; entry->d=0; entry->c=0; entry->type=0; entry->flag=0; entry->firstCount=0; entry->secondCount=0; entry->reserved=0; }
// Original: arm9/main @ 0x0207ED48; symbol: func_0207ed48; size: 0x148.
extern "C" int Script_BuildEntryFromIntegerParameters(const Script::Parameter *args) { Entry entry; Initialize(&entry); entry.id=args[0].ToInt(); entry.a=args[1].ToInt(); entry.b=args[2].ToInt(); entry.c=args[3].ToInt(); entry.d=args[4].ToInt(); entry.type=(unsigned char)args[5].ToInt(); entry.flag=(unsigned char)args[6].ToInt()==0; entry.firstCount=args[7].ToInt(); entry.secondCount=args[8].ToInt(); if(entry.firstCount) entry.first=ScriptAppendIndexedHalfwordRecord_UnknownRoleZeroInitializedStorage.allocator->Allocate(entry.firstCount*4); if(entry.secondCount) entry.second=ScriptAppendIndexedHalfwordRecord_UnknownRoleZeroInitializedStorage.allocator->Allocate(entry.secondCount*4); DisplayLayout_AppendGroup(ScriptAppendIndexedHalfwordRecord_UnknownRoleZeroInitializedStorage.owner,&entry); return 1; }
