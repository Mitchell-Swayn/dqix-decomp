#include <globaldefs.h>
ARM
extern "C" int GetTypeSevenRowMajorIndex(void*, unsigned);
extern "C" int func_ov004_021570a4(void*, unsigned);
extern "C" unsigned char data_ov004_021707d8[];
extern "C" void InvokeEntryHandlerForStateKey(void*, unsigned, unsigned);
extern "C" void func_ov004_02159384(void*);
// Original: arm9/ov004 @ 0x021599B4; symbol: func_ov004_021599b4; size: 0x78.
extern "C" int Resource_DecrementActiveEntryAndInvokeHandler(void* object) {
    int index = GetTypeSevenRowMajorIndex(object, 0x5b);
    if (index < 0) return 0;
    if (func_ov004_021570a4(object, (unsigned)index & 0xff) == 0) return 0;
    unsigned char* state = *(unsigned char**)(data_ov004_021707d8 + 8);
    unsigned char count = state[0x11];
    if (count <= 1) return 0;
    state[0x11] = count - 1;
    InvokeEntryHandlerForStateKey(object, 0x25c, 1);
    func_ov004_02159384(object);
    return 0;
}
