// Original data: arm9/main @ 0x2108844; symbol: data_02108844.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 1180 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct Node { char padding[6]; unsigned char key; char rest[9]; Node *next; Node *group; }; extern "C" unsigned char ScriptExecuteTriggerAction_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x020643FC; symbol: func_020643fc; size: 0x60.
 extern "C" void LinkedList_AppendNodeToMatchingKeyGroup(void *,Node *node) { Node *current=*(Node **)(ScriptExecuteTriggerAction_UnknownRoleZeroInitializedStorage+0x47c); Node *previous; if(!current) { *(Node **)(ScriptExecuteTriggerAction_UnknownRoleZeroInitializedStorage+0x47c)=node; return; } for(;current;previous=current,current=current->group) { if(current->key==node->key) { while(current->next)current=current->next; current->next=node; return; } } if(!current)previous->group=node; }
