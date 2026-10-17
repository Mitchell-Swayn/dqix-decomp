#include <globaldefs.h>
ARM
extern "C" void func_ov004_02166bd8(void);
extern "C" unsigned int func_ov004_021666bc(void *, unsigned char *);
extern "C" void *func_ov004_02165e70(void *, unsigned int);
extern "C" void BackgroundLoader_UpdateIdentifierAndCancelPreviousTask(char *, int, unsigned char);
// Original: arm9/ov004 @ 0x021675FC; symbol: func_ov004_021675fc; size: 0x4C.
extern "C" int Filesystem_UpdateOwnerTaskFromStackByte(void *owner) {
    unsigned char value;
    func_ov004_02166bd8();
    unsigned int identifier = func_ov004_021666bc(owner, &value);
    unsigned char savedValue = value;
    void *task = func_ov004_02165e70(owner, 7);
    if (task != 0) BackgroundLoader_UpdateIdentifierAndCancelPreviousTask((char *)task + 0x34, identifier, savedValue);
    return 0;
}
