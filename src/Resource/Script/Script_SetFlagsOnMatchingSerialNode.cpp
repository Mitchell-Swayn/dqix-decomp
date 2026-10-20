#include <globaldefs.h>
#include <Resource/Script.h>
// Original data: arm9/main @ 0x2108cec; symbol: data_02108cec.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" { extern unsigned char ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage[]; unsigned char* LinkedList_FindNodeByUnsignedKey(void*,int);
// Original: arm9/main @ 0x0206CA3C; symbol: func_0206ca3c; size: 0x9C.
 ARM int Script_SetFlagsOnMatchingSerialNode(Script::Parameter* params,int count) { int key=(params++)->ToInt(); unsigned char* node=LinkedList_FindNodeByUnsignedKey(*(void**)(ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage+16),key); if(!node)return 0; while(node) { if(*(unsigned short*)(node+68)==*(unsigned short*)(ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage+10))break;node=*(unsigned char**)(node+112); } if(!node)return 0; for(int i=0;i<count-1;i++){ unsigned int flag=(params++)->ToInt();*(unsigned int*)(node+12)|=flag; } return 1; } }
