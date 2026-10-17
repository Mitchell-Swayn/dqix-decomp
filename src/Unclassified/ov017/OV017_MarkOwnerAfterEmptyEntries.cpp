#include <globaldefs.h>
extern "C" void func_ov017_02190264(void *, int);
extern "C" int ReadIndexedSignedField1038(char *);
// Original: arm9/ov017 @ 0x021CC6C4; symbol: func_ov017_021cc6c4; size: 0x6C.
extern "C" void OV017_MarkOwnerAfterEmptyEntries(void *unused, unsigned char *entries, void *unused2, void *owner, char *record) {
    int hasEmpty = 0;
    for (int i = 0; i < entries[4]; ++i) {
        unsigned char *entry = entries + i;
        unsigned char item = entry[5];
        func_ov017_02190264(owner, item);
        if (item == 0) hasEmpty = 1;
    }
    if (hasEmpty && ReadIndexedSignedField1038(record)) *((unsigned char *)owner + 0x42e1) = 1;
}
