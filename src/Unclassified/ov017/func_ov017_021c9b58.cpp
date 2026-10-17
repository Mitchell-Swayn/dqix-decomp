#include <globaldefs.h>
ARM
extern "C" void func_ov017_021c9954(unsigned int, unsigned int, unsigned int, void *);
// Original: arm9/ov017 @ 0x021C9B58; symbol: func_ov017_021c9b58; size: 0x1C.
extern "C" void func_ov017_021c9b58(void *first, unsigned char *record) {
    func_ov017_021c9954(*(unsigned short *)(record + 6), 0, record[0xa], first);
}
