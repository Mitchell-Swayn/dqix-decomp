#include <globaldefs.h>
ARM
struct Vec {int x,y,z;};struct Command {unsigned type,next;Vec first,second;};
// Original data: arm9/ov000 @ 0x2184264; symbol: data_ov000_02184264.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
extern "C" {extern unsigned CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage[];char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);char* _ZN6Script9Parameter9ToVec3fixEP8Vector3i(void*,Vec*);float _ZNK6Script9Parameter7ToFloatEv(void*);void Overlay_EnqueueLinkedNode(void*);}
// Original: arm9/ov000 @ 0x0216C04C; symbol: func_ov000_0216c04c; size: 0xA8.
extern "C" int Script_QueueTwoVectorCommand59(char* parameters){
Command* command=(Command*)_ZN13SafeAllocator8AllocateEj(CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage[2],32);
command->type=0;command->next=0;command->type=0x59;
char* next=_ZN6Script9Parameter9ToVec3fixEP8Vector3i(parameters,&command->first);
command->second.x=(int)(4096.0f*_ZNK6Script9Parameter7ToFloatEv(next));
command->second.y=(int)(4096.0f*_ZNK6Script9Parameter7ToFloatEv(next+8));
command->second.z=(int)(4096.0f*_ZNK6Script9Parameter7ToFloatEv(next+16));
Overlay_EnqueueLinkedNode(command);return 1;
}
