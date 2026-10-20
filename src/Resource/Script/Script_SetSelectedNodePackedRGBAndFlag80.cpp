#include <globaldefs.h>
#include "Resource/Script.h"
// Original data: arm9/main @ 0x2108cec; symbol: data_02108cec.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct Node {char pad[0xa];unsigned char flags;char pad2[0x15];unsigned short color;char pad3[0x22];unsigned short id;char pad4[0x2a];Node* next;};struct Context {char pad[0xa];unsigned short id;unsigned unused;void* list;};extern "C" {extern Context ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage;Node* LinkedList_FindNodeByUnsignedKey(void*,int);
// Original: arm9/main @ 0x0206D9D8; symbol: func_0206d9d8; size: 0x9C.
int Script_SetSelectedNodePackedRGBAndFlag80(Script::Parameter* args){int id=args[0].ToInt();Node* n=LinkedList_FindNodeByUnsignedKey(ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage.list,id);if(!n)return 0;for(;n;n=n->next){if(n->id==ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage.id)break;}if(!n)return 0;int r=args[1].ToInt(),g=args[2].ToInt(),b=args[3].ToInt();n->color=r|(g<<5)|(b<<10);n->flags|=0x80;return 1;} }
