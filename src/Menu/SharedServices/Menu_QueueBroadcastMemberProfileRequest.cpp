#include <globaldefs.h>
ARM
extern "C" void Field_QueueMemberProfileRequest(int, int, int);
// Original: arm9/ov004 @ 0x0216A7E0; symbol: QueueTag19Record; size: 0x1C.
// Calls the record helper with (-1, 1, 0); the helper encodes tag 0x19 and queues/applies the resulting record.
extern "C" int Menu_QueueBroadcastMemberProfileRequest(void) {
    Field_QueueMemberProfileRequest(-1, 1, 0);
    return 0;
}
