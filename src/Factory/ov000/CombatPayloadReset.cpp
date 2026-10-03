#include <globaldefs.h>

struct CombatPayloadPrefix {
    unsigned char flag0;
    unsigned char flag1;
    unsigned short value0;
    unsigned short value1;
};

extern "C" ARM void func_ov000_021820fc(CombatPayloadPrefix* payload) {
    payload->flag0 = 0;
    payload->flag1 = 0;
    payload->value0 = 0;
    payload->value1 = 0;
}
