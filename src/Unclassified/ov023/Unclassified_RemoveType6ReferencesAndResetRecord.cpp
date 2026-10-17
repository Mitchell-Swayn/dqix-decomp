#include <globaldefs.h>
ARM

extern "C" unsigned int ReadWordAtOffset18(const void *p);
extern "C" unsigned int OV023_ReadHalfwordField04(void *);
extern "C" void ResetRecordAndIndexedEntries(unsigned char *p);

// Original: arm9/ov023 @ 0x021F7984; symbol: func_ov023_021f7984; size: 0x60.
extern "C" void Unclassified_RemoveType6ReferencesAndResetRecord(void *self, void **headRef) {
    char *node = *(char **)headRef;
    while (node != 0) {
        char *next = (char *)ReadWordAtOffset18(node);
        if (OV023_ReadHalfwordField04(node) == 6) {
            char *fields = node + 0x20;
            if (fields != 0 && (char *)self + 0x28 == *(char **)(fields + 4)) {
                *(char **)(fields + 4) = 0;
            }
        }
        node = next;
    }
    ResetRecordAndIndexedEntries((unsigned char *)self + 0x28);
}
