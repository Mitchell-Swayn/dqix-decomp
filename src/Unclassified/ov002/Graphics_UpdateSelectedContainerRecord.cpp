#include <globaldefs.h>
ARM
extern "C" void func_0205ac40(void *, void *);
// Original: arm9/ov002 @ 0x02154BCC; symbol: func_ov002_02154bcc; size: 0x64.
extern "C" void Graphics_UpdateSelectedContainerRecord(int x, int y, void *container, unsigned int index, unsigned char optionA, unsigned char optionB) {
    unsigned char *base = *(unsigned char **)((char *)container + 0x40);
    unsigned char *record = 0;
    if (base != 0) {
        unsigned int count = *(unsigned short *)((char *)container + 0x4e);
        if (index < count) record = base + index * 0x28;
    }
    if (record == 0) return;
    *(int *)(record + 0x14) = x << 12;
    *(int *)(record + 0x18) = y << 12;
    if (optionB != 0xff) record[0x25] = optionB;
    if (optionA != 0xff) record[0x22] = optionA;
    func_0205ac40(container, record);
}
