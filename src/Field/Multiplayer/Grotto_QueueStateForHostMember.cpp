#include <globaldefs.h>
ARM
extern "C" int Network_GetLocalMemberId(char *);
extern "C" void Network_QueueGrottoStateRecord(char, unsigned char);
// Original: arm9/ov017 @ 0x021CF704; symbol: Network_QueueGrottoStateRecordWhenField1038Zero; size: 0x2C.
// When the indexed signed field at +0x1038 is zero, queues the sign-extended low byte of the first argument with a zero flag.
extern "C" void Grotto_QueueStateForHostMember(unsigned int type, unsigned int, unsigned int, unsigned int, char *record) {
    if (Network_GetLocalMemberId(record) == 0)
        Network_QueueGrottoStateRecord((char)type, 0);
}
