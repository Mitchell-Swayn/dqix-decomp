#include <globaldefs.h>
extern "C" void ActionData_GetDefinitionIdentifier();extern "C" int ActionData_BinarySearchDefinitionRecords(void*,void*,void(*)());
#pragma optimization_level 4
// Original: arm9/main @ 0x02079E2C; symbol: func_02079e2c; size: 0x34.
extern "C" ARM void ActionData_FindDefinitionInPrimaryOrSecondaryTable(char* p,void* a){if(ActionData_BinarySearchDefinitionRecords(p,a,ActionData_GetDefinitionIdentifier))return;ActionData_BinarySearchDefinitionRecords(p+12,a,ActionData_GetDefinitionIdentifier);}
