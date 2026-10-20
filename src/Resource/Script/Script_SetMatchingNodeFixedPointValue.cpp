#include "globaldefs.h"
#pragma optimize_for_size off
ARM
// Original data: arm9/main @ 0x2108cec; symbol: data_02108cec.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct Parameter{unsigned words[2];};struct Node{unsigned char pad[12];unsigned flags;unsigned char pad2[0x2c];int value;unsigned pad3;unsigned short id;unsigned char pad4[0x2a];Node*next;};struct State{unsigned char pad[10];unsigned short id;unsigned pad2;void*list;};extern "C" State ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage;extern "C" int _ZNK6Script9Parameter5ToIntEv(const Parameter*);extern "C" float _ZNK6Script9Parameter7ToFloatEv(const Parameter*);extern "C" Node* LinkedList_FindNodeByUnsignedKey(void*,int);
// Original: arm9/main @ 0x0206D3D4; symbol: func_0206d3d4; size: 0x90.
extern "C" int Script_SetMatchingNodeFixedPointValue(const Parameter*p){int id=_ZNK6Script9Parameter5ToIntEv(p);Node*n=LinkedList_FindNodeByUnsignedKey(ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage.list,id);if(!n)return 0;while(n){if(n->id==ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage.id)break;n=n->next;}if(!n)return 0;float value=_ZNK6Script9Parameter7ToFloatEv(p+1);n->value=(int)(4096.0f*value);n->flags|=0x800;return 1;}
