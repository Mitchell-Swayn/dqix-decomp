#include <globaldefs.h>
ARM
extern "C" void* RecordArray_ReadGlobalEntryPointer();
extern "C" int ReadIndexedSignedField1038(char* p);
extern "C" void Record_SetBitWhenModeEnabled(unsigned char* p, int bit);
extern "C" void Record_SetActiveByteWhenModeEnabled(char* p);
extern "C" void ClearContextEnabledByte1Bit(unsigned char* p, int bit);
extern "C" void Record_UpdateModeWhenIndexedFieldMatches(int mode, unsigned char* record, int unused2, int unused3, char* indexedField);
// Original: arm9/ov017 @ 0x021CED84; symbol: func_ov017_021ced84; size: 0x70.
extern "C" void Record_UpdateModeWhenIndexedFieldMatches(int mode, unsigned char* record, int unused2, int unused3, char* indexedField) {
    unsigned char* entry = (unsigned char*)RecordArray_ReadGlobalEntryPointer();
    int value = ReadIndexedSignedField1038(indexedField);
    if (record[5] != value) return;
    if (record[4] == 0) {
        Record_SetBitWhenModeEnabled(entry, mode & 0xff);
        return;
    }
    if (record[4] == 1) {
        Record_SetActiveByteWhenModeEnabled((char*)entry);
        return;
    }
    if (record[4] == 2) {
        ClearContextEnabledByte1Bit(entry, mode & 0xff);
    }
}
