#include <globaldefs.h>
ARM
// Original data: arm9/ov000 @ 0x2184264; symbol: data_ov000_02184264.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
extern "C" { int _ZNK6Script9Parameter5ToIntEv(const void*); char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned); void Overlay_EnqueueLinkedNode(void*); extern unsigned CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage[]; }
// Original: arm9/ov000 @ 0x0216C85C; symbol: func_ov000_0216c85c; size: 0x88.
extern "C" int Resource_AllocateType115ScriptCommand(unsigned char* parameters,int count) {
 char* record=_ZN13SafeAllocator8AllocateEj(CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage[2],16);
 if(!record) return 0;
 unsigned short index;
 int value=_ZNK6Script9Parameter5ToIntEv(parameters);
 index=_ZNK6Script9Parameter5ToIntEv(parameters+8);
 unsigned char flag=0;
 if(count>=3) flag=_ZNK6Script9Parameter5ToIntEv(parameters+16);
 *(int*)(record+8)=value;
 *(unsigned short*)(record+12)=index-26;
 record[14]=flag;
 *(int*)record=115;
 Overlay_EnqueueLinkedNode(record);
 return 1;
}
