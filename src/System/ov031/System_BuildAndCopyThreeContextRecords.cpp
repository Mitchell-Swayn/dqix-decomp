#include <globaldefs.h>
ARM

extern "C" void func_ov031_02208e54(void *, const void *, void *);
extern "C" void MI_CpuCopy8(const void *, void *, unsigned);
extern "C" unsigned char data_ov031_02249748[];
extern "C" unsigned char data_ov031_0224974c[];
extern "C" unsigned char data_ov031_02249750[];

// Original: arm9/ov031 @ 0x02208EF0; symbol: func_ov031_02208ef0; size: 0x60.
extern "C" void System_BuildAndCopyThreeContextRecords(void *destination) {
    unsigned char records[0x30];
    func_ov031_02208e54(records, data_ov031_02249748, destination);
    func_ov031_02208e54(records + 0x10, data_ov031_0224974c, destination);
    func_ov031_02208e54(records + 0x20, data_ov031_02249750, destination);
    MI_CpuCopy8(records, destination, 0x30);
}
