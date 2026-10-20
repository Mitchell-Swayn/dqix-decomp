#include <globaldefs.h>
ARM
extern "C" void *Menu_GetDisplayRecordRegistry(void *);
extern "C" void *MenuRecordList_LocateByKey(void **, unsigned short);
// Original: arm9/ov004 @ 0x021634B8; symbol: Grotto_SetRecordByte3AById; size: 0x24.
// Looks up a record in the state's list by the halfword key and writes the supplied byte at offset 0x3A when found.
extern "C" void TreasureMapMenu_SetEntryDecorationVariant(void *state, unsigned short value, unsigned char byte) {
    void **head = (void **)Menu_GetDisplayRecordRegistry(state);
    unsigned char *record = (unsigned char *)MenuRecordList_LocateByKey(head, value);
    if (record) record[0x3a] = byte;
}
