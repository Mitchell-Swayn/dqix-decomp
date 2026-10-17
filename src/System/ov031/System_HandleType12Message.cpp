#include <globaldefs.h>
ARM

extern "C" void System_CancelAndRestartStateNineAlarm(void);
extern "C" void _Z15UnblockContextsP18BlockedContextList(void *);
extern "C" unsigned char data_ov031_0224e540[];
extern "C" unsigned char data_ov031_0224e544[];

// Original: arm9/ov031 @ 0x0220F28C; symbol: func_ov031_0220f28c; size: 0x40.
extern "C" void System_HandleType12Message(const unsigned short *message) {
    if (message[0] != 0x12) {
        return;
    }
    *(unsigned int *)(data_ov031_0224e540 + 0x24) = message[1];
    if (message[1] == 0) {
        System_CancelAndRestartStateNineAlarm();
    }
    _Z15UnblockContextsP18BlockedContextList(data_ov031_0224e544);
}
