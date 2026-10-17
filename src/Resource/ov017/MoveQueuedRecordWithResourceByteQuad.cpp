#include <globaldefs.h>
ARM
extern "C" void *ReadGlobalAt02100044(void);
extern "C" void *GameResources_GetInstance(void);
extern "C" void MoveQueuedRecordAndApplySourceValue(void *, const void *, short);
// Original: arm9/ov017 @ 0x021CE29C; symbol: func_ov017_021ce29c; size: 0x60.
extern "C" void MoveQueuedRecordWithResourceByteQuad(void) {
    void *object = ReadGlobalAt02100044();
    unsigned char *resources = *(unsigned char **)((unsigned char *)GameResources_GetInstance() + 0x3B30);
    unsigned char source[0x14];
    source[0] = 0x2E;
    unsigned char *payload = source + 4;
    for (int i = 0; i < 4; i++) payload[i] = (resources + i)[0x1B];
    MoveQueuedRecordAndApplySourceValue(object, source, 0);
}
