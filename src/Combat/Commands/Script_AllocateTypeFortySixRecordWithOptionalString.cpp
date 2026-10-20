#include <globaldefs.h>
ARM
#include <std_library_functions.h>
// Original data: arm9/ov000 @ 0x2184264; symbol: data_ov000_02184264.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
extern "C" unsigned CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage[];
extern "C" const char* _ZNK6Script9Parameter8ToStringEv(const void*);
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
extern "C" void Overlay_EnqueueLinkedNode(void*);
struct Record { unsigned type,next; char* text; };
// Original: arm9/ov000 @ 0x0216B180; symbol: func_ov000_0216b180; size: 0x84.
extern "C" int Script_AllocateTypeFortySixRecordWithOptionalString(const void* params,int count) {
 Record* record=(Record*)_ZN13SafeAllocator8AllocateEj(CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage[2],12);
 record->type=0;
 record->next=0;
 record->type=0x2e;
 record->text=0;
 if(count<=1) {
  const char* text=_ZNK6Script9Parameter8ToStringEv(params);
  if(text) {
   record->text=_ZN13SafeAllocator8AllocateEj(CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage[2],strlen(text)+1);
   strcpy(record->text,text);
  }
 }
 Overlay_EnqueueLinkedNode(record);
 return 1;
}
