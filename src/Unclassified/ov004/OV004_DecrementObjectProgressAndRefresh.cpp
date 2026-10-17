#include <globaldefs.h>
ARM
extern "C" void *OV011_GetObjectIfFieldValueSeven(void *, unsigned int);
extern "C" void func_ov004_0215a738(void *);
// Original: arm9/ov004 @ 0x0215CE7C; symbol: func_ov004_0215ce7c; size: 0x48.
extern "C" int OV004_DecrementObjectProgressAndRefresh(void *owner) {
    void *object = OV011_GetObjectIfFieldValueSeven(owner, 0x63);
    short next = *(short *)((char *)object + 0x5c) - 1;
    short limit = *(short *)((char *)object + 0x5e);
    if (next < 0) next = limit - 1;
    *(short *)((char *)object + 0x5c) = next;
    *(short *)((char *)object + 0x5e) = limit;
    func_ov004_0215a738(owner);
    return 0;
}
