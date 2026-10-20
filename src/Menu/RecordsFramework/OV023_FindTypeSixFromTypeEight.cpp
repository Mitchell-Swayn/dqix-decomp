#include <globaldefs.h>
ARM
extern "C" void* Menu_GetDisplayRecordRegistry(void*);
extern "C" void* MenuRecordList_LocateByKey(void**, unsigned short);
extern "C" unsigned MenuRecord_GetType(void*);
// Original: arm9/ov023 @ 0x021F9CB8; symbol: func_ov023_021f9cb8; size: 0x5C.
extern "C" void* OV023_FindTypeSixFromTypeEight(unsigned unused, void* stateObject, void* candidate) {
    if (candidate == 0) return 0;
    if (MenuRecord_GetType(candidate) != 8) return 0;
    unsigned short value = *(unsigned short*)((char*)candidate + 0x34);
    void* state = Menu_GetDisplayRecordRegistry(stateObject);
    void* result = MenuRecordList_LocateByKey((void**)state, value);
    if (result == 0) return 0;
    if (MenuRecord_GetType(result) != 6) return 0;
    return result;
}
