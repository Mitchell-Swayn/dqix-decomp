#include <globaldefs.h>
ARM
#pragma optimize_for_size off
#include <Resource/Script.h>
// Original data: arm9/main @ 0x2108cec; symbol: data_02108cec.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct Node{unsigned char pad[0x38];int value;unsigned char pad3c[8];unsigned short id;unsigned char pad46[0x2a];Node* next;};struct State{unsigned char pad[10];unsigned short id;int padc;void* object;};extern "C" {extern State ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage;Node* LinkedList_FindNodeByUnsignedKey(void*,int);
// Original: arm9/main @ 0x0206CB48; symbol: func_0206cb48; size: 0x84.
int Script_SetSelectedNodeFixedPointValue(Script::Parameter* p){int id=p->ToInt();Node* n=LinkedList_FindNodeByUnsignedKey(ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage.object,id);if(!n)return 0;while(n){if(n->id==ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage.id)break;n=n->next;}if(!n)return 0;n->value=(int)(4096.0f*(p+1)->ToFloat());return 1;}}
