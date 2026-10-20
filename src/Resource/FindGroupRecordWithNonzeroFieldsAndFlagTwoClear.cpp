#include <globaldefs.h>
#include <Resource/Script.h>
ARM
#pragma optimization_level 3
extern "C" unsigned char* DisplayLayout_FindGroupById(void*,int);extern "C" unsigned char* DisplayLayout_FindPartById(void*,int);
// Original: arm9/main @ 0x02080468; symbol: func_02080468; size: 0x94.
extern "C" int FindGroupRecordWithNonzeroFieldsAndFlagTwoClear(unsigned char* p,int key){int result=-1;unsigned char* group=DisplayLayout_FindGroupById(p+12,key);if(group)for(unsigned char i=0;i<group[19];i++){result=(*(short**)group)[i];unsigned char* entry=DisplayLayout_FindPartById(p+4,result);if(entry&&!(entry[42]&2)&&(*(unsigned*)(entry+24)||*(unsigned*)(entry+28)||*(unsigned*)(entry+32)||*(unsigned*)(entry+36))){result=*(short*)(entry+4);break;}}return result;}
