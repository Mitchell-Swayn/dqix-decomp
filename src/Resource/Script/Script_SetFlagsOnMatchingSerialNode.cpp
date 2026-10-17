#include <globaldefs.h>
#include <Resource/Script.h>
extern "C" { extern unsigned char data_02108cec[]; unsigned char* LinkedList_FindNodeByUnsignedKey(void*,int);
// Original: arm9/main @ 0x0206CA3C; symbol: func_0206ca3c; size: 0x9C.
 ARM int Script_SetFlagsOnMatchingSerialNode(Script::Parameter* params,int count) { int key=(params++)->ToInt(); unsigned char* node=LinkedList_FindNodeByUnsignedKey(*(void**)(data_02108cec+16),key); if(!node)return 0; while(node) { if(*(unsigned short*)(node+68)==*(unsigned short*)(data_02108cec+10))break;node=*(unsigned char**)(node+112); } if(!node)return 0; for(int i=0;i<count-1;i++){ unsigned int flag=(params++)->ToInt();*(unsigned int*)(node+12)|=flag; } return 1; } }
