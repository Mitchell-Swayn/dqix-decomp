#include <globaldefs.h>
#include "Resource/Script.h"
// Original data: arm9/main @ 0x2108cec; symbol: data_02108cec.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage[]; extern "C" unsigned char *LinkedList_FindNodeByUnsignedKey(unsigned,int);
// Original: arm9/main @ 0x0206D464; symbol: func_0206d464; size: 0x7C.
extern "C" int Script_SetMatchedNodeFlagAndVectorFromParameters(Script::Parameter *p) { int key=p->ToInt();unsigned char *node=LinkedList_FindNodeByUnsignedKey(*(unsigned *)(ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage+16),key);if(!node)return 0;for(;node;node=*(unsigned char **)(node+0x70)){if(*(unsigned short *)(node+0x44)==*(unsigned short *)(ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage+10))break;}if(!node)return 0;*(unsigned *)(node+12)|=0x2000;(p+1)->ToVec3fix((Vector3i *)(node+0x48));return 1; }
