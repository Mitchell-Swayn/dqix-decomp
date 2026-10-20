#include <globaldefs.h>
ARM
extern "C" unsigned strlen(const char*);
extern "C" char* strcpy(char*,const char*);
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void*);
extern "C" const char* _ZNK6Script9Parameter8ToStringEv(const void*);
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
extern "C" void Overlay_EnqueueLinkedNode(void*);
// Original data: arm9/ov000 @ 0x2184264; symbol: data_ov000_02184264.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
extern "C" unsigned CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov000 @ 0x0216B7B8; symbol: func_ov000_0216b7b8; size: 0xB8.
extern "C" int Resource_ScriptQueueType3BWithCopiedString(unsigned char* p){
 unsigned char* record=(unsigned char*)_ZN13SafeAllocator8AllocateEj(CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage[2],16);
 if(!record)return 0;
 *(int*)record=0;*(int*)(record+4)=0;*(int*)record=59;
 record[8]=(unsigned char)_ZNK6Script9Parameter5ToIntEv(p)-26;
 record[9]=(unsigned char)_ZNK6Script9Parameter5ToIntEv(p+8)-26;
 const char* text=_ZNK6Script9Parameter8ToStringEv(p+16);
 if(text){
 *(char**)(record+12)=_ZN13SafeAllocator8AllocateEj(CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage[2],strlen(text)+1);
 if(*(char**)(record+12))strcpy(*(char**)(record+12),text);
 }else *(char**)(record+12)=0;
 Overlay_EnqueueLinkedNode(record);
 return 1;
}
