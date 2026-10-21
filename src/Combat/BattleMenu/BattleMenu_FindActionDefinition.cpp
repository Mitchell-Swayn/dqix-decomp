#include <globaldefs.h>
struct Record {unsigned int field0; unsigned int identifier:12; unsigned int remaining:20;};
extern "C" void* ActionData_GetGlobalTables();
extern "C" void* ActionData_FindDefinitionInPrimaryOrSecondaryTable(char*,int);
// Original: arm9/ov000 @ 0x02170CF8; symbol: func_ov000_02170cf8; size: 0xB8.
// Layout projection only; broader object ownership remains unclassified.
extern "C" ARM Record* BattleMenu_FindActionDefinition(unsigned char* p,unsigned int id) {
 if(!id) return 0; void* owner=ActionData_GetGlobalTables(); if(!owner) return 0;
 Record* result=(Record*)ActionData_FindDefinitionInPrimaryOrSecondaryTable((char*)owner,(short)id); if(result) return result;
 Record** entries=(Record**)(p+0x9c);
 for(unsigned short i=0;i<66;i++) {result=entries[i]; if(result && id==result->identifier) return result;}
 entries=(Record**)(p+0x1a4);
 for(unsigned short i=0;i<147;i++) {result=entries[i]; if(result && id==result->identifier) return result;}
 return 0;
}
