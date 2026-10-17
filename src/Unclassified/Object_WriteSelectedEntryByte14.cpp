#include <globaldefs.h>

extern "C" char* FindRecordPointerByKey(void*, int);

// Original: arm9/main @ 0x0205A42C; symbol: func_0205a42c; size: 0x18.
extern "C" ARM void Object_WriteSelectedEntryByte14(void* owner, int index, unsigned char value) {
    char* record = FindRecordPointerByKey(owner, index);
    if (record)
        record[0x14] = value;
}
