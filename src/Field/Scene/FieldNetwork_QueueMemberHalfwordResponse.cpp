#include <globaldefs.h>
ARM

extern "C" void *Network_GetCommandRecordPool(void);
extern "C" void *Network_GetConnectionManager(void);
extern "C" int Network_GetLocalMemberId(char *);
extern "C" void Network_QueueOutgoingRecord(void *, const void *, short);

// Original: arm9/ov017 @ 0x021D079C; symbol: func_ov017_021d079c; size: 0x6C.
extern "C" void FieldNetwork_QueueMemberHalfwordResponse(unsigned char type, unsigned char index, short value) {
    unsigned char record[20];
    void *queue = Network_GetCommandRecordPool();
    char *connection = (char *)Network_GetConnectionManager();
    record[0] = 0x99;
    unsigned char *payload = record + 4;
    payload[0] = type;
    payload[2] = index;
    payload[1] = (unsigned char)Network_GetLocalMemberId(connection);
    if (payload[2] == 0) {
        *(short *)(payload + 4) = value;
    } else if (payload[2] == 1) {
        *(short *)(payload + 4) = value;
    }
    Network_QueueOutgoingRecord(queue, record, 0);
}
