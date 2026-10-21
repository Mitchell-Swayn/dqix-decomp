#include <globaldefs.h>
struct SearchTable { unsigned count:12; unsigned rest:20; char* data; };
extern "C" unsigned ActionData_GetDefinitionIdentifier(char*);
extern "C" void* ActionData_BinarySearchDefinitionRecords(SearchTable* table,int key,unsigned (*getKey)(char*));
extern "C" void* ActionData_FindDefinitionInPrimaryOrSecondaryTable(char*,int);
#pragma optimization_level 4
// Original: arm9/main @ 0x02079E2C; symbol: func_02079e2c; size: 0x34.
extern "C" ARM void* ActionData_FindDefinitionInPrimaryOrSecondaryTable(char* p,int a){if(void* found=ActionData_BinarySearchDefinitionRecords((SearchTable*)p,a,ActionData_GetDefinitionIdentifier))return found;return ActionData_BinarySearchDefinitionRecords((SearchTable*)(p+12),a,ActionData_GetDefinitionIdentifier);}
