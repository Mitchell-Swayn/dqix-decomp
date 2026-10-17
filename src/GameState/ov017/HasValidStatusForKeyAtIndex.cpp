#include <globaldefs.h>
ARM
extern "C" void *ReadGlobalValueAt02108EA8();
extern "C" int Object_TestFourRecordStatusBytesNonnegative(char *, int);
struct E;
extern "C" E *FindKeyAmongFourRecords(E *, unsigned int);

// Original: arm9/ov017 @ 0x021C5BF8; symbol: func_ov017_021c5bf8; size: 0x64.
extern "C" int HasValidStatusForKeyAtIndex(int index, unsigned int key) {
    if (index >= 4) goto fail;
    char *records = (char *)ReadGlobalValueAt02108EA8();
    if (!Object_TestFourRecordStatusBytesNonnegative(records, (unsigned short)key)) goto fail;
    E *record = FindKeyAmongFourRecords((E *)records, (unsigned short)key);
    if (record != 0 && *((signed char *)record + index + 8) != -1) return 1;
fail:
    return 0;
}
