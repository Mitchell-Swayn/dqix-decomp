#include <globaldefs.h>
ARM
extern "C" void func_ov017_021cbdcc(void);
extern "C" void* ReadGlobalAt02100044(void);
extern "C" void MoveQueuedRecordAndApplySourceValue(void*, const void*, short);
// Original: arm9/ov017 @ 0x021CBC48; symbol: func_ov017_021cbc48; size: 0x78.
extern "C" void CopyRecordIntoTaggedQueueEntry(const unsigned char* record) {
    unsigned char copy[0x14];
    func_ov017_021cbdcc();
    void* destination = ReadGlobalAt02100044();
    copy[0] = 0x64;
    *(unsigned short*)(copy + 4) = *(const unsigned short*)(record + 0);
    *(unsigned short*)(copy + 6) = *(const unsigned short*)(record + 2);
    *(unsigned*)(copy + 8) = *(const unsigned*)(record + 4);
    copy[0xc] = record[8];
    copy[0xd] = (unsigned char)*(const signed char*)(record + 9);
    copy[0xe] = record[10];
    copy[0xf] = record[11];
    copy[0x10] = record[12];
    *(short*)(copy + 0x12) = *(const short*)(record + 0xe);
    MoveQueuedRecordAndApplySourceValue(destination, copy, 0);
}
