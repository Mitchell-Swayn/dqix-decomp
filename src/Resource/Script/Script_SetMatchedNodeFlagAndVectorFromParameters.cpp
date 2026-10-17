#include <globaldefs.h>
#include "Resource/Script.h"
extern "C" unsigned char data_02108cec[]; extern "C" unsigned char *LinkedList_FindNodeByUnsignedKey(unsigned,int);
// Original: arm9/main @ 0x0206D464; symbol: func_0206d464; size: 0x7C.
extern "C" int Script_SetMatchedNodeFlagAndVectorFromParameters(Script::Parameter *p) { int key=p->ToInt();unsigned char *node=LinkedList_FindNodeByUnsignedKey(*(unsigned *)(data_02108cec+16),key);if(!node)return 0;for(;node;node=*(unsigned char **)(node+0x70)){if(*(unsigned short *)(node+0x44)==*(unsigned short *)(data_02108cec+10))break;}if(!node)return 0;*(unsigned *)(node+12)|=0x2000;(p+1)->ToVec3fix((Vector3i *)(node+0x48));return 1; }
