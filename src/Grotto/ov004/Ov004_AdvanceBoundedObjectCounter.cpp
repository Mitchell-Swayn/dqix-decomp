#include <globaldefs.h>
extern "C" void* OV011_GetObjectIfFieldValueSeven(void*, unsigned);
extern "C" void func_ov004_02158fec(void*);
// Original: arm9/ov004 @ 0x0215CDAC; symbol: func_ov004_0215cdac; size: 0x44.
extern "C" ARM int Ov004_AdvanceBoundedObjectCounter(void* object) {
    void* record = OV011_GetObjectIfFieldValueSeven(object, 0x5b);
    short current = *(short*)((char*)record + 0x5c);
    short limit = *(short*)((char*)record + 0x5e);
    short next = current + 1;
    if (limit <= next) next = 0;
    *(short*)((char*)record + 0x5c) = next;
    *(short*)((char*)record + 0x5e) = limit;
    func_ov004_02158fec(object);
    return 0;
}
