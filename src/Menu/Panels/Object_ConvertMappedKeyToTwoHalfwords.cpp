#include <globaldefs.h>
extern "C" char* MenuLayout_FindGroupByKey(char*, int);
extern "C" void Menu_GetLayoutCellScreenCoordinates(void*, int, short*, short*);
// Original: arm9/ov023 @ 0x021E2BDC; symbol: func_ov023_021e2bdc; size: 0x5C.
extern "C" void Object_ConvertMappedKeyToTwoHalfwords(void* object, int key, short* outputA, short* outputB) {
    char* record = MenuLayout_FindGroupByKey((char*)object, key);
    if (record && *(unsigned short*)(record + 2) != 0) {
        void* value = *(void**)(record + 4);
        if (value) {
            short localA, localB;
            Menu_GetLayoutCellScreenCoordinates(object, *(short*)value, &localA, &localB);
            *outputA = localA;
            *outputB = localB;
        }
    }
}
