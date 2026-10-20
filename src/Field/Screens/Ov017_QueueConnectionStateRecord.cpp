#include <globaldefs.h>
ARM
extern "C" void *Network_GetConnectionManager(void);
extern "C" int Network_IsSessionActive(void *);
extern "C" int Network_GetLocalMemberId(char *);
extern "C" void *Network_GetCommandRecordPool(void);
extern "C" void Network_QueueOutgoingRecord(void *, const void *, short);
// Original: arm9/ov017 @ 0x021D1CB8; symbol: func_ov017_021d1cb8; size: 0x48.
extern "C" void Ov017_QueueConnectionStateRecord(void) {
    if (Network_IsSessionActive(Network_GetConnectionManager()) != 0) {
        if (Network_GetLocalMemberId((char *)Network_GetConnectionManager()) == 0) {
            void *object = Network_GetCommandRecordPool();
            unsigned char record[20];
            record[0] = 0xb4;
            Network_QueueOutgoingRecord(object, record, 0);
        }
    }
}
