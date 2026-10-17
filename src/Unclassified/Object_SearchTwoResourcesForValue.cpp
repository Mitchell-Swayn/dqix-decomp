#include <globaldefs.h>
ARM
#pragma optimize_for_size off
extern "C" void Word_ReadValue();
extern "C" int FindEightByteRecordByCallbackBinarySearch(char*,unsigned,void(*)());
// Original: arm9/main @ 0x02079EE0; symbol: func_02079ee0; size: 0x40.
extern "C" int Object_SearchTwoResourcesForValue(char* p,unsigned value){
    if(!value)return 0;
    int result=FindEightByteRecordByCallbackBinarySearch(p+24,value,Word_ReadValue);
    if(result)return result;
    return FindEightByteRecordByCallbackBinarySearch(p+36,value,Word_ReadValue);
}
