#include <globaldefs.h>
ARM
// Original data: arm9/ov000 @ 0x2184264; symbol: data_ov000_02184264.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
extern "C" {extern unsigned CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage[];int _ZNK6Script9Parameter5ToIntEv(const void*);float _ZNK6Script9Parameter7ToFloatEv(void*);char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);void Overlay_EnqueueLinkedNode(void*);}
struct Command {unsigned type,next;unsigned char index;int angle;};
// Original: arm9/ov000 @ 0x0216D110; symbol: func_ov000_0216d110; size: 0x8C.
extern "C" int Script_QueueFixedRadianCommand8C(char* parameters){
Command* command=(Command*)_ZN13SafeAllocator8AllocateEj(CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage[2],16);
command->type=0;command->next=0;command->type=0x8c;
command->index=_ZNK6Script9Parameter5ToIntEv(parameters);
float degrees=_ZNK6Script9Parameter7ToFloatEv(parameters+8);
command->angle=(int)(4096.0f*((3.1415927410125732f*degrees)/180.0f));
Overlay_EnqueueLinkedNode(command);return 1;
}
