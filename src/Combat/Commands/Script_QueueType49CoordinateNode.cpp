#include <globaldefs.h>
#include <Resource/Script.h>
#include <Memory/SafeAllocator.h>
ARM
#pragma always_inline on
// Original data: arm9/ov000 @ 0x2184264; symbol: data_ov000_02184264.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
extern "C" char CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage[];
extern "C" void Overlay_EnqueueLinkedNode(void*);
struct CoordinateNode {
 unsigned type;CoordinateNode* next;Vector3fix position;unsigned char mode,padding[3];
 inline void Initialize(){type=0;next=0;}
};
// Original: arm9/ov000 @ 0x0216B2BC; symbol: func_ov000_0216b2bc; size: 0x6C.
// Allocates a type-49 coordinate node, reads an optional mode byte and enqueues it.
// Mode semantics and manager ownership remain partial.
extern "C" int Script_QueueType49CoordinateNode(Script::Parameter* parameters,int count) {
 CoordinateNode* node=(CoordinateNode*)(*(SafeAllocator**)(CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage+8))->Allocate(24);
 node->Initialize();
 node->type=49;
 parameters=parameters->ToVec3fix(&node->position);
 unsigned char mode=0;
 if(count>=4)mode=parameters->ToInt();
 node->mode=mode;
 Overlay_EnqueueLinkedNode(node);
 return 1;
}
