#include <globaldefs.h>
ARM
extern "C" int func_ov000_02171698(void *entries);
// Original: arm9/ov000 @ 0x02171640; symbol: func_ov000_02171640; size: 0x34.
extern "C" void func_ov000_02171640(void *entries, int index, void *value) {
    if (index < 0 || index >= 0x42 || value == 0) return;
    *(void **)((char *)entries + index * 4 + 0x9c) = value;
    *(unsigned short *)((char *)entries + 0x82) = (unsigned short)func_ov000_02171698(entries);
}
