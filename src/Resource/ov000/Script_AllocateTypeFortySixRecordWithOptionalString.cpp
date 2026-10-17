#include <globaldefs.h>
ARM
#include <std_library_functions.h>
extern "C" unsigned data_ov000_02184264[];
extern "C" const char* _ZNK6Script9Parameter8ToStringEv(const void*);
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
extern "C" void Overlay_EnqueueLinkedNode(void*);
struct Record { unsigned type,next; char* text; };
// Original: arm9/ov000 @ 0x0216B180; symbol: func_ov000_0216b180; size: 0x84.
extern "C" int Script_AllocateTypeFortySixRecordWithOptionalString(const void* params,int count) {
 Record* record=(Record*)_ZN13SafeAllocator8AllocateEj(data_ov000_02184264[2],12);
 record->type=0;
 record->next=0;
 record->type=0x2e;
 record->text=0;
 if(count<=1) {
  const char* text=_ZNK6Script9Parameter8ToStringEv(params);
  if(text) {
   record->text=_ZN13SafeAllocator8AllocateEj(data_ov000_02184264[2],strlen(text)+1);
   strcpy(record->text,text);
  }
 }
 Overlay_EnqueueLinkedNode(record);
 return 1;
}
