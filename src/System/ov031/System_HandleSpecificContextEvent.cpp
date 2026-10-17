#include <globaldefs.h>
ARM

extern "C" void SetSharedStateAndManageStateNineAlarm(int);
extern "C" void func_ov031_0220db6c(void);
extern "C" unsigned char data_ov031_0224e53c[];

// Original: arm9/ov031 @ 0x0220DBC8; symbol: func_ov031_0220dbc8; size: 0x78.
extern "C" void System_HandleSpecificContextEvent(const unsigned short *message) {
    if (message[1] != 8 || message[2] != 0x16 || message[3] != 0x25) {
        return;
    }
    unsigned int state = *(unsigned int *)((char *)*(void **)data_ov031_0224e53c + 0x2260);
    switch (state) {
    case 8:
        SetSharedStateAndManageStateNineAlarm(12);
        break;
    case 9:
    case 12:
        func_ov031_0220db6c();
        break;
    case 10:
        SetSharedStateAndManageStateNineAlarm(12);
        break;
    default:
        break;
    }
}
