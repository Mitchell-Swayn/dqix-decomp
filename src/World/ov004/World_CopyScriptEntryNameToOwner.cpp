#include <globaldefs.h>
ARM
extern "C" void *data_ov004_0217101c;
extern "C" unsigned char *ReadWordFieldAtOffset1C(void);
extern "C" void ClearOwnerBuffersAndResetSignedByteSentinels(signed char *);
extern "C" unsigned int func_ov004_021666bc(void *, unsigned int *);
extern "C" unsigned int *WorldScriptArray_FindEntryByKey(void *, unsigned int);
extern "C" void CopyBoundedNameToIndexedSlot(void *, int, const char *);
// Original: arm9/ov004 @ 0x02167310; symbol: func_ov004_02167310; size: 0x60.
extern "C" int World_CopyScriptEntryNameToOwner(void *owner) {
    void *scriptArray = data_ov004_0217101c;
    unsigned char *object = ReadWordFieldAtOffset1C();
    ClearOwnerBuffersAndResetSignedByteSentinels((signed char *)object);
    unsigned int output;
    unsigned int key = func_ov004_021666bc(owner, &output);
    unsigned int *entry = WorldScriptArray_FindEntryByKey((unsigned char *)scriptArray + 0xc, key);
    if (entry) CopyBoundedNameToIndexedSlot(object, 0, (const char *)entry[1]);
    return 0;
}
