#include <globaldefs.h>
ARM
extern "C" int Http_SetNamedRequestParameter(void *, unsigned int, unsigned int, unsigned int);
// Original: arm9/ov031 @ 0x02240050; symbol: Network_RegisterOrUpdateKeyedRecordIfStateEmpty; size: 0x24.
// Returns zero if the state word is set; otherwise calls the keyed-record registration helper with selector 0x18.
extern "C" int Network_RegisterOrUpdateKeyedRecordIfStateEmpty(unsigned int *p, unsigned int a, unsigned int b) {
    if (*p != 0) return 0;
    return Http_SetNamedRequestParameter((unsigned char *)p + 0x34, a, b, 0x18);
}
