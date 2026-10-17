#include <globaldefs.h>
ARM

extern "C" void *ReadGlobalAt02100044(void);
extern "C" void *Object_GetGlobalConnectionState(void);
extern "C" int ReadIndexedSignedField1038(char *);
extern "C" void MoveQueuedRecordAndApplySourceValue(void *, const void *, short);

// Original: arm9/ov017 @ 0x021D079C; symbol: func_ov017_021d079c; size: 0x6C.
extern "C" void QueueIndexedConnectionRecord(unsigned char type, unsigned char index, short value) {
    unsigned char record[20];
    void *queue = ReadGlobalAt02100044();
    char *connection = (char *)Object_GetGlobalConnectionState();
    record[0] = 0x99;
    unsigned char *payload = record + 4;
    payload[0] = type;
    payload[2] = index;
    payload[1] = (unsigned char)ReadIndexedSignedField1038(connection);
    if (payload[2] == 0) {
        *(short *)(payload + 4) = value;
    } else if (payload[2] == 1) {
        *(short *)(payload + 4) = value;
    }
    MoveQueuedRecordAndApplySourceValue(queue, record, 0);
}
