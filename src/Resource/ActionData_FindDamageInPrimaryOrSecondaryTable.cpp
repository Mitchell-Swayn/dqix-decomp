#include <globaldefs.h>
ARM
#pragma optimize_for_size off
extern "C" void ActionData_GetDamageIdentifier();
extern "C" int ResourceIndex_FindEntryByExtractedKey(char*,unsigned,void(*)());
// Original: arm9/main @ 0x02079EE0; symbol: func_02079ee0; size: 0x40.
extern "C" int ActionData_FindDamageInPrimaryOrSecondaryTable(char* p,unsigned value){
    if(!value)return 0;
    int result=ResourceIndex_FindEntryByExtractedKey(p+24,value,ActionData_GetDamageIdentifier);
    if(result)return result;
    return ResourceIndex_FindEntryByExtractedKey(p+36,value,ActionData_GetDamageIdentifier);
}
