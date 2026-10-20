#include <globaldefs.h>
ARM
extern "C" void* Network_GetPartySynchronizationFlags();
extern "C" int Network_GetLocalMemberId(char* p);
extern "C" void Network_RequestPartySynchronization(unsigned char* p, int bit);
extern "C" void Network_MarkLocalPartySynchronizationReady(char* p);
extern "C" void Network_ClearPartySynchronizationAcknowledgement(unsigned char* p, int bit);
extern "C" void Record_UpdateModeWhenIndexedFieldMatches(int mode, unsigned char* record, int unused2, int unused3, char* indexedField);
// Original: arm9/ov017 @ 0x021CED84; symbol: func_ov017_021ced84; size: 0x70.
extern "C" void Record_UpdateModeWhenIndexedFieldMatches(int mode, unsigned char* record, int unused2, int unused3, char* indexedField) {
    unsigned char* entry = (unsigned char*)Network_GetPartySynchronizationFlags();
    int value = Network_GetLocalMemberId(indexedField);
    if (record[5] != value) return;
    if (record[4] == 0) {
        Network_RequestPartySynchronization(entry, mode & 0xff);
        return;
    }
    if (record[4] == 1) {
        Network_MarkLocalPartySynchronizationReady((char*)entry);
        return;
    }
    if (record[4] == 2) {
        Network_ClearPartySynchronizationAcknowledgement(entry, mode & 0xff);
    }
}
